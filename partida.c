#include <stdio.h>
#include <stdlib.h>
#include "carta.h"
#include "mazo.h"
#include "partida.h"
#include "colores.h"

void espacio() {
	for (int i=0; i<100; i++) {
		printf("\n");
	}
}



//Sentido=0-->horari, Sentido=1-->antihorari
void cambio_turno(tpartida *p)
{
	if(p->sentido==0)
	{ 
		p->turno =(p->turno + 1) % p->jugs.njugs;
	}	
	else 
	{
		p->turno = (p->turno + p->jugs.njugs) % (p->jugs.njugs + 1);
	}
}




int atzar (int a) {
	int b;	
	a=rand() % b;
	return a;
}




tpartida inicio()
{
	tpartida p;

	int nj;
	do
	{
		printf ("Cuantos jugadores? [3-5]: ");
		scanf ("%d%*c", &nj);
	} while (nj<3 || nj>5);
	p.jugs.njug=nj;
	//numero de jugadors fet
	

	printf ("Tu nombre? ");
	scanf("%s", &p.jugs.jug[0].nom);
	//nom jugador fet


	for (int i=1; i<nj-1; i++) {
		p.jugs.jug[i].nom[1]="R";
		p.jugs.jug[i].nom[2]="o";
		p.jugs.jug[i].nom[3]="b";
		p.jugs.jug[i].nom[4]="o";
		p.jugs.jug[i].nom[5]="t";
		p.jugs.jug[i].nom[6]=48+i;
		p.jugs.jug[i].nom[7]="\0";
		
		p.jugs.jug[i].c.n=0;
	}
	//noms robots i robots fets


	char sino;
	do {
		printf("Quieres ejecutar en modo COMPROBACION? [s/n]: ");
		scanf("%c%*c", &sino);
	} while (sino!='s' && sino!='S' && sino!='n' && sino!='S');

	if (sino=='s' || sino=='S') {
		p.com=1;
	} else {
		p.com=0;
	}
	//modo comprobacio fet


	p.sentido=0;
	p.final=0;
	//sentido i final fets


	p.robar = iniciar_cartas();
	p.robar = mezclar_mazo( p.robar);

	repartir_cartas( *p);


	int numcart;
	tcarta primera;
	do {
		numcart = atzar(108);
		primera = p.robar.mazo[numcart];
	} while (primera.num > 9);

	cambiar_carta( p.robar, p.descartes, numcart);

	//descartes i robar


	p.turno = atzar(p.jugs.njug);

	//turno al azar

	return p;
}




void ronda(tpartida p) {
	if (p.com == 1) {
		printf("\nMazo:\n");
		printf("|");
		mostrar_carta(p.robar.mazo[p.robar.n-1]);
		printf("|\n");
		printf();
	




	} else {




	}

}



void finalizar_partida(tpartida *p)
{
	int i;
	for(i=0;i<p->jugs.njugs;i++)
	{
		if(p->jugs.jug[i].c.n==0)
			p->final=0;
	}
}


//void especial();
