#ifndef CARTA_H
#define CARTA_H


#include <stdio.h>
#include "carta.h"
#include "partida.h"

#define MAZO_H

temazo pos_tir(temazo mazo1, tcarta carta1);
void mostrar_mazo(temazo mazo);
void repartir_cartas(tpartida *partida);
void cambiar_carta(temazo mazo1, temazo mazo2, int pos);
temazo iniciar_cartas();
temazo mezclar_mazo(temazo mazo);

#endif

