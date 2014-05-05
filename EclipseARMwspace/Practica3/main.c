    /*********************************************************************************************
* Fichero:	main.c
* Autor:	
* Descrip:	punto de entrada de C
* Version:	<P4-ARM.8seg-button>
*********************************************************************************************/

/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "keyboard.h"
#include "buffer.h"
#include "timer.h"

/*--- variables globales ---*/
int symbol = 12;

extern int key;
extern int cuentaClave;
extern int cuentaIntento;
extern int cuentaAcierto;
extern int posicion;
/*--- funciones externas ---*/
extern void init_keyboard(void);
extern void D8Led_symbol(int value);
extern void TIMER_init(void);
/*--- codigo de las funciones ---*/
void guardaClave(){
	D8Led_symbol(symbol);  	/* muestra el simbolo inicial en el display */
	rINTMSK |= BIT_TIMER0; // Enmascara el timer
	modoClave(1); //Activa la lectura de clave
	while (key != 15){

	}
}

void muestraClave(){
	rINTMSK &= ~BIT_TIMER0; //Habilita el timer, enmascara el keyboard
	rINTMSK |= BIT_EINT1;
	modoTimer(0); //Modo muestra de clave
	while(cuentaClave <= 20){

	}
}
void leeIntento(){
	resetIntento();
	modoClave(0); //Activa la lectura de intento
	D8Led_symbol(15);
	rINTMSK |= BIT_TIMER0; // Enmascara el timer
	rINTMSK &= ~BIT_EINT1; //Habilita el keyboard
	key = -1;
	while (key != 15){

	}
}
void muestraIntento(){
	rINTMSK &= ~BIT_TIMER0; //Habilita el timer, enmascara el keyboard
	rINTMSK |= BIT_EINT1;
	modoTimer(1); //Modo muestra de intento
	cuentaIntento = 0;
	posicion = 0;
	while(cuentaIntento <= 20){

	}
}
void compruebaAcierto(){
	rINTMSK &= ~BIT_TIMER0; //Habilita el timer, enmascara el keyboard
	rINTMSK |= BIT_EINT1;
	modoTimer(2); //Modo muestra de clave
	if (comparar() == 1)
		D8Led_symbol(10);
	else
		D8Led_symbol(14);
	cuentaAcierto = 0;
	while(cuentaAcierto <= 10){

	}
}
int main(void)
{	

    sys_init();     		/* Inicializacion de la placa, interrupciones, puertos y UART */
    init_keyboard(); 	    /* Inicializacion de EINT6/7 y del puerto G */
	TIMER_init();	   		// Inicializacion del temporizador

	guardaClave();
	muestraClave();

	while(1){
		leeIntento();
		muestraIntento();
		compruebaAcierto();
	}
    return 0;
}
