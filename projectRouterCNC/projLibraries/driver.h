#ifndef PROJLIBRARIES_DRIVER_H_
#define PROJLIBRARIES_DRIVER_H_

#define MAX 		360
#define MED 		180
#define MIN  		90
#define SPINDLE1 	44
#define SPINDLE2	52

/* VARIAVEIS */
extern int driverState;
extern bool errorFlag;
extern int x;
extern int y;

/* FUNCOES DRIVER */
void iniciaDriver();
void spindleManual(int spindleRPM);
void setRpm(int rpm);
void stepX(int steps);
void stepY(int steps);
void stepZ(int steps);
void iniciaMotor();
void iniciaSpindle();
void origem();
void interpolation(int x0, int y0, int xf, int yf);
void spindleSerial(int serials);
void inverteSpindle(int serials);

#endif /* PROJLIBRARIES_DRIVER_H_ */
