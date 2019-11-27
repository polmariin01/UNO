#include <stdio.h>
#include "carta.h"

void mostrar_carta(tcarta carta)
{
	cambiar_color_fondo(0);
	switch (carta.num)
	{
		case 10:
			cambiar_color_fondo(carta.color);
			printf(" R ");
			break;
		case 11:
			cambiar_color_fondo(carta.color);
			printf(" S ");
			break;
		case 12:
			cambiar_color_fondo(carta.color);
			printf("+2 ");
			break;
		case 13:
			printf(" W ");
			break;
		case 14:
			printf("W+4");
			break;
		default:
			cambiar_color_fondo(carta.color);
			printf(" %d ", carta.num);
			break;
	}
	cambiar_color_fondo(5);
}	

int comparar_carta(tcarta carta1, tcarta carta2);
{
  
}
