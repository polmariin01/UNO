#define MAZO_H

typedef struct
{
	int col;
	char car;
} tcarta;

typedef struct
{
	int n;
	tcarta mazo[MAXCART];
} temazo;

typedef struct
{
	char nom[20];
	temazo c;
	int uno; //0 si no te uno, 1 si te uno//
} tjug;

typedef struct
{
	int color;
	int sentido; //0 horario, 1 antihorario//
	int comprobacion; //0 cubert, 1 descubert//
}tpartida;


int pos_tir(temazo mazo1, temazo mazo2);
void repartir_cartas(temazo *mazo1, temazo *mazo2);
void es_la_ultima(tjug *a);
void mostrar_mazo(temazo mazo);
void cambiar_carta(temazo mazo1, temazo mazo2, int pos);
temazo iniciar_cartas();
temazo mezclar_mazo(temazo mazo);

#endif

