#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "carta.h"
#include "mazo.h"
#include "partida.h"
#include "colores.h"
#include "extres.h"




int main() {
	tpartida p;
	int i, a;

	srand(time(NULL));
	
	espacio();

	intro();
	printf("\n\n");

	p = inicio();

	espacio();


	while (p.fi==0)
	{
//		chivato(p);
//		espacio();
		ronda(p);
		turno(&p);
		finalizar_partida(&p);
		espacio();
	}


}
