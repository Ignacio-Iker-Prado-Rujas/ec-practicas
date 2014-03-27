/*********************************************************************************************
* Fichero:		timer.c
* Autor:		
* Descrip:		funciones de control del timer0 del s3c44b0x
* Version:	
*********************************************************************************************/

/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"

 


//*--- declaracion de funciones ---*/
void timer_ISR(void) __attribute__ ((interrupt ("IRQ")));
void timer_init(void);

/*--- codigo de las funciones ---*/
void timer_ISR(void)
{  /*  TAREA 2a */
        /*Actualizar leds con cada int. del timer */
		if (resetsymbol == 1){
				.........	 /* actualizamos el contador a 9 */
				resetsymbol=0;
				pausa = 1;
		} else if (pausa == 0) {
				.........	 /* actualiza el contador segun proceda */
		}
		D8Led_symbol(symbol); 		     /* muestra el contador en el display */
		leds_switch(); 
	/* borrar bit en I_ISPC */
    .....
	/*fin Tarea 2a*/
}

void timer_init(void)
{
/*TAREA 2b*/
	/* Configuraion controlador de interrupciones */
	....  // Configura las linas como de tipo IRQ
	....  // Habilita int. vectorizadas y la linea IRQ (FIQ no)
	....  // habilita Timer0 y el bit global
		
	/* Establece la rutina de servicio para TIMER0 */
	pISR_TIMER0=(unsigned)timer_ISR;

/*fin TAREA 2b*/	

	/* Configura el Timer0 */
    rTCFG0 = 63;
    rTCFG1 = 0x0;
    rTCNTB0 = 65535;
    rTCMPB0 = 12800;
    /* establecer update=manual + inverter=on */
	rTCON = 0x2;
	/* inicial timer con auto-reload */
    rTCON  = 0x09;

}

