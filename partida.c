#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "mazo.h"
#include "partida.h"
#include "colores.h"
#include <string.h>


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
		p->turno = (p->turno + p->jugs.njug - 1) % (p->jugs.njug);
	}
}







int atzar (int a) {
	int b;	
	b=rand() % a;
	return b;
}




tpartida inicio() {
	tpartida p;

	espacio();
	printf("NUEVA PARTIDA\n");
	printf("*************\n\n");

	int nj;
	do {
		printf ("Cuantos jugadores? [3-5]: ");
		scanf ("%d%*c", &nj);
	} while (nj<3 || nj>5);

	p.jugs.njug=nj;
	//numero de jugadors fet

	printf ("Tu nombre? ");
	scanf("%[^\n]%*c", &p.jugs.jug[0].nom[0]);
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
		scanf("%c%*c", &sino);
	} while (sino!='s' && sino!='S' && sino!='n' && sino!='N');

	if (sino=='s' || sino=='S') {
		p.com=1;
	} else {
		p.com=0;
	}
	//modo comprobacio fet


	p.sentido=0;
	p.fi=-1;
	//sentido i final fets

	
	p.robar = iniciar_cartas();
	mezclar_mazo( &(p.robar));
	repartir_cartas( &p);

	int i;	
	int numcart;
	tcarta primera;

	do {
		numcart = atzar(p.robar.n);
		primera = p.robar.mazo[numcart];
	} while (primera.num >= 9);

	p.descartes.n=0;

	cambiar_carta( &(p.robar), &(p.descartes), numcart);
	p.color = primera.col; 
	//descartes i robar

	p.turno = atzar(p.jugs.njug);
	//turno al azar

	espacio();

	return p;
}







