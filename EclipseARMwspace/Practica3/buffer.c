
#include <stdio.h>
#include <stdlib.h>

int clave[] = {0,0,0,0};
int intento[] = {0,0,0,0};

void insertarClave (int nuevo){

	clave[0] = clave[1];
	clave[1] = clave[2];
	clave[2] = clave[3];
	clave[3] = nuevo;
}
int leerClave(int posicion){
	return clave[posicion];
}
void insertarIntento (int nuevo){

	intento[0] = intento[1];
	intento[1] = intento[2];
	intento[2] = intento[3];
	intento[3] = nuevo;
}
int leerIntento(int posicion){
	return intento[posicion];
}
void resetIntento(){
	intento[0] = 0;
	intento[1] = 0;
	intento[2] = 0;
	intento[3] = 0;
}
int comparar(){
	if(clave[0] == intento[0])
		if(clave[1] == intento[1])
			if(clave[2] == intento[2])
				if(clave[3] == intento[3])
					return 1;
	return 0;
}
