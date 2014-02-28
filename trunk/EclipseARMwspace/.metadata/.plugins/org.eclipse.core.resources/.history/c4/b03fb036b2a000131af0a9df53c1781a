#include "trafo.h"
#include "types.h"


extern unsigned char rgb2gray(pixelRGB* pixel);

void RGB2GrayMatrix(pixelRGB orig[], unsigned char dest[], int nfilas, int ncols) {
    int i, j;
	for (i = 0; i < nfilas; i++)
		for (j = 0; j < ncols; j++)
			dest[i*ncols+j] = rgb2gray(orig[i*ncols+j]);
    
}

void Gray2BinaryMatrix(unsigned char orig[], unsigned char dest[],
		unsigned char umbral, int nfilas, int ncols) {
	int i,j;
	// umbral será una variable o constante de nuestro código
	for (i = 0; i < nfilas; i++) {
		for (j = 0; j < ncols; j++) {
			if (orig[i*ncols + j] > umbral)
				dest[i*ncols + j] = 1;
			else
				dest[i*ncols + j] = 0;
		}
	}
    
}

