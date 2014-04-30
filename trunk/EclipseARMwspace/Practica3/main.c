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
int symbol = 11;

/*--- funciones externas ---*/
extern void init_keyboard(void);
extern void D8Led_symbol(int value);
extern void TIMER_init(void);
/*--- codigo de las funciones ---*/
int main(void)
{	

    sys_init();     		/* Inicializacion de la placa, interrupciones, puertos y UART */
    init_keyboard(); 	    /* Inicializacion de EINT6/7 y del puerto G */
	TIMER_init();	   // Inicializacion del temporizador

	D8Led_symbol(symbol);  	/* muestra el simbolo inicial en el display */
		
    while(1) {


	}
    return 0;
}
