
	.global RGB2GrayMatrix

	RGB2GrayMatrix:
		@En r0 tenemos la direccion de la matriz rgb
		@En r1 tenemos la direccion de la matriz de grises
		@En r2 tenemos nfilas
		@En r3 tenemos ncols

		PUSH {lr}

		mul r2, r3, r2			@En r2 tenemos nfilas*ncols := N
		add r2, r1, r2 			@Ahora en r2 ponemos el margen final: destino_final:= destino + N

buclei:	cmp  r1, r2				@destino_actual = destino_final?
		beq endBuclei

		PUSH {r0, r1, r2}		@Guardamos los registros por si algún chino los toca luego en la subrutina
		bl rgb2gray				@Llamamos a la subrutina

		mov r0, r3				@El valor devuelto se pasa a r3 para mantenerlo
		POP {r0, r1, r2}		@Recuperamos los valores anteriores a la llamada

		strb r3, [r1]			@dest[] = rgb2Gray()

		add r0, r0, #4			@orig := orig + 4
		add r1, r1, #1			@destino := destino + 1
		b buclei

endBuclei:

		pop {pc}

		@Ignacio Iker Prado Rujas, Enrique Ballesteros Horcajo
