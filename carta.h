#include <stdio.h>

#define MAXCART 108


typedef struct
{
	int col;	//color (0 - sin color, 1 - azul, 2 - rojo, 3 - verde, 4 - amarillo)
	int car;	//tipo de carta (0,1,2,3,4,5,6,7,8,9,10(S),11(R),12(+2),13(W),14(+4))
} tcarta;

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


void mostrar_carta(tcarta carta);
void comparar_carta(tcarta carta1, tcarta carta2);
