/*********************************************************************************************
* Fichero:	8led.c
* Autor:		
* Descrip:	Funciones de control del display 8-segmentos
* Version:	
*********************************************************************************************/

/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "def.h"

/*--- definicion de macros ---*/
#define	LED8ADDR	(*(volatile unsigned char *)(0x2140000))
// typedef enum{false, true} bool;
extern char actual;
/* Mapa de bits de cada segmento 
  (valor que se debe escribir en el display para que se ilumine el segmento) */
#define SEGMENT_A		0x80
#define SEGMENT_B		0x40
#define SEGMENT_C		0x20
#define SEGMENT_D		0x08
#define SEGMENT_E		0x04
#define SEGMENT_F		0x02
#define SEGMENT_G		0x01
#define SEGMENT_P		0x10

/*--- variables globales ---*/

#define DIGIT_F (SEGMENT_A | SEGMENT_G | SEGMENT_E | SEGMENT_F)
#define DIGIT_E (SEGMENT_A | SEGMENT_G | SEGMENT_E | SEGMENT_F | SEGMENT_D)
#define DIGIT_D (SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F |  SEGMENT_E)
#define DIGIT_C (SEGMENT_A | SEGMENT_G | SEGMENT_E | SEGMENT_D)
#define DIGIT_B (SEGMENT_C | SEGMENT_G | SEGMENT_E | SEGMENT_F |  SEGMENT_D)
#define DIGIT_A (SEGMENT_A | SEGMENT_G | SEGMENT_E | SEGMENT_F | SEGMENT_B | SEGMENT_C)

#define DIGIT_9 (SEGMENT_A | SEGMENT_G | SEGMENT_B | SEGMENT_F |  SEGMENT_C)
#define DIGIT_8 (SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D |  SEGMENT_E |  SEGMENT_F |  SEGMENT_G)
#define DIGIT_7 (SEGMENT_A | SEGMENT_B | SEGMENT_C)
#define DIGIT_6 (SEGMENT_A | SEGMENT_G | SEGMENT_E | SEGMENT_F |  SEGMENT_D |  SEGMENT_C)
#define DIGIT_5 (SEGMENT_A | SEGMENT_G | SEGMENT_C | SEGMENT_F |  SEGMENT_D)
#define DIGIT_4 (SEGMENT_B | SEGMENT_G | SEGMENT_C | SEGMENT_F)
#define DIGIT_3 (SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_F |  SEGMENT_D)
#define DIGIT_2 (SEGMENT_A | SEGMENT_B | SEGMENT_E | SEGMENT_F |  SEGMENT_D)
#define DIGIT_1 (SEGMENT_B | SEGMENT_C)
#define DIGIT_0 (SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_G)

int segmentOn[] = {0, 0, 0, 0, 0, 0, 0, 0};

/* tabla de segmentos */
int Symbol[] = { SEGMENT_A, SEGMENT_B, SEGMENT_C, SEGMENT_P, SEGMENT_D, SEGMENT_E, SEGMENT_F, SEGMENT_G};
			  					  

/*--- declaración de funciones ---*/
void D8Led_init(void);
void D8Led_symbol(int value); 
void D8Led_parpadear();
void D8Led_swicht();
void D8Led_pintaSeg();
/*--- código de las funciones ---*/
void D8Led_init(void)
{
    /* Estado inicial del display con todos los segmentos iluminados 
       (buscar en los ficheros de cabera la direccion implicada) */
    LED8ADDR = 0 ;
}

