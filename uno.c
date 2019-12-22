#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "carta.h"
#include "mazo.h"
#include "partida.h"
#include "colores.h"




int main() {
	tpartida p;
	int i, a;
	srand(time(NULL));

	p = inicio();
	espacio();


	while (p.fi==0)
	{
		ronda(p);
		turno(&p);
		finalizar_partida(&p);
		espacio();
	}


}
