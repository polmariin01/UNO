#include <stdio.h>
#include <stdlib.h>
#include "carta.h"
#include "mazo.h"
#include "partida.h"
#include "colores.h"




void mostrar_carta(tcarta carta)
{
	cambiar_color_fondo(carta.col);
	switch (carta.num)
	{
		case 10:
			printf(" R ");
			break;
		case 11:
			printf(" S ");
			break;
		case 12:
			printf("+2 ");
			break;
		case 13:
			cambiar_color_letra(5);
			printf(" W ");
			break;
		case 14:
			cambiar_color_letra(5);
			printf("W+4");
			break;
		case -1:
			cambiar_color_letra(2);
			printf("UNO");
			break;
		default:
			printf(" %d ", carta.num);
			break;
	}
	default_attributes();
}





int comparar_carta(tcarta carta1, tpartida p)
{
	tcarta carta = p.descartes.mazo[p.descartes.n-1];
	//carta 1 es la de sobre, si la jugada es posible = 1 sino =0//
 int a=0;
	if((carta1.col==p.color)||(carta1.num==carta.num)||(carta1.num==13)) {
		a=1;
	}
	if (carta1.num==14) {
		a=2;
	}
	return(a);
}
