#ifndef ESCENARIO_H_INCLUDED
#define ESCENARIO_H_INCLUDED

#include "raylib.h"
#include <stdbool.h>

#define ALTO_CASILLA 32
#define ANCHO_CASILLA 32
#define TERRENO_ANCHO 25
#define TERRENO_ALTO 14

// 0 = vacío/fuera, 1 = muro, 2 = suelo transitable
extern int TERRENO[TERRENO_ALTO][TERRENO_ANCHO];

void EscenarioIniciar();

// Comprueba si un rectángulo puede estar en esa posición (no colisiona con muros)
bool UbicacionLibre(Rectangle hitbox);

// Convertir posición en píxeles a coordenadas de casilla
Vector2 PixelesACasilla(Vector2 posicionPx);

// Convertir coordenadas de casilla a píxeles (esquina superior izquierda)
Vector2 CasillaAPixeles(Vector2 casilla);

// Obtener el centro de una casilla en píxeles
Vector2 CentroCasilla(Vector2 casilla);

void EscenarioDibujar();

#endif // ESCENARIO_H_INCLUDED
