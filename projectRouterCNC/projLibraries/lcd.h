#ifndef PROJLIBRARIES_LCD_H_
#define PROJLIBRARIES_LCD_H_

/* TELAS */
#define MAIN	    	 0
#define HOME			 1
#define REF    	 		 2

/* VARIAVEIS */
extern int manualModeX;
extern int manualModeY;
extern int manualModeZ;
extern int manualFlag;
extern int tela;
extern int posX;
extern int posY;
extern int posZ;
extern int spindleRPM;

/* FUNCOES LCD */
void switchTela();
void iniciaLCD();
void error_screen();
void overtravel();
void update_screen();

#endif /* PROJLIBRARIES_LCD_H_ */
