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
#include "uart.h"

/*--- variables globales ---*/
int symbol = 12;
char inte;
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
	modoTimer(3);
	D8Led_symbol(symbol);  	/* muestra el simbolo inicial en el display */
	rINTMSK &= ~BIT_TIMER1; // Enmascara el timer
	while (key != 15){

	}
}

void muestraClave(){
	rINTMSK &= ~BIT_TIMER1; //Habilita el timer, enmascara el keyboard
	rINTMSK |= BIT_EINT1;
	modoTimer(0); //Modo muestra de clave
	while(cuentaClave <= 12){

	}
}
void leeIntento(){
	resetIntento();
	D8Led_symbol(15);
	modoTimer(3);
	rINTMSK &= ~BIT_TIMER1; // Enmascara el timer
	rINTMSK |= BIT_EINT1; //Inhabilita el keyboard
	Uart_Printf("Introduzca clave\n");
	inte = Uart_Getch();
	while (inte != '\r'){
		insertarIntento(inte-'0');
		inte = Uart_Getch();
	}
}
void muestraIntento(){
	rINTMSK &= ~BIT_TIMER1; //Habilita el timer, enmascara el keyboard
	rINTMSK |= BIT_EINT1;
	modoTimer(1); //Modo muestra de intento
	cuentaIntento = 0;
	posicion = 0;
	while(cuentaIntento <= 16){

	}
}
void compruebaAcierto(){
	rINTMSK &= ~BIT_TIMER1; //Habilita el timer, enmascara el keyboard
	rINTMSK |= BIT_EINT1;
	modoTimer(2); //Modo muestra de clave
	if (comparar() == 1){
		D8Led_symbol(10);
		Uart_Printf("Correcto\n");
	}
	else{
		D8Led_symbol(14);
		Uart_Printf("Error\n");
	}
	cuentaAcierto = 0;
	while(cuentaAcierto <= 4){

	}
}
int main(void)
{	

    sys_init();     		/* Inicializacion de la placa, interrupciones, puertos y UART */
    init_keyboard(); 	    /* Inicializacion de EINT6/7 y del puerto G */
	TIMER_init();	   		// Inicializacion del temporizador
	Uart_Init(115200);

	guardaClave();
	muestraClave();

	while(1){
		leeIntento();
		muestraIntento();
		compruebaAcierto();
	}
    return 0;
}
