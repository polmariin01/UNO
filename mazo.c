#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "mazo.h"
#include "partida.h"
#include "colores.h"


temazo pos_tir(tpartida p)
{
	temazo t;
	t.n=0;
	int i,k, a, b=0;
	for(i=0; i< p.jugs.jug[p.turno].c.n ; i++)
	{
		a=comparar_carta(p.jugs.jug[p.turno].c.mazo[i], p);
		if(a==1)
		{
			t.mazo[b]=p.jugs.jug[p.turno].c.mazo[i];
			t.posis[b]=i;
			b++;
			t.n++;
		}
	}

	if (t.n==0) { //en cas que no hagi trobat cap carta que es pugui tirar diferent al +4
		for(i=0; i< p.jugs.jug[p.turno].c.n ; i++)
		{
			a=comparar_carta(p.jugs.jug[p.turno].c.mazo[i], p);
			if(a==2)
			{
				t.mazo[b]=p.jugs.jug[p.turno].c.mazo[i];
				t.posis[b]=i;
				b++;
				t.n++;
			}
		}
	}
	return(t);		
}




void mostrar_mazo(temazo mazo){
	int numcartes=mazo.n;
	int i, j, files, fila;
	files=numcartes/20;
	if (numcartes%20!=0) {
		files++;
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

		if (i<files-1){
		printf("\n");
		printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+");
		printf("\n");
		}
		
	}
}



void cambiar_carta(temazo *mazo1, temazo *mazo2, int pos)
{
	int i;
	
	//carta que s'ha de moure, copia auxiliar
	tcarta c;
	c=mazo1->mazo[pos];
	
	//quitar carta de mazo 1

	for (i=pos; i<mazo1->n-1; i++) {
		mazo1->mazo[i]=mazo1->mazo[i+1];
	} 
	mazo1->n--;

	//poner carta en mazo 2
	
	mazo2->mazo[mazo2->n]=c;
	mazo2->n++;
}



void repartir_cartas(tpartida *partida)
{
	int i,k;
	for(i=0; i<partida->jugs.njug; i++)
	{
		for(k=0;k<7;k++)
		{
			cambiar_carta(&(partida->robar), &(partida->jugs.jug[i].c), 0);
		}
	}
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
				//0 nomes hi hi ha una de cada color
			}
			mazo.mazo[pos].col=i;
			mazo.mazo[pos].num=j;
			mazo.n++;
			pos++;
		}
	}
	//crea 2 cartas de cada color de numeros del 1 al 9, R, S i +2

	for (i=0; i<2; i++) {
		for(j=0; j<4; j++) {
			mazo.mazo[pos].col=0;
			mazo.mazo[pos].num=13+i;
			pos++;
			mazo.n++;
		}
	}
	//crea les cartes que falten, W+4 i W (4 de cada)

	return mazo;
}



void mezclar_mazo(temazo *mazo) 
{	
	int a, i, b;
	tcarta c;
	for(i=0;i< 2* mazo->n ;i++)
	{
		a = atzar(mazo->n);
		do {
			b = atzar(mazo->n);
		} while (b==a);

		c = mazo->mazo[a];
		mazo->mazo[a]=mazo->mazo[b];
		mazo->mazo[b]=c;
	}
}
