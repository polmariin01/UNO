#ifndef MAZO_H
#define MAZO_H


#include <stdio.h>
#include "carta.h"
#include "partida.h"


temazo pos_tir(tpartida p);
void mostrar_mazo(temazo mazo);
void repartir_cartas(tpartida *partida);
void cambiar_carta(temazo *mazo1, temazo *mazo2, int pos); //punteros arreglats
temazo iniciar_cartas();
void mezclar_mazo(temazo *mazo);

#endif

