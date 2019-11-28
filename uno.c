#include <stdio.h>
#include "cartas.c"
#include "mazo.c"
#include "partida"
#define MAXCART 108

typedef struct
{
	int col;
	char car;
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
	int color;
	int sentido; //0 horario, 1 antihorario//
	int com; //0 cubert, 1 descubert//
	int turno;
}tpartida;
//wea


