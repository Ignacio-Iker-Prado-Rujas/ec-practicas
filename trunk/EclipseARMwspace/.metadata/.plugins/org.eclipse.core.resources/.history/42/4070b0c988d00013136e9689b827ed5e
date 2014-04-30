    /*********************************************************************************************
* Fichero:	main.c
* Autor:	
* Descrip:	punto de entrada de C
* Version:	<P4-ARM.8seg-button>
*********************************************************************************************/

/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"

/*--- variables globales ---*/
int symbol = 15;
extern int update;
extern int pausa;
extern int resetsymbol;
extern int switch_leds;

/*--- funciones externas ---*/
extern void EINT4567_init(void);
extern void D8Led_symbol(int value);
extern void timer_init();
extern void leds_off();
extern void led1_on();
extern void leds_switch();
/*--- codigo de las funciones ---*/
int main(void)
{	
    sys_init();     		/* Inicializacion de la placa, interrupciones, puertos y UART */
    EINT4567_init(); 	    /* Inicializacion de EINT6/7 y del puerto G */
	TIMER_init();	   // Inicializacion del temporizador

	leds_off();
	led1_on();

	D8Led_symbol(symbol);  	/* muestra el simbolo inicial en el display */
		
    while(1) {


	}
    return 0;
}
