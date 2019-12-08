#ifndef PARTIDA_H
#define PARTIDA_H
#define MAXCART 108

#include <stdio.h>
#include "carta.h"
#include "mazo.h"


typedef struct
{
	int col;
	int num;
} tcarta;

typedef struct
{
	int n;
	tcarta mazo[MAXCART];
} temazo;

typedef struct
{
	char nom[20];
	temazo c;
} tjug;

typedef struct
{
	int njug;
	tjug jug[5];
}tjugadores;

typedef struct
{
	int sentido; //0 horario, 1 antihorario//
	int com; //0 cubert, 1 descubert//
	int turno;
	int fi;
	tjugadores jugs;
	temazo descartes;
	temazo robar;
}tpartida;



void espacio();
void cambio_turno(tpartida *p);
int atzar (int a);
tpartida inicio();
void ronda(tpartida p);
void finalizar_partida(tpartida *p);

//void especial();



//int jugadas(tcarta a, temazo b);


#endif
