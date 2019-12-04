#include <Arduino.h>
#include <Stepper.h>
#include "buttons.h"
#include "driver.h"
#include "main.h"
#include "lcd.h"


/* VARIÁVEIS */
int driverState;
const int steps = 10;
Stepper eixoX(steps, 13, 12, 11, 10);
Stepper eixoY(steps, 9, 8, 7, 6);
Stepper eixoZ(steps, 5, 4, 3, 2);
bool flagX, flagY, flagZ = false;
bool errorFlag;
int x  = 0, y = 0;

void iniciaMotor()
{
	eixoX.setSpeed(MIN);
	eixoY.setSpeed(MIN);
	eixoZ.setSpeed(MIN);
}

void iniciaSpindle()
{
	pinMode(SPINDLE1, OUTPUT);
	pinMode(SPINDLE2, OUTPUT);
	analogWrite(SPINDLE1, 0);
	analogWrite(SPINDLE2, 0);
}

void iniciaDriver()
{
	pinMode(TAMPA, INPUT);
	driverState = 1;
}

void setRpm(int rpm){
	
	switch (rpm)
  {
    case MAX:
		eixoX.setSpeed(MAX);
		eixoY.setSpeed(MAX);
		eixoZ.setSpeed(MAX);
		break;
    case MED:
		eixoX.setSpeed(MED);
		eixoY.setSpeed(MED);
		eixoZ.setSpeed(MED);
		break;
    case MIN:
		eixoX.setSpeed(MIN);
		eixoY.setSpeed(MIN);
		eixoZ.setSpeed(MIN);
		break;
  }
}

void spindleSerial(int serials)
{
	if(serials != 0)
		serials = map(serials, 200, 2000, 0, 255);

	analogWrite(SPINDLE1, serials);
}

void inverteSpindle(int serials)
{
	if(analogRead(SPINDLE1) > 0)
	{
		analogWrite(SPINDLE1, 0);

		serials = map(serials, 200, 2000, 0, 255);
		analogWrite(SPINDLE2, serials);
	}

	else if(analogRead(SPINDLE2) > 0)
	{
		analogWrite(SPINDLE2, 0);

		serials = map(serials, 200, 2000, 0, 255);
		analogWrite(SPINDLE1, serials);
	}
}

void spindleManual(int spindleRPM)
{
	if(spindleRPM != 0)
		spindleRPM = map(spindleRPM, 0, 500, 0, 255);

	analogWrite(SPINDLE1, spindleRPM);
}


void stepX(int steps){
	eixoX.step(steps);
}


void stepY(int steps){
	eixoY.step(steps);
}


void stepZ(int steps){
	eixoZ.step(steps);
}



void origem()
{
	while (!(flagX == true && flagY == true && flagZ == true))
	{
		if (digitalRead(HOMEX) == LOW)
		  eixoX.step(-steps);
		else
		  flagX = true;
		if (digitalRead(HOMEY) == LOW)
		  eixoY.step(-steps);
		else
		  flagY = true;
		if (digitalRead(HOMEZ) == LOW)
		  eixoZ.step(-steps);
		else
		  flagZ = true;

		if(digitalRead(TAMPA) == LOW)
		{
			error_screen();
			errorFlag = true;
			break;
		}
	}

	if(errorFlag == true)
	{
		tela = MAIN;
	}
	else
	{
		tela = REF;
	}

}

void interpolation(int x0, int y0, int xf, int yf)
{
	int positX = 0, positY = 0, i = 0, maior = 0;

	x = x0;
	y = y0;

	if(xf > yf)
	{
		Serial.println("X maior que Y ");
		positX = (xf - x0)/(yf - y0);
		positY = (xf - x0)%(yf - y0);
		if(positY == 0) {
			stepY(10*(yf - y0));
			y += (yf - y0);

		}
		maior = 1;
	}
	else if(yf > xf)
	{
		positY = (yf - y0)/(xf - x0);
		positX = (yf - y0)%(xf - x0);
		if(positX == 0) {
			stepX(10*(xf - x0));
			x += (xf - x0);

		}
		maior = 2;
	}

	while((y <= yf) && (x <= xf))
	{

		if(x <= xf){
			for(i=0; i<positX; i++){
				stepX(10);
				x+=1;
				Serial.print("X: ");
				Serial.println(x);
			}
		}

		if(y <= yf){
			for(i=0; i<positY; i++){
				stepY(10);
				y+=1;
				Serial.print("Y: ");
				Serial.println(y);
			}
		}
	}

	if(maior == 1)
	{
		stepX(10*positY);
		x += positY;
	}
	else if(maior == 2)
	{
		stepY(10*positX);
		y += positX;
	}

}
