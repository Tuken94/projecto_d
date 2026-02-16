#include "escenario.h"
#include "raymath.h"
#include <stdlib.h>

// Mapa simple: 2 = suelo, 1 = muro, 0 = vac¡o
int TERRENO[TERRENO_ALTO][TERRENO_ANCHO] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void EscenarioIniciar(){
    // Por ahora nada que inicializar (sin texturas)
}

bool UbicacionLibre(Rectangle r){
    // Esquina superior izquierda
    int destinoX = (int)(r.x / ANCHO_CASILLA);
    int destinoY = (int)(r.y / ALTO_CASILLA);
    if(TERRENO[destinoY][destinoX] < 2) return false;

    // Esquina superior derecha (restamos 1 para no contar el borde siguiente)
    destinoX = (int)((r.x + r.width - 1) / ANCHO_CASILLA);
    if(TERRENO[destinoY][destinoX] < 2) return false;

    // Esquina inferior derecha
    destinoY = (int)((r.y + r.height - 1) / ALTO_CASILLA);
    if(TERRENO[destinoY][destinoX] < 2) return false;

    // Esquina inferior izquierda
    destinoX = (int)(r.x / ANCHO_CASILLA);
    if(TERRENO[destinoY][destinoX] < 2) return false;

    return true;
}

Vector2 PixelesACasilla(Vector2 posicionPx){
    return (Vector2){
        floorf(posicionPx.x / ANCHO_CASILLA),
        floorf(posicionPx.y / ALTO_CASILLA)
    };
}

Vector2 CasillaAPixeles(Vector2 casilla){
    return (Vector2){
        casilla.x * ANCHO_CASILLA,
        casilla.y * ALTO_CASILLA
    };
}

Vector2 CentroCasilla(Vector2 casilla){
    return (Vector2){
        casilla.x * ANCHO_CASILLA + ANCHO_CASILLA / 2.0f,
        casilla.y * ALTO_CASILLA + ALTO_CASILLA / 2.0f
    };
}

void EscenarioDibujar(){
    for (int i = 0; i < TERRENO_ALTO; i++){
        for (int j = 0; j < TERRENO_ANCHO; j++){
            int posX = j * ANCHO_CASILLA;
            int posY = i * ALTO_CASILLA;

             if(TERRENO[i][j] == 1){
                // Muro = negro
                DrawRectangle(posX, posY, ANCHO_CASILLA, ALTO_CASILLA, BLACK);
            }
            else if(TERRENO[i][j] == 2){
                // Suelo = blanco con borde negro
                DrawRectangle(posX, posY, ANCHO_CASILLA, ALTO_CASILLA, WHITE);
                DrawRectangleLines(posX, posY, ANCHO_CASILLA, ALTO_CASILLA, BLACK);
            }
        }
    }
}
