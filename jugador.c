#include "jugador.h"
#include "escenario.h"

const int VEL_INICIAL=200;
const char* archivo_andando="textures/Sprites/Walk/walk.png";
const char* archivo_idle="textures/Sprites/Idle/idle.png";
Texture2D textura_andando;
Texture2D textura_idle;
Rectangle frames[6][8];
int filaFrame=0;
int colFrame=0;
int jugadorFPS=8;
float jugadorTiempo=0.0f;

Jugador JugadorCrear(Vector2 posicionInicial){
/*    //Cargo las texturas
    textura_andando=LoadTexture(archivo_andando);
    textura_parado=LoadTexture(archivo_parado);
    //Construyo array de fotogramas del personaje
    for(int i=0;i<6;i++){
        for(int j=0;j<8;j++){
            frames[i][j]=(Rectangle){
                j*JUGADOR_ANCHO_FRAME,
                i*JUGADOR_ALTO_FRAME,
                JUGADOR_ANCHO_FRAME,
                JUGADOR_ALTO_FRAME
            };
        }
    }
    //Intancio el jugador
    Prota nuevo={
        pos_ini,
        textura_parado,
        (Rectangle){0,0,48,64},
        (Rectangle){pos_ini.x+PROTA_X_HITBOX,pos_ini.y+PROTA_Y_HITBOX,PROTA_ANCHO_HITBOX,PROTA_ALTO_HITBOX},
        VEL_INICIAL,
        (Vector2){0,0}, // Direcci�n inicial
        (Vector2){0,0}, // Losa inicial
        PROTA_VIDA_MAX  // <--- IMPORTANTE: Inicializar la vida
    };
    return nuevo;*/
    Jugador j;
    j.posicion = posicionInicial;
    j.velocidad = VEL_INICIAL;
    j.vida = JUGADOR_VIDA_MAX;
    j.dir = (Vector2){0, 0};
    j.enMovimiento = false;

    // Calcular en qué casilla empieza
    j.casillaActual = (Vector2){
        floorf(posicionInicial.x / 32),
        floorf(posicionInicial.y / 32)
    };
    j.casillaDestino = j.casillaActual;

    return j;
}

void ActualizarJugador(Jugador* j,float delta){
    // Si está en movimiento, continuar deslizándose hacia el destino
    if(j->enMovimiento){
        // Calcular centro del destino
        Vector2 centroDestino = {
            j->casillaDestino.x * 32 + 16 - JUGADOR_ANCHO_HITBOX/2,
            j->casillaDestino.y * 32 + 16 - JUGADOR_ALTO_HITBOX/2
        };

        // Moverse hacia el centro del destino
        Vector2 direccion = {
            centroDestino.x - j->posicion.x,
            centroDestino.y - j->posicion.y
        };

        float distancia = sqrtf(direccion.x * direccion.x + direccion.y * direccion.y);

        // Si ya llegó al centro
        if(distancia < 2.0f){
            j->posicion = centroDestino;
            j->casillaActual = j->casillaDestino;
            j->enMovimiento = false;
            j->dir = (Vector2){0, 0};
        }
        else{
            // Normalizar y mover
            direccion.x /= distancia;
            direccion.y /= distancia;

            j->posicion.x += direccion.x * j->velocidad * delta;
            j->posicion.y += direccion.y * j->velocidad * delta;
        }
    }
    // Si no está en movimiento, puede aceptar input
    else{
        Vector2 input = {0, 0};

        // Detectar input (solo 4 direcciones)
        if(IsKeyDown(KEY_W)) input.y = -1;
        else if(IsKeyDown(KEY_S)) input.y = 1;
        else if(IsKeyDown(KEY_A)) input.x = -1;
        else if(IsKeyDown(KEY_D)) input.x = 1;

        // Si hay input, iniciar movimiento
        if(input.x != 0 || input.y != 0){
            // Calcular casilla destino
            Vector2 destino = {
                j->casillaActual.x + input.x,
                j->casillaActual.y + input.y
            };

            // Calcular el hitbox que tendría en el centro de la casilla destino
            Vector2 centroDestino = {
                destino.x * 32 + 16 - JUGADOR_ANCHO_HITBOX/2,
                destino.y * 32 + 16 - JUGADOR_ALTO_HITBOX/2
            };

            Rectangle hitboxDestino = {
                centroDestino.x,
                centroDestino.y,
                JUGADOR_ANCHO_HITBOX,
                JUGADOR_ALTO_HITBOX
            };

            // Solo moverse si la casilla destino es transitable
            if(UbicacionLibre(hitboxDestino)){
                j->dir = input;
                j->casillaDestino = destino;
                j->enMovimiento = true;
            }
        }
    }
}

void DibujarJugador(Jugador* j){
    DrawRectangle(j->posicion.x,j->posicion.y,JUGADOR_ANCHO_HITBOX,JUGADOR_ALTO_HITBOX, RED);
}
