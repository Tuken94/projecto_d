#include "jugador.h"

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
        (Vector2){0,0}, // Direcci¢n inicial
        (Vector2){0,0}, // Losa inicial
        PROTA_VIDA_MAX  // <--- IMPORTANTE: Inicializar la vida
    };
    return nuevo;*/
    Jugador j;
    j.posicion = posicionInicial;
    j.velocidad = VEL_INICIAL;
    j.vida = JUGADOR_VIDA_MAX;
    j.dir = (Vector2){0, 0};

    return j;
}

void ActualizarJugador(Jugador* j,float delta){
    Vector2 dir={0,0};
    // Detectar input horizontal (A y D se cancelan entre s¡)
    if(IsKeyDown(KEY_A)) dir.x--;
    if(IsKeyDown(KEY_D)) dir.x++;

    // Detectar input vertical (W y S se cancelan entre s¡)
    if(IsKeyDown(KEY_W)) dir.y--;
    if(IsKeyDown(KEY_S)) dir.y++;

    // Solo permitir movimiento en una direcci¢n (4 direcciones, sin diagonales)
    // Si hay input horizontal y vertical, cancelar ambos
    if(dir.x != 0 && dir.y != 0){
        dir.x = 0;
        dir.y = 0;
    }

    j->posicion.x += dir.x * j->velocidad * delta;
    j->posicion.y += dir.y * j->velocidad * delta;
}

void DibujarJugador(Jugador* j){
    DrawRectangle(j->posicion.x,j->posicion.y,JUGADOR_ANCHO_HITBOX,JUGADOR_ALTO_HITBOX, RED);
}
