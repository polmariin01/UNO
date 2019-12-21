#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "mazo.h"
#include "partida.h"
#include "colores.h"


void espacio() {
	for (int i=0; i<100; i++)
	{
		printf("\n");
	}
}



void cambio_turno(tpartida *p) {
	if(p->sentido==0)
	{ 
		p->turno = (p->turno + 1) % p->jugs.njug;
	}	
	else 
	{
		p->turno = (p->turno + p->jugs.njug) % (p->jugs.njug + 1);
	}
}




int atzar (int a) {
	int b;	
	b=rand() % a;
	return b;
}




tpartida inicio() {
	tpartida p;

	int nj;
	do {
		printf ("Cuantos jugadores? [3-5]: ");
		scanf ("%d%*c", &nj);
	} while (nj<3 || nj>5);

	p.jugs.njug=nj;

	//numero de jugadors fet
	

	printf ("Tu nombre? ");
	scanf("%s%*c", &p.jugs.jug[0].nom[0]);
	//nom jugador fet


	for (int i=1; i<nj; i++) {
		p.jugs.jug[i].nom[0]='R';
		p.jugs.jug[i].nom[1]='o';
		p.jugs.jug[i].nom[2]='b';
		p.jugs.jug[i].nom[3]='o';
		p.jugs.jug[i].nom[4]='t';
		p.jugs.jug[i].nom[5]=48+i;
		p.jugs.jug[i].nom[6]='\0';
		
		p.jugs.jug[i].c.n=0;

	}
	//noms robots i robots fets


	char sino;
	do {
		printf("Quieres ejecutar en modo COMPROBACION? [s/n]: ");
		scanf("%c", &sino);
	} while (sino!='s' && sino!='S' && sino!='n' && sino!='N');

	if (sino=='s' || sino=='S') {
		p.com=1;
	} else {
		p.com=0;
	}
	//modo comprobacio fet


	p.sentido=0;
	p.fi=0;
	//sentido i final fets

	
	p.robar = iniciar_cartas();

	/*
	printf("\n\nMazo iniciado\n");
	mostrar_mazo(p.robar);
	
	mezclar_mazo( &(p.robar)); //no funciona, Gil se encarga

	printf("\n\nMazo mezclado\n");
	mostrar_mazo(p.robar);

	repartir_cartas( &p);

	printf("\n\nMazo repartido\n");
	mostrar_mazo(p.robar);
	*/

	mezclar_mazo( &(p.robar));
	repartir_cartas( &p);

	int i;
	for (i=0; i<nj; i++) {
		printf("\n%s\n", p.jugs.jug[i].nom);
		mostrar_mazo(p.jugs.jug[i].c);
	}
	
	
	int numcart;
	tcarta primera;

	do {
		numcart = atzar(p.robar.n);
		primera = p.robar.mazo[numcart];
	} while (primera.num > 9);

	cambiar_carta( &(p.robar), &(p.descartes), numcart);

	//descartes i robar


	p.turno = atzar(p.jugs.njug);

	//turno al azar

	return p;
}




void ronda(tpartida p) {
	tcarta null = {0,-1};

	printf("\nMazo:\n");

	if (p.com == 1) {
		mostrar_mazo(p.robar);
	} else {
		printf("|");
		mostrar_carta(null);
		printf("| (%d)\n", p.robar.n);
	}
	//imprime mazo

	printf("Mazo Descartes:\n");
	printf("|");
	mostrar_carta(p.descartes.mazo[p.descartes.n-1]);
	printf("| (%d) Sentido: \n", p.descartes.n);
	
	cambiar_color_letra(4);
	if (p.sentido == 0)
	{
		printf("HORARIO");
	} else {
		printf("ANTIHORARIO");

	}
	default_attributes();
	//imprime descartes


	int i;


	for (i=0; i<p.jugs.njug; i++)
	{
		printf("\n%s:\n",p.jugs.jug[i].nom);
		if (p.com == 1 || i==0) {
			mostrar_mazo(p.jugs.jug[i].c);
		} else {
			printf("|");
			for (i=0; i<p.jugs.jug[i].c.n; i++) {
				mostrar_carta(null);
				printf("|");
			}
		}

		if (p.jugs.jug[i].c.n == 1)
		{
			cambiar_color_letra(3);
			printf(" ** UNO **");
			default_attributes();
		}
	}
	scanf("%*c");
}



void turno(tpartida *p){
	int i, tria;
	temazo posible;
	tcarta setira;

	cambiar_color_letra(2);	
	printf("Turno %s: ", p->jugs.jug[p->turno].nom);
	default_attributes();
	printf("Jugades posibles: ");
	posible = pos_tir( p->jugs.jug[p->turno].c , p->descartes.mazo[p->descartes.n-1] );
	
	if (posible.n>0) {	//pot tirar carta

		if (p->turno == 0) { //tires tu
			for (i=0; i<posible.n; i++) {		
				printf("%d(|", i);
				mostrar_carta( posible.mazo[i]);
				printf("|) ");			
			}
			
			
			do {
				printf("Que carta tiras? [0-%d]: ", posible.n-1);
				scanf("%d%*c", &tria);
			} while (tria>=0 || tria<posible.n);

			setira=posible.mazo[tria];


		} else { //tiren robots
			


		//a choice has to be made
	 
		}

		printf("Tira: ");
		mostrar_carta(setira);
	
	} 
	//else { //no pot tirar cap carta

	
}



void finalizar_partida(tpartida *p)
{
	int i;
	for(i=0;i<p->jugs.njug;i++)
	{
		if(p->jugs.jug[i].c.n==0)
		{
			p->fi=1;
		}
	}
}


//void especial();
