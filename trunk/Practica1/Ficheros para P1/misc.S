
.text

contarUnos:

		bx lr		

rgb2gray:

		bx lr

div10000:
		push {fp}
		LDR     R1, =0xD1B71758
		UMULL   R3, R2, R0, R1
		MOV     R0, R2,LSR#13
 		pop {fp}
 		bx lr



