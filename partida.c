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
int jugadas(tcarta a, temazo b)
{
	for(i=0; i<b.mazo[MAXCART]; i++)
	{
		if (b.cartas.num==a.num || b.color== a.color)
		{ //preguntar al gil i acabar codi//
}
tpartida inicio()
{
	tpartida partida;
	
	i=0;
	do
	{
		printf ("Cuantos jugadores? [3-5]: ");
		scanf ("%d%*c", &partida.numjugs);	//ens falta nombrar la variable numjug=num 							jugadors als structs//
	}while (tjug.num>5);
	printf ("Tu nombre: ");
	do
	{		
		scanf ("%c", &tjug.nom[i]); 
		i++;			
	}while (tjug.nom!='\n');
int uno()				//La variable que ha d'entrar es la del resultat de la 						funcio del gil: es_la_ultima, si el resultat de la funcio 						del gil es !=0 no uno.
{
	if (es_la_ultima==1)
	{
		printf("UNO")
	}
}
						 
// ronda();
