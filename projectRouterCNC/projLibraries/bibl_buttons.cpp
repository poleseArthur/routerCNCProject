#include "Arduino.h"
#include "buttons.h"
#include <Bounce2.h>

void botoes()
{
	pinMode(p, INPUT_PULLUP);
	pinMode(mais, INPUT_PULLUP);
	pinMode(menos, INPUT_PULLUP);
	pinMode(s, INPUT_PULLUP);
}

Bounce P = Bounce();
Bounce MAIS = Bounce();
Bounce MENOS = Bounce();
Bounce S = Bounce();

void debouncer()
{
	P.attach(p);
	MAIS.attach(mais);
	MENOS.attach(menos);
	S.attach(s);
	P.interval(15);
	MAIS.interval(15);
	MENOS.interval(15);
	S.interval(15);
}

void update()
{
	P.update();
	MAIS.update();
	MENOS.update();
	S.update();
}

bool p_button()
{
	if(P.fell())
		return true;
	else
		return false;
}

bool up_button()
{
	if(MAIS.fell())
		return true;
	else
		return false;
}

bool down_button()
{
	if(MENOS.fell())
		return true;
	else
		return false;
}

bool set_button()
{
	if(S.fell())
		return true;
	else
		return false;
}


