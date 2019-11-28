#include "partida.h"

int cambio_turno(int turno, int jugadores, int sentido)
//Sentido=0-->horari, Sentido=1-->antihorari
{	
	if(sentido==0)
	{ 
		if (turno==jugadores)
		{
			turno=1;
		}
		else
		{
			turno++;
		}
	}	
	else 
	{
		if (turno==1)
		{
			turno=jugadores;
		}
		else
		{
			turno--;
		}
	}	
	return turno;
}

tpartida inicio()
{
	tpartida partida;
	
	i=0;
	do
	{
		printf ("Cuantos jugadores? [3-5]: ");
		scanf ("%d%*c", &partida.numjugs);	//ens falta nombrar la variable numjug=num 							jugadors als structs//
	} while (tjug.num>5);
	
	printf ("Tu nombre: ");
	
	do
	{		
		scanf ("%c", &tjug.nom[i]); 
		i++;			
	} while (tjug.nom!='\n');
}

// ronda();
// finalizar_partida();
