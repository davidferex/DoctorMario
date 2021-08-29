#include "Enemigo.h"
#include "Pantalla.h"
#include "Colisiones.h"
#include "stdlib.h"
#include "stdio.h"
#include "Rafaga.h"
#include "Bala.h"
#include "Personaje.h"
#define ANCHO_PANTALLA 1080


struct EnemigoRep
{
    double x;
    double y;
    double vx;
    double vy;
    double ancho;
    double alto;
    int vidas;
    Imagen imagen;
    int tipo;       //Tipo 1: virus; Tipo 2: seta; Tipo 3: vacuna.
};

Enemigo crea_enemigo( double x, double y, double vx, double vy, double w, double h, int v, Imagen imagen, int t )
{
    Enemigo nuevo = malloc(sizeof(struct EnemigoRep));
    nuevo->x = x;
    nuevo->y = y;
    nuevo->vx = vx;
    nuevo->vy = vy;
    nuevo->ancho = w;
    nuevo->alto = h;
    nuevo->vidas = v;
    nuevo->imagen = imagen;
    nuevo->tipo = t;
    return nuevo;
}

void libera_enemigo ( Enemigo e )
{
    free(e);
}


void dibuja_vidas_enemigo ( Enemigo e )
{
    char * vidasenemigo = malloc (sizeof (char) + 1);
    sprintf (vidasenemigo, "%d", e->vidas);
    Pantalla_DibujaTexto(vidasenemigo, e->x, e->y);
    free (vidasenemigo);
}

void dibuja_enemigo ( Enemigo e )
{
    Pantalla_DibujaImagen(e->imagen, e->x, e->y, e->ancho, e->alto);
}


void mueve_enemigo ( Enemigo e, Personaje p )
{
    //Cada tipo de enemigo se mueve distinto.
    if (e->tipo == 1)
    {
        e->x = e->x + e->vx;
        e->y = e->y + e->vy;
        //Hacemos que rebote:
        if (e->x < 0)
        {
            e->vx = -1*e->vx;
        }
        if (e->x > ANCHO_PANTALLA-e->ancho)
        {
            e->vx = -1*e->vx;
        }
    }
    if (e->tipo == 2)
    {
        if (get_y_personaje(p) - 10 > e->y) //El 10 es simplemente para dar "un margen" al personaje para escapar.
        {
            e->y = e->y + e->vy;
        }
        if (get_y_personaje(p) + 10 < e->y)
        {
            e->y = e->y - e->vy;
        }
        if (get_x_personaje(p) - 10 > e->x) //El 10 es simplemente para dar "un margen" al personaje para escapar.
        {
            e->x = e->x + e->vx;
        }
        if (get_x_personaje(p) + 10 < e->x)
        {
            e->x = e->x - e->vx;
        }
    }
    if (e->tipo == 3)
    {
        e->x = e->x + e->vx;
        e->y = e->y + e->vy;
    }
}

double get_x_enemigo ( Enemigo e )
{
    return e->x;
}

double get_y_enemigo ( Enemigo e )
{
    return e->y;
}

double get_w_enemigo ( Enemigo e )
{
    return e->ancho;
}

double get_h_enemigo ( Enemigo e )
{
    return e->alto;
}

int get_vidas_enemigo ( Enemigo e )
{
    return e->vidas;
}

int get_tipo_enemigo ( Enemigo e )
{
    return e->tipo;
}

int colision_enemigo ( Enemigo e, double x,	double	y,	double	w,	double	h )
{
    if (solape_rectangulos(x, y, w, h, e->x, e->y, e->ancho, e->alto))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void resta_vidas_enemigo ( Enemigo e, int vidasrestadas )
{
    e->vidas = e->vidas - vidasrestadas;
}

void enemigo_dispara ( Enemigo e, Rafaga r )
{
    Imagen imagenbala = Pantalla_ImagenLee("bullet.bmp", 255);
    inserta_rafaga(r, crea_bala(e->x + 30, e->y, 0, 20, imagenbala)); //Insertamos la bala con la imagen cargada en la ráfaga deseada.
    //Ponemmos la x + 30 para que salgan un poco más centradas las balas.
}
