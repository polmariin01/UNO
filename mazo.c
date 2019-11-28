#include <stdio.h>
#include "carta.h"
#include "mazos.h"



int pos_tir(temazo mazo1, temazo mazo2)
{
	int pos_tir[108];
	
	
	return(pos_tir);		
}
	
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

void repartir_cartas(tpartida *partida)
{
	int i,0;
	for(i=0;i<partida->jugs.njug;i++)
	{
		for(k=0;k<7;k++)
		{
			cmbiar_carta(partida->.jugs.jug[i].c.mazo,partida->descartes,0);
		}
	}
}

void cambiar_carta(temazo mazo1, temazo mazo2, int pos)
{
	printf("\nPara ver si ha funcionado (dentro de la funcion)\n");
	printf("\nMazo 1 al principio:\n");
	mostrar_mazo(mazo1);
	printf("\nMazo 2 al principio:\n");
	mostrar_mazo(mazo2);

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

	//wea de prueba
	printf("\n\n\nMazo 1 al final:\n");
	mostrar_mazo(mazo1);
	printf("\nMazo 2 al final:\n");
	mostrar_mazo(mazo2);
}

temazo iniciar_cartas()
{
	int i, j, pos=0;
	temazo mazo;
	mazo.n=0;

	for (i=1; i<=4; i++) {
		for (j=0; j<=12; j++) {
			if (j!=0) {
				mazo.mazo[pos].col=i;
				mazo.mazo[pos].num=j;
				mazo.n++;
				pos++;
			}
			mazo.mazo[pos].col=i;
			mazo.mazo[pos].num=j;
			mazo.n++;
			pos++;
		}
	}

	for (i=0; i<2; i++) {
		for(j=0; j<4; j++) {
			mazo.mazo[pos].col=0;
			mazo.mazo[pos].num=13+i;
			pos++;
			mazo.n++;
		}
	}
	return mazo;
}

void mezclar_mazo(temazo mazo)  //s'ha d'incloure la llibreria stdlib.h i la time.h//
{	
	for(i=0;i<106;i++)
	{
		

