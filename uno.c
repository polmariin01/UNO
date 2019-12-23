/*
Gil Boleda 
Eudald Brils
Pol Marin

Grup 10
*/

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
	int i, a, f=0;
	srand(time(NULL));
	
	while (f==0) {
		espacio();
		intro();
		p = inicio();
		espacio();

		while (p.fi<0) {
			ronda(p);
			turno(&p);
			finalizar_partida(&p);
			espacio();
		}
		f = sanseacabo(p);
	}
	espacio();
	printf("Hecho por:\n\nGil Boleda\nEudald Brils\nPol Marin\n\nPress ENTER para salir...");
	scanf("%*c");
	espacio();
}
