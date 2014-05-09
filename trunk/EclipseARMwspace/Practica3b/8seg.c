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

/* tabla de segmentos */
int Symbol[] = { SEGMENT_A, SEGMENT_B, SEGMENT_C, SEGMENT_D, SEGMENT_E, SEGMENT_G,SEGMENT_F};
			  					  
/*--- declaración de funciones ---*/
void D8Led_init(void);
void D8Led_symbol(int value); 

/*--- código de las funciones ---*/
void D8Led_init(void)
{
    /* Estado inicial del display con todos los segmentos iluminados 
       (buscar en los ficheros de cabera la direccion implicada) */
    LED8ADDR = 0 ;
}

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
