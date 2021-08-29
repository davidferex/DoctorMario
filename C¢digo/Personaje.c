#include "Personaje.h"
#include "Pantalla.h"
#include "stdlib.h"
#include "Rafaga.h"
#include "Bala.h"
#define ALTO_PANTALLA 640
#define COORDENADA_Y_PERSONAJE (ALTO_PANTALLA-ALTO_PERSONAJE-(ALTO_PANTALLA/11))//58
#define ALTO_PERSONAJE (ALTO_PANTALLA/9)//70
#define VY_SALTO -20
#define VIDAS_PERSONAJE 5
#define DESPL_H_PERSONAJE 20
#define TIEMPO_INVULNERABILIDAD 30
#define VEL_BALA_PERSONAJE -25


struct PersonajeRep
{
    double x;
    double y;
    double w;
    double h;
    double vx;
    double vy;
    int vidas;
    int puntos;
    Imagen imagen;
    int contInvulnerabilidad;               //Añado un contador y una variable entera, que valdrá 0 o 1, para hacer la ampliación de la invulnerabilidad.
    int invulnerable;
};

Personaje crea_personaje ( double x, double y, double w, double h )
{
    Personaje nuevo = malloc(sizeof( struct PersonajeRep));
    nuevo->x = x;
    nuevo->y = y;
    nuevo->w = w;
    nuevo->h = h;
    nuevo->vx = DESPL_H_PERSONAJE;    //El desplazamiento horizontal es una constante y el vertical, que se usará para saltar, se inicializa a 0.
    nuevo->vy = 0;
    nuevo->vidas = VIDAS_PERSONAJE;               //Las vidas y los puntos se inicializan a 5 y 0 respectivamente.
    nuevo->puntos = 0;
    nuevo->imagen = Pantalla_ImagenLee("doctor mario.bmp", 1);
    nuevo->contInvulnerabilidad = 0;        //Ponemos la invulnerabilidad y el contador a 0 inicialmente.
    nuevo->invulnerable = 0;
    return nuevo;
}

void libera_personaje ( Personaje p )
{
    Pantalla_ImagenLibera(p->imagen);
    free (p);
}

void dibuja_personaje ( Personaje p )
{
    Pantalla_DibujaImagen(p->imagen, p->x, p->y, p->w, p->h);
}

void mueve_personaje ( Personaje p )
{
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT))  //Sumamos o restamos la vx dependiendo de la tecla
    {
        p->x = p->x + p->vx;
    }
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT))
    {
        p->x = p->x - p->vx;
    }
    if (p->invulnerable == 1)           //Se aprovecha que esta función se usa en cada iteración para actualizar la invulnerabilidad.
    {
        p->contInvulnerabilidad = p->contInvulnerabilidad + 1;
    }
    if (p->contInvulnerabilidad >= TIEMPO_INVULNERABILIDAD)
    {
        p->invulnerable = 0;
        p->contInvulnerabilidad = 0;
    }
}

void salta_personaje ( Personaje p )      //Inicializa la vy para el salto.
{
    if (p->vy == 0 && (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)))
    {
        p->vy = VY_SALTO;
    }
}

void mueve_personaje_salto ( Personaje p )    //Mueve al personaje durante el salto.
{
    if (p->y < COORDENADA_Y_PERSONAJE + ALTO_PERSONAJE)
    {
        p->y = p->y + p->vy;
        p->vy = p->vy + 3;      //Simula la gravedad.
    }
    if (p->y >= COORDENADA_Y_PERSONAJE )        //Recolocamos al personaje.
    {
        p->y = COORDENADA_Y_PERSONAJE;
        p->vy = 0;
    }
}

void suma_puntos ( Personaje p, int punt )
{
    p->puntos = p->puntos + punt;
}

void suma_vidas ( Personaje p, int v )
{
    p->vidas = p->vidas + v;
}

double get_x_personaje ( Personaje p )
{
    return p->x;
}

double get_y_personaje ( Personaje p )
{
    return p->y;
}

double get_w_personaje ( Personaje p )
{
    return p->w;
}

double get_h_personaje ( Personaje p )
{
    return p->h;
}

int get_vidas_personaje ( Personaje p )
{
    return p->vidas;
}

int get_puntos_personaje ( Personaje p )
{
    return p->puntos;
}

void personaje_dispara ( Personaje p, Rafaga r )
{
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE))
    {
        Imagen imagenbala = Pantalla_ImagenLee("bala.bmp", 255);
        inserta_rafaga(r, crea_bala(p->x+17, p->y, 0, VEL_BALA_PERSONAJE, imagenbala) ); //Insertamos una bala con la imagen leida en la rafaga deseada.
        //Ponemos la coordenada x del personaje + 17 para que salga más "centrada" la bala.
    }
}

void personaje_activa_invulnerabilidad ( Personaje p )
{
    p->invulnerable = 1;
}

int personaje_comprueba_invulnerabilidad ( Personaje p )
{
    return p->invulnerable == 1;
}


int colision_personaje_rafaga ( Personaje p, Rafaga r )
{
    if (colision_rafaga(r, p->x, p->y, p->w, p->h))
    {
        p->invulnerable = 1;
        return 1;
    }
    else
    {
        return 0;
    }
}
