/*********************************************************************************************
* Fichero:	uart.c
* Autor:	
* Descrip:	funciones de UART
* Version:
*********************************************************************************************/
/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "uart.h"
#include <stdarg.h>
#include <stdio.h>


/** RECORDAD consultar las macros y constantes de 44b.b:
 RdURXH0, WrUTXH0n, rULCON0, rUCON0.....
 **/
/*--- implementación de las funciones ---*/
void Uart_Init(int baud)
{
// a COMPLETAR
    
    /* UART0 */
	rULCON0	= 0x03;
        // Modo normal, no paridad, 1b stop, 8b char
	rUCON0 = 0x205;
      // tx=nivel, rx=flanco, no rx-timeout ni rx-error, normal, int/polling
    
    // formula division de frecuencia
    rUBRDIV0=( (int)(MCLK/16./baud + 0.5) -1 );
    
    // Desactivar FIFO
    rUFCON0	 = 0x00;
    rUMCON0 = 0x00;
    // Desactivar control de flujo

    
}

///// Estos comentarios estan pensados para trabajar SIN interrupciones
/// PodŽis hacerlo COMO quer‡is.


/// COMPLETAR
char Uart_Getch(void)
{
    /// COMPLETAR
    
    // esperar a que el buffer contenga datos
	while (!(rUTRSTAT0 & 0x1));
	
    // devolver el caracter
    char c = RdURXH0();
    return c;
}


//COMPLETAR
void Uart_SendByte(int data)
{
    // Tratamiento del retorno de carro
    if(data == '\n')
	{
	   while (!(rUTRSTAT0 & 0x2));     // esperar a que THR se vacie
	   WrUTXH0('\r');			       // escribir retorno de carro (utilizar macro)
    }
	while (!(rUTRSTAT0 & 0x2));


    // COMPLETAR escribir data (utilizar macro)
	if(data != '\n') WrUTXH0(data);
}

void Uart_SendString(char *pt)
{
    while (*pt)					// mandar byte a byte hasta completar string
	Uart_SendByte(*pt++);
}

void Uart_Printf(char *fmt,...)
{
    va_list ap;
    char string[256];
    va_start(ap,fmt);
    vsprintf(string,fmt,ap);
    Uart_SendString(string);
    va_end(ap);
}

