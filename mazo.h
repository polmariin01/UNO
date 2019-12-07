#define MAZO_H

int pos_tir(temazo mazo1, temazo mazo2);
void repartir_cartas(temazo *mazo1, temazo *mazo2);
void es_la_ultima(tjug *a);
void mostrar_mazo(temazo mazo);
void cambiar_carta(temazo mazo1, temazo mazo2, int pos);
temazo iniciar_cartas();
temazo mezclar_mazo(temazo mazo);

#endif

