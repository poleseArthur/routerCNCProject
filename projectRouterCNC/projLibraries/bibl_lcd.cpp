#include "Arduino.h"
#include "lcd.h"
#include "main.h"
#include "buttons.h"
#include "driver.h"
#include "serial.h"

#include <LiquidCrystal.h>

LiquidCrystal lcd(22, 23, 24, 25, 26, 27); // @suppress("Abstract class cannot be instantiated")


/* VARIAVEIS */
int tela;
int manualModeX;
int manualModeY;
int manualModeZ;
int manualFlag;
int flagErro = 0, flagCursor;
int posX, posY, posZ, spindleRPM = 0;


void iniciaLCD()
{
	lcd.begin(16,2);
}

void update_screen()
{
	lcd.clear();

	lcd.setCursor(0,0);
	lcd.print("S:");
	lcd.setCursor(2,0);
	lcd.print(spindleRPM);

	lcd.setCursor(0,1);
	lcd.print("X:");
	lcd.setCursor(2,1);
	lcd.print(posX);

	lcd.setCursor(9,0);
	lcd.print("Y:");
	lcd.setCursor(11,0);
	lcd.print(posY);

	lcd.setCursor(9,1);
	lcd.print("Z:");
	lcd.setCursor(11,1);
	lcd.print(posZ);
}

void error_screen()
{
	heartbeat();

	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Error: Please");
	lcd.setCursor(0,1);
	lcd.print("Close the cover!");
	delay(3000);
	lcd.clear();

}

void overtravel()
{
	lcd.clear();
	heartbeat();

	if(manualModeX == 1)
	{
		lcd.setCursor(3,0);
		lcd.print("Over Travel");
		lcd.setCursor(5,1);
		lcd.print("Axis:");
		lcd.setCursor(11,1);
		if(posX > 199)
		{
			lcd.print("X+");
		}
		else if(posX < 1)
		{
			lcd.print("X-");
		}

		delay(1000);
		update_screen();
	}

	if(manualModeY == 1)
	{
		lcd.setCursor(3,0);
		lcd.print("Over Travel");
		lcd.setCursor(5,1);
		lcd.print("Axis:");
		lcd.setCursor(11,1);
		if(posY > 299)
		{
			lcd.print("Y+");
		}
		else if(posY < 1)
		{
			lcd.print("Y-");
		}

		delay(1000);
		update_screen();
	}

	if(manualModeZ == 1)
	{
		lcd.setCursor(3,0);
		lcd.print("Over Travel");
		lcd.setCursor(5,1);
		lcd.print("Axis:");
		lcd.setCursor(11,1);
		if(posZ > 149)
		{
			lcd.print("Z+");
		}
		else if(posZ < 1)
		{
			lcd.print("Z-");
		}

		delay(1000);
		update_screen();
	}
}

void menu_inicial()
{
	lcd.clear();
	update();

	while(tela == MAIN)
	{
		update();
		heartbeat();
		errorFlag = false;

		lcd.setCursor(3,0);
		lcd.print("CNC Router");
		lcd.setCursor(0,1);
		lcd.print("Home Ret? <S>");

		if(set_button())
		{
			if(digitalRead(TAMPA) == LOW)
			{
				error_screen();
			}

			else
			{
				tela = HOME;
			}

		}
	}
}

void menu_homing()
{
	lcd.clear();
	update();

	while(tela == HOME)
	{
		heartbeat();

		lcd.setCursor(0,0);
		lcd.print("Machine home");
		lcd.setCursor(0,1);
		lcd.print("in progress..");


		if(digitalRead(TAMPA) == LOW)
		{
			error_screen();
			tela = MAIN;
		}

		origem();
	}
}

