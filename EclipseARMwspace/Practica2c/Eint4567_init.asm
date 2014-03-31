.global EINT4567_init

.extern Eint4567_ISR

.equ rI_ISPC, 0x1e00024
.equ rEXTINTPND, 0x1d20054
.equ rEXTINT, 0x1d20050
.equ rINTMOD, 0x1e00008
.equ rINTCON, 0x1e00000
.equ rINTMSK, 0x1e0000c
.equ BIT_GLOBAL, (0x1<<26)
.equ BIT_EINT4567, (0x1<<21)
.equ rPCONG, 0x1d20040
.equ rPUPG, 0x1d20048
.equ pISR_EINT4567, 0xc7fff74


.equ BorraIspc, 0xFFFFFFFF;
.equ BorraExtint, 0xf;
.equ ConfigIntmod, 0x0;
.equ Pines, 0xffff;
.equ FlancoBajada, 0x22222222;
.equ Bits, 0xFBDFFFFF;

EINT4567_init:
	/* Configuracion del controlador de interrupciones */
	
	@ rI_ISPC=0xFFFFFFFF	;	   // Borra INTPND
	ldr r0, =BorraIspc;
	ldr r1, =rI_ISPC;
	str r0,[r1]	
	
	@rEXTINTPND = 0xf; 		   // Borra EXTINTPND
	
	ldr r0, =BorraExtint;
	ldr r1, =rEXTINTPND;
	str r0,[r1]
	
	@rINTMOD=0x0;	   // Configura las lineas como de tipo IRQ mediante rINTMOD
	
	ldr r0, =ConfigIntmod;
	ldr r1, =rINTMOD;
	str r0,[r1]
	
	@rINTCON  =0x1; // Habilita int. vectorizadas y la linea IRQ (FIQ no) mediante rINTCON
	
	mov r0, #1;
	ldr r1, =rINTCON;
	str r0,[r1]
	
	@rINTMSK = ~(BIT_GLOBAL|BIT_EINT4567); // Emascara todas las lineas excepto eint4567 y el bit global mediante rINTMSK
	
	ldr r0, =Bits;
	ldr r1, =rINTMSK;
	str r0, [r1];
	
		
	/* Establece la rutina de servicio para Eint4567 */
    @pISR_EINT4567 = (int)Eint4567_ISR;
    ldr r0, =Eint4567_ISR;
    ldr r1, =pISR_EINT4567;
	str r0, [r1];
	
    /* Configuracion del puerto G */
    @rPCONG  = 0xffff;        		// Establece la funcion de los pines (EINT0-7)
	
	ldr r0, =Pines;
	ldr r1, =rPCONG;
	str r0,[r1]
	
	@rPUPG   = 0x0;                  // Habilita el "pull up" del puerto
	
	mov r0, #0;
	ldr r1, =rPUPG;
	str r0,[r1]
	
	@rEXTINT = rEXTINT|0x22222222;   // Configura las lineas de int. como de flanco de bajada
	
	ldr r0, =FlancoBajada;
	ldr r1, =rEXTINT;
	ldr r2, [r1];
	orr r0, r2, r0;
	ldr r1, =rEXTINT;
	str r0,[r1];

    /* Por precaucion, se vuelven a borrar los bits de INTPND y EXTINTPND */
	@ rI_ISPC=0xFFFFFFFF	;	   // Borra INTPND
	
	ldr r0, =BorraIspc;
	ldr r1, =rI_ISPC;
	str r0,[r1]	
	
	@rEXTINTPND = 0xf; 		   // Borra EXTINTPND
	
	ldr r0, =BorraExtint;
	ldr r1, =rEXTINTPND;
	str r0,[r1]

	mov pc,lr