//Esta funcion hace parpadear el segmento solicitado
//Cada vez que se la llama enciende o apaga el segmento adecuado
void D8Led_parpadear() {
	switch (actual){
		case 'a':
			if(((~LED8ADDR) & SEGMENT_A) == SEGMENT_A) {	//Estaba encendido => lo apago
				LED8ADDR |= SEGMENT_A;
			} else {										//Estaba apagado => lo enciendo
				LED8ADDR &= ~SEGMENT_A;
			}
			break;
		case 'b':
			if(((~LED8ADDR) & SEGMENT_B) == SEGMENT_B) {
				LED8ADDR |= SEGMENT_B;
			} else {
				LED8ADDR &= ~SEGMENT_B;
			}
			break;
		case 'c':
			if(((~LED8ADDR) & SEGMENT_C) == SEGMENT_C) {
				LED8ADDR |= SEGMENT_C;
			} else {
				LED8ADDR &= ~SEGMENT_C;
			}
			break;
		case 'd':
			if(((~LED8ADDR) & SEGMENT_D) == SEGMENT_D) {
				LED8ADDR |= SEGMENT_D;
			} else {
				LED8ADDR &= ~SEGMENT_D;
			}
			break;
		case 'e':
			if(((~LED8ADDR) & SEGMENT_E) == SEGMENT_E) {
				LED8ADDR |= SEGMENT_E;
			} else {
				LED8ADDR &= ~SEGMENT_E;
			}
			break;
		case 'f':
			if(((~LED8ADDR) & SEGMENT_F) == SEGMENT_F) {
				LED8ADDR |= SEGMENT_F;
			} else {
				LED8ADDR &= ~SEGMENT_F;
			}
			break;
		case 'g':
			if(((~LED8ADDR) & SEGMENT_G) == SEGMENT_G) {
				LED8ADDR |= SEGMENT_G;
			} else {
				LED8ADDR &= ~SEGMENT_G;
			}
			break;
		default:
			if(((~LED8ADDR) & SEGMENT_P) == SEGMENT_P) {
				LED8ADDR |= SEGMENT_P;
			} else {
				LED8ADDR &= ~SEGMENT_P;
			}
			break;
		}

}

//Esta funcion enciende o apaga un segmento concreto
void D8Led_swicht(){
	switch (actual){
		case 'a':
			if(segmentOn[0] == 1) {
				segmentOn[0] = 0;
			} else {
				segmentOn[0] = 1;
			}
			break;
		case 'b':
			if(segmentOn[1] == 1) {
				segmentOn[1] = 0;
			} else {
				segmentOn[1] = 1;
			}
			break;
		case 'c':
			if(segmentOn[2] == 1) {
				segmentOn[2] = 0;
			} else {
				segmentOn[2] = 1;
			}
			break;
		case 'p':
			if(segmentOn[3] == 1) {
				segmentOn[3] = 0;
			} else {
				segmentOn[3] = 1;
			}
			break;
		case 'd':
			if(segmentOn[4] == 1) {
				segmentOn[4] = 0;
			} else {
				segmentOn[4] = 1;
			}
			break;
		case 'e':
			if(segmentOn[5] == 1) {
				segmentOn[5] = 0;
			} else {
				segmentOn[5] = 1;
			}
			break;
		case 'f':
			if(segmentOn[6] == 1) {
				segmentOn[6] = 0;
			} else {
				segmentOn[6] = 1;
			}
			break;
		default:
			if(segmentOn[7] == 1) {
				segmentOn[7] = 0;
			} else {
				segmentOn[7] = 1;
			}
			break;
		}
}

//Esta funcion actualiza LED8ADDR pintando los segmentos adecuados en funcion de segmentOn
void D8Led_pintaSeg(){
	int i = 0;
	while( i < 8){
		if (segmentOn[i]==1)
			LED8ADDR &= ~Symbol[i];
		i++;
	}
}

//D8Led_symbol() no se usa en el extra
void D8Led_symbol(int value)
{
/*Tarea 3*/
	//int num = value%16;
	switch (value){
		case 0:
			LED8ADDR = ~DIGIT_0;
			break;
		case 1:
			LED8ADDR = ~DIGIT_1;
			break;
		case 2:
			LED8ADDR = ~DIGIT_2;
			break;
		case 3:
			LED8ADDR = ~DIGIT_3;
			break;
		case 4:
			LED8ADDR = ~DIGIT_4;
			break;
		case 5:
			LED8ADDR = ~DIGIT_5;
			break;
		case 6:
			LED8ADDR = ~DIGIT_6;
			break;
		case 7:
			LED8ADDR = ~DIGIT_7;
			break;
		case 8:
			LED8ADDR = ~DIGIT_8;
			break;
		case 9:
			LED8ADDR = ~DIGIT_9;
			break;
		case 10:
			LED8ADDR = ~DIGIT_A;
			break;
		case 11:
			LED8ADDR = ~DIGIT_B;
			break;
		case 12:
			LED8ADDR = ~DIGIT_C;
			break;
		case 13:
			LED8ADDR = ~DIGIT_D;
			break;
		case 14:
			LED8ADDR = ~DIGIT_E;
			break;
		default:
			LED8ADDR = ~DIGIT_F;
			break;

	/* muestra el Symbol[value] en el display   */

	}
		
		
/*fin Tarea 3*/		
}
