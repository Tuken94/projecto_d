#ifndef ESCENARIO_H_INCLUDED
#define ESCENARIO_H_INCLUDED

#include "raylib.h"

#define ALTO_CASILLA 32
#define ANCHO_CASILLA 32

typedef struct{
    int anchoCasillas;  // Ancho en casillas
    int altoCasillas;   // Alto en casillas
    int anchoPx;        // Ancho en p¡xeles
    int altoPx;         // Alto en p¡xeles
    int* casillas;      // Array din mico [y * anchoCasillas + x]
}Escenario;

Escenario EscenarioCrear(int anchoVentana, int altoVentana);

void EscenarioLiberar(Escenario* esc);

// Obtener valor de una casilla
int ObtenerCasilla(Escenario* esc, int x, int y);

// Establecer valor de una casilla
void EstablecerCasilla(Escenario* esc, int x, int y, int valor);

// Convertir posici¢n en p¡xeles a coordenadas de casilla
Vector2 PixelesACasilla(Vector2 posicionPx);

// Convertir coordenadas de casilla a p¡xeles (esquina superior izquierda)
Vector2 CasillaAPixeles(Vector2 casilla);

// Obtener el centro de una casilla en p¡xeles
Vector2 CentroCasilla(Vector2 casilla);

void EscenarioDibujar();

#endif // ESCENARIO_H_INCLUDED
