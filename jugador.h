#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "raylib.h"
#include "raymath.h"
#include <stdbool.h>
#include <stdio.h>

#define JUGADOR_ANCHO_FRAME 48
#define JUGADOR_ALTO_FRAME 64
#define JUGADOR_ANCHO_HITBOX 32
#define JUGADOR_ALTO_HITBOX 32
#define JUGADOR_X_HITBOX 18
#define JUGADOR_Y_HITBOX 20
#define JUGADOR_VIDA_MAX 100
#define JUGADOR_ALTO_BARRA_VIDA 3

typedef struct{
    Vector2 posicion;
    Texture2D textura;
    Rectangle region;
    Rectangle hitbox;
    int velocidad;
    Vector2 dir;
    Vector2 tile;
    int vida;
    Vector2 casillaActual;
    Vector2 casillaDestino;
    bool enMovimiento;
}Jugador;

Jugador JugadorCrear(Vector2);//posicion inicial

void ActualizarJugador(Jugador*,float);

void DibujarJugador(Jugador*);

#endif // JUGADOR_H_INCLUDED
