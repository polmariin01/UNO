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

void cambiar_carta(temazo mazo1, temazo mazo2, int pos)
{
	//carta que s'ha de moure, copia auxiliar
	tcarta c;
	c=mazo1.mazo[pos];
	
	//quitar carta de mazo 1

	for (i=pos; i<mazo1.n-1;i++) {
		mazo1.mazo[i]=mazo1.mazo[i+1];
	} 
	mazo1.n--;

	//poner carta en mazo 2
	
	mazo2.mazo[mazo2.n]=c;
	mazo2.n++;
}
void buscar_carta(tjug mazo_jug.n)//no estic segur que sigui aquesta variable la que entra a la funcio, en teoria hauria d'entrar el num de cartes del mazo del jugador//
{
int i;
	//feta per eudi: busca una carta dins del mazo del jugador que pugui ser tirada, utilitzo 		la funcio del gil de comparar_carta
 	for (i=0; i>mazo_jug.n; i++)
	{
		comparar_carta(tcarta carta1; tcarta carta2);
			
	}











