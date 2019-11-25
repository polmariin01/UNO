#include <stdio.h>
#include "carta.h"

typedef struct
{
	int n;			//numero de cartas en el mazo
	tcarta mazo[MAXCART];	//cartas del mazo
} temazo;

typedef struct
{
	char nom[20];	//nombre jugador
	temazo c;	//mazo del jugador
} tjug;


void mostrar_mazo(temazo mazo){
	int numcartas=mazo.n;
	int i, j, files, fila;
	files=numcartes/20;
	if (numcartes%20!=0) {
		numcartes++;
	}

	//imprimir files de 20 cartes
	for (i=0; i<files; i++) {
		printf("|");

		if (numcartes/20>=1){
			fila=20;
		} else {
			fila=numcartes%20;
		}
		numcartes=numcartes-20;

		for (j=0; j<fila; j++) {
			mostrar_carta(mazo.mazo[20*i+j]);
			printf("|");
		}
		printf("\n");
		if (i<files-1){
			printf("+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+");
		}
		printf("\n");
	}
}
