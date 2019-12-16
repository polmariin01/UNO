#include <stdio.h>
#include "carta.h"
#include "mazo.h"
#include "partida.h"
#include "colores.h"



int main() {
	tpartida p;

	p = inicio();

	mostrar_mazo(p.robar);
	while (p.fi==0)
	{
		//printf("La wea ronda");
		//ronda(p);
		//turno(&p);
		//finalizar_partida(&p);
	}


}
