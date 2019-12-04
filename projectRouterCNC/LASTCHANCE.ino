#include "Arduino.h"

#include <LiquidCrystal.h>

#include "projLibraries/main.h"
#include "projLibraries/driver.h"
#include "projLibraries/buttons.h"
#include "projLibraries/lcd.h"
#include "projLibraries/serial.h"

void heartbeat()
{
	static unsigned long long int millis_heart_beating = 0;

	if(driverState == 1)
	{
		if(millis()-millis_heart_beating >= DELAY_HEART_BEATING)
		{
			millis_heart_beating = millis();
			digitalWrite(PIN_HEART_BEATING, !digitalRead(PIN_HEART_BEATING));
		}
	}
	else if(driverState == 0) digitalWrite(PIN_HEART_BEATING, HIGH);
}

void setup()
{
	pinMode(PIN_HEART_BEATING, OUTPUT);

	init_serial();

	botoes();
	debouncer();
	iniciaDriver();
	iniciaSpindle();
	iniciaMotor();
	iniciaLCD();
}

// The loop function is called in an endless loop
void loop()
{
	switchTela();
}
