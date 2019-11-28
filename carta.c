#include<stdio.h>
#include "carta.h"

void mostrar_carta(tcarta carta)
{
	cambiar_color_fondo(carta.color);
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
			printf(" W ");
			break;
		case 14:
			printf("W+4");
			break;
		default:
			printf(" %d ", carta.num);
			break;
	}
	cambiar_color_fondo(5);
}	

int comparar_carta(tcarta carta1; tcarta carta2);
{
	//carta 1 es la de sobre, si la jugada es posible = 1 sino =0//
	int a=0;
	if((carta1.color==carta2.color)||(carta1.num==carta2.num)||(carta2.num>=13))
		a=1;
	return(a);
}




