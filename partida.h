
int cambio_turno(int turno, int jugadores, int sentido);
int jugadas(tcarta a, temazo b);
int incicio(tjug t, int comprobacion); //no se si el nom al ser un vector de 								caracters pot anar dins d'aquesta funcio//
int uno(int );

typedef struct
{
	int n;			//numero de cartas en el mazo
	tcarta mazo[MAXCART];	//cartas del mazo
} temazo;

typedef struct
{
	char nom[20];	//nombre jugador
	temazo c;	//mazo del jugador
} tjug;
