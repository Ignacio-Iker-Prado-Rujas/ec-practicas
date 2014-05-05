/*********************************************************************************************
* Fichero:		timer.c
* Autor:		
* Descrip:		funciones de control del timer0 del s3c44b0x
* Version:	
*********************************************************************************************/

/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"
#include "buffer.h"
#include "8seg.h"

int posicion = 0;
int modoT = 0;
int cuentaClave = 0;
int cuentaIntento = 0;
int cuentaAcierto = 0;
// El 0 es modo mostrar clave, el 1 mostrar intento, el 2 mostrar acierto
//*--- declaracion de funciones ---*/
void timer_ISR(void) __attribute__ ((interrupt ("IRQ")));


/*--- codigo de las funciones ---*/
void timer_ISR(void)
{  /*  TAREA 2a */
        /*Actualizar leds con cada int. del timer */
	if (modoT == 0){
		cuentaClave++;
		D8Led_symbol(leerClave(posicion));
		if (posicion == 3)
			posicion = 0;
		else
			posicion = posicion + 1;
	}else if(modoT == 1){
		cuentaIntento++;
		D8Led_symbol(leerIntento(posicion));
		if (posicion == 3)
			posicion = 0;
		else
			posicion = posicion + 1;
	}else{
		cuentaAcierto++;
	}
	/* borrar bit en I_ISPC */
	rI_ISPC |= BIT_TIMER1;
	/*fin Tarea 2a*/

}

void modoTimer(int i){
	modoT = i;
}
