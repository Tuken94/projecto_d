#include "escenario.h"
#include "raymath.h"

Escenario EscenarioCrear(int anchoVentana, int altoVentana){
    Escenario escenario;

    escenario.anchoCasillas = anchoVentana / ANCHO_CASILLA;
    escenario.altoCasillas = altoVentana / ALTO_CASILLA;
    escenario.anchoPx = anchoVentana;
    escenario.altoPx = altoVentana;

    // Crear array din mico e inicializar todas las casillas a 0 (vac¡as)
    int totalCasillas = escenario.anchoCasillas * escenario.altoCasillas;
    escenario.casillas = (int*)malloc(totalCasillas * sizeof(int));

    for(int i = 0; i < totalCasillas; i++){
        escenario.casillas[i] = 0;
    }

    return escenario;
}

void EscenarioLiberar(Escenario* esc){
    if(esc->casillas != NULL){
        free(esc->casillas);
        esc->casillas = NULL;
    }
}

int ObtenerCasilla(Escenario* esc, int x, int y){
    if(x < 0 || x >= esc->anchoCasillas || y < 0 || y >= esc->altoCasillas){
        return -1; // Fuera de l¡mites
    }
    return esc->casillas[y * esc->anchoCasillas + x];
}

void EstablecerCasilla(Escenario* esc, int x, int y, int valor){
    if(x < 0 || x >= esc->anchoCasillas || y < 0 || y >= esc->altoCasillas){
        return; // Fuera de l¡mites
    }
    esc->casillas[y * esc->anchoCasillas + x] = valor;
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
    // Por ahora vac¡a, solo l¢gica
}
