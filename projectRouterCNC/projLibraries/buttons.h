#ifndef PROJLIBRARIES_BUTTONS_H_
#define PROJLIBRARIES_BUTTONS_H_

/* PINOS */
#define	p		37
#define mais	36
#define menos 	35
#define s		34

/* FUNCOES */
void botoes();
void debouncer();
void update();
bool p_button();
bool set_button();
bool up_button();
bool down_button();

#endif /* PROJLIBRARIES_BUTTONS_H_ */
