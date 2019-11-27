#include <stdio.h>
#include "extres.h"
#include "carta.h"
#include "mazo.h"
#include "partida.h"

int main() {
	intro();
	printf("VAmo a ase la wea ");
	float mango;
	int wea;
	scanf("%d",&wea);
	mango=prova(wea);
	printf("La wea %d del mango %f",wea, mango);
}