void ronda(tpartida p) {
	tcarta null = {0,-1};

	printf("Mazo:\n");

	if (p.com == 1) {
		mostrar_mazo(p.robar);
	} else {
		printf("|");
		mostrar_carta(null);
		printf("| (%d)", p.robar.n);
	}
	//imprime mazo

	printf("\n\nMazo Descartes:\n");
	printf("|");
	mostrar_carta(p.descartes.mazo[p.descartes.n-1]);
	printf("|(%d) ", p.descartes.n);

	if (p.descartes.mazo[ p.descartes.n - 1 ].num >= 13) {
		printf("| Color escogido: |");
		cambiar_color_fondo(p.color);
		printf("  ");
		default_attributes();
	}


	printf("| Sentido: "); 
	
	cambiar_color_letra(4);
	if (p.sentido == 0)
	{
		printf("HORARIO");
	} else {
		printf("ANTIHORARIO");

	}
	default_attributes();
	//imprime descartes
	
	int i, j;

	for (i=0; i<p.jugs.njug; i++)
	{
		printf("\n\n%s:\n",p.jugs.jug[i].nom);
		if (p.com == 1 || i==0) {
			mostrar_mazo(p.jugs.jug[i].c);
		} else {
			printf("|");
			for (j=0; j<p.jugs.jug[i].c.n; j++) {
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
	printf("\n\n");
}













void turno(tpartida *p){
	int i, tria, wea;
	temazo posible;
	tcarta setira;

	cambiar_color_letra(2);	
	printf("\nTurno %s: ", p->jugs.jug[p->turno].nom);
	default_attributes();
	posible = pos_tir(*p);

	if (posible.n>0) {	//pot tirar carta
		if (p->turno == 0) { //tires tu
			printf("Jugades posibles: ");			
			for (i=0; i<posible.n; i++) {		
				printf("%d(|", i);
				mostrar_carta( posible.mazo[i]);
				printf("|) ");			
			}
			
			do {
				printf("Que carta tiras? [0-%d]: ", posible.n-1);
				scanf("%d%*c", &tria);
			} while (tria<0 || tria>=posible.n);

		} else {	//a choice has to be made
			if (p->com==1){ 
				printf("Jugades posibles: ");
				for (i=0; i<posible.n; i++) {
					printf("%d(|", i);
					mostrar_carta( posible.mazo[i]);
					printf("|) ");	 
				}
			}
			tria = atzar(posible.n);
		}	

		setira=posible.mazo[tria];

		printf("Tira: |");
		mostrar_carta(setira);
		printf("| ");

		if (p->jugs.jug[p->turno].c.n == 2)
		{
			cambiar_color_letra(3);
			printf(" ** UNO **  ");
			default_attributes();
		}

		cambiar_carta( &(p->jugs.jug[p->turno].c) , &(p->descartes) ,posible.posis[tria]);

		p->color= setira.col;
		especial( p , setira );
	
	} else {
		tcarta robasion = p->robar.mazo[0];
		int puedese;		

		printf("Coge del mazo: |");
		mostrar_carta(robasion);
		printf("| ");
		
		puedese = comparar_carta(robasion, *p);
		
		if (puedese==1) {
			printf("Tira: |");
			mostrar_carta(robasion);
			printf("| ");
			cambiar_carta( &(p->robar) , &(p->descartes), 0);
			p->color = robasion.col;
			especial( p, robasion);
		} else {
			printf("Ha pasado");
			cambiar_carta( &(p->robar) , &(p->jugs.jug[p->turno].c), 0);
		}
		
	}
		
	printf("\nPress return to continue...");	
	scanf("%*c");
	
	cambio_turno(&(*p));
}












void finalizar_partida(tpartida *p)
{
	int i, pick;
	for(i=0;i<p->jugs.njug;i++)
	{
		if(p->jugs.jug[i].c.n==0)
		{
			p->fi=i;
		}
	}


	//si hay menos de 5 cartas en el mazo para robar, coje todas las del mazo de descartes menos la ultima, las mezcla y las pone en el mazo de robar
	temazo mezclar;
	int fin = p->descartes.n-1;
	if (p->robar.n < 5) {
		for (i=0; i<fin; i++) {
			cambiar_carta( &(p->descartes) , &mezclar, 0);
			printf("Cartas en descarets - %d\nCartas en robar - %d", p->descartes.n, p->robar.n);
		}

		mezclar_mazo( &mezclar);

		for (i=0; i<fin; i++) {
			cambiar_carta( &mezclar , &(p->robar), 0);
		}
	}



}












void especial(tpartida *p, tcarta c) {
	int i, col, ntorn;

	//printf("\nTurno: %d\nSentido: %d\n\nESPECIAL: ", p->turno, p->sentido);

	if(p->sentido==0)
	{ 
		ntorn = (p->turno + 1) % p->jugs.njug;
	}	
	else 
	{
		ntorn = (p->turno + p->jugs.njug - 1) % (p->jugs.njug);
	}



	if (c.num >= 10) {
		//printf("YES\n\n");
		switch(c.num) {
			case 10:	//R
				p->sentido = (p->sentido + 1) % 2;
				break;
			case 11:	//S
				cambio_turno(p);
				break;
			
			case 13:	//W
			case 14:	//W+4
				if (p->turno == 0) {
					do {
						printf("Que color escoges? [ ");
						
						for (i=1; i<=4; i++) {
							printf("%d(|", i);
							cambiar_color_fondo(i);
							printf("  ");
							default_attributes();
							printf("|) ");

						}
						printf("]: ");

						scanf("%d%*c", &col);
					} while (col<1 || col>4);
					
				} else {
					col = atzar(4)+1;
				}

				p->color = col;
				printf("Color escogido: |");
				cambiar_color_fondo(col);
				printf("  ");
				default_attributes();
				printf("| ");

			case 12:	//+2

				if (c.num%2 == 0) {
					for (i=0; i< c.num % 10; i++) {
						cambiar_carta( &(p->robar) , &(p->jugs.jug[ntorn].c) , 0);
					}
					cambio_turno(p);
				}
				break;
		}
	} 
}
