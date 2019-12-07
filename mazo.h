#define MAZO_H

temazo pos_tir(temazo mazo1, temazo mazo2);
void mostrar_mazo(temazo mazo);
void repartir_cartas(tpartida *partida);
void cambiar_carta(temazo mazo1, temazo mazo2, int pos);
temazo iniciar_cartas();
temazo mezclar_mazo(temazo mazo);

#endif

