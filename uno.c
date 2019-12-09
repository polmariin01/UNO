#include <stdio.h>
#include "carta.h"
#include "mazo.h"
#include "partida.h"
#include "colores.h"



int main() {
	tpartida p;

	p = inicio();

	while (p.fi==0)
	{
		ronda(p);
		//turno(&p);
		finalizar_partida(&p);
	}


}
