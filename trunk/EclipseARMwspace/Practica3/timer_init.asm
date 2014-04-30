.global TIMER_init

.extern timer_ISR

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
.equ pISR_TIMER0, 0xc7fff54

.equ rTCFG0, 0x1d50000
.equ rTCFG1, 0x1d50004
.equ rTCNTB0, 0x1d5000c
.equ rTCMPB0, 0x1d50010
.equ rTCON, 0x1d50008

.equ BorraIspc, 0xFFFFFFFF;
.equ BorraExtint, 0xf;
.equ ConfigIntmod, 0x0;
.equ Pines, 0xffff;
.equ FlancoBajada, 0x22222222;
.equ BitsTimer, 0xFBFFDFFF;

.equ Constante, 65535;

TIMER_init:
	/* Configuracion del controlador de interrupciones */

/*TAREA 2b*/
	/* Configuraion controlador de interrupciones */
	@rINTMOD=0x0; // Configura las linas como de tipo IRQ

	ldr r0, =ConfigIntmod;
	ldr r1, =rINTMOD;
	str r0,[r1]

	@rINTCON  =0x1;  // Habilita int. vectorizadas y la linea IRQ (FIQ no)

	mov r0, #1;
	ldr r1, =rINTCON;
	str r0,[r1]

	@rINTMSK &= ~(BIT_GLOBAL|BIT_TIMER0);  // habilita Timer0 y el bit global

	ldr r3, =rINTMSK;
	ldr r0, [r3];
	ldr r1, =BitsTimer
	and r2, r0, r1;

	str r2, [r3];

	/* Establece la rutina de servicio para TIMER0 */
	@pISR_TIMER0=(unsigned)timer_ISR;

	ldr r0, =timer_ISR;
    ldr r1, =pISR_TIMER0;
	str r0, [r1];

/*fin TAREA 2b*/

	/* Configura el Timer0 */
    @rTCFG0 = 255;

    mov r0, #255;
	ldr r1, =rTCFG0;
	str r0,[r1];

    @rTCFG1 = 0x0;
    mov r0, #0;
	ldr r1, =rTCFG1;
	str r0,[r1];

    @rTCNTB0 = 65535;
    ldr r0, =Constante
	ldr r1, =rTCNTB0;
	str r0,[r1];

    @rTCMPB0 = 12800;

    mov r0, #12800;
	ldr r1, =rTCMPB0;
	str r0,[r1];

    /* establecer update=manual + inverter=on */
	@rTCON = 0x2;

    mov r0, #0x2;
	ldr r1, =rTCON;
	str r0,[r1];
	/* inicial timer con auto-reload */

    @rTCON  = 0x09;

    mov r0, #0x09;
	ldr r1, =rTCON;
	str r0,[r1];

	mov pc,lr