void menu_referencia()
{
	lcd.clear();
	update();
	/*commands();*/

	while(tela == REF)
	{
		heartbeat();
		update();

		commands(); //aceita serial enquanto estiver fora do manual

		lcd.setCursor(0,0);
		lcd.print("S:");
		lcd.setCursor(2,0);
		lcd.print(spindleRPM);

		lcd.setCursor(0,1);
		lcd.print("X:");
		lcd.setCursor(2,1);
		lcd.print(posX);

		lcd.setCursor(9,0);
		lcd.print("Y:");
		lcd.setCursor(11,0);
		lcd.print(posY);

		lcd.setCursor(9,1);
		lcd.print("Z:");
		lcd.setCursor(11,1);
		lcd.print(posZ);

		if(manualFlag == 0) lcd.noCursor();

		if(set_button())
		{
			if(spindleRPM == 0)
			{
				spindleRPM = 500;
				spindleManual(spindleRPM);
			}
			else
			{
				spindleRPM = 0;
				spindleManual(spindleRPM);
			}
		}

		if(p_button())
		{
			manualFlag = 1;
			manualModeX = 1;
			flagCursor = 0;
		}



		while(manualFlag == 1)
		{
			update();
			heartbeat();

			while(manualModeX == 1)
			{
				update();
				heartbeat();

				if(flagCursor == 0)
				{
					lcd.setCursor(0,1);
					lcd.cursor();
				}

				if (up_button())
				{
					if(posX <= 200)
					{
						posX += 1;
						stepX(10);
					}
					else if(posX > 200)
					{
						posX = 200;
						overtravel();
					}

					update_screen();
					lcd.setCursor(2,1);
					lcd.print(posX);

				}

				if (down_button())
				{
					if(posX > 0)
					{
						posX -= 1;
						stepX(-10);
					}

					else if(posX <= 0)
					{
						overtravel();
						posX = 0;
					}

					update_screen();
					lcd.setCursor(2,1);
					lcd.print(posX);
				}


				if(p_button())
				{
					manualModeY = 1;
					manualModeX = 0;
					flagCursor++;
					break;
				}
			}

			while(manualModeY == 1)
			{
				update();
				heartbeat();

				if(flagCursor == 1)
				{
					lcd.setCursor(9,0);
					lcd.cursor();
				}


				if (up_button())
				{
					if(posY <= 300)
					{
						posY += 1;
						stepY(10);
					}
					else if(posY > 300)
					{
						posX = 300;
						overtravel();
					}

					update_screen();
					lcd.setCursor(11,0);
					lcd.print(posY);
				}

				if (down_button())
				{
					if(posY > 0)
					{
						posY -= 1;
						stepY(-10);
					}
					else if(posY <= 0)
					{
						posY = 0;
						overtravel();
					}

					update_screen();
					lcd.setCursor(11,0);
					lcd.print(posY);
				}

				if(p_button())
				{
					manualModeZ = 1;
					manualModeY = 0;
					flagCursor++;
					break;
				}
			}

			while(manualModeZ == 1)
			{
				update();
				heartbeat();

				if(flagCursor == 2)
				{
					lcd.setCursor(9,1);
					lcd.cursor();
				}

				if (up_button())
				{
					if(posZ <= 150)
					{
						posZ += 1;
						stepZ(10);
					}
					else if(posZ > 150)
					{
						posZ = 150;
						overtravel();
					}

					update_screen();
					lcd.setCursor(11,1);
					lcd.print(posZ);
				}

				if (down_button())
				{
					if(posZ > 0)
					{
						posZ -= 1;
						stepZ(-10);
					}
					else if(posZ <= 0)
					{
						posZ = 0;
						overtravel();
					}

					update_screen();
					lcd.setCursor(11,1);
					lcd.print(posZ);
				}

				if(p_button())
				{
					manualModeZ = 0;
					manualFlag = 0;
					flagCursor = 0;
				}
			}
		}
	}
}

void switchTela()
{
switch (tela)
{
	case MAIN:
		menu_inicial();
		break;

	case HOME:
		menu_homing();
		break;

	case REF:
		menu_referencia();
		break;
}

}

