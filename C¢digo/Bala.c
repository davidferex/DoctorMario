#include "Bala.h"
#include "Pantalla.h"
#include "Colisiones.h"
#include <stdio.h>
#include <stdlib.h>
#define ANCHO_BALA 10
#define ALTO_BALA 10


struct  BalaRep
{
    double xbala;
    double ybala;
    double vybala;
    double vxbala;
    double anchobala;
    double altobala;
    Imagen imagenbala;
};

Bala crea_bala( double x, double y, double vx, double vy, Imagen imagenbala )
{
    Bala b= malloc(sizeof(struct BalaRep));
    b->xbala=x;
    b->ybala=y;
    b->vxbala=vx;
    b->vybala=vy;
    b->anchobala= ANCHO_BALA;
    b->altobala=ALTO_BALA;
    b->imagenbala= imagenbala;
    return b;
}

void libera_bala( Bala b )
{
    Pantalla_ImagenLibera(b->imagenbala);
    free(b);
}

void mueve_bala ( Bala b )
{
    b->xbala=(b->xbala)+(b->vxbala);
    b->ybala=(b->ybala)+(b->vybala);
}

void dibuja_bala ( Bala b )
{
    Pantalla_DibujaImagen (b->imagenbala, b->xbala, b->ybala, b->anchobala, b->altobala);
}

double get_x_bala ( Bala b )
{
    return b->xbala;
}

double get_y_bala ( Bala b )
{
    return b->ybala;
}

int	colision_bala(	Bala	b,	double	x,	double	y,	double	w,	double	h )
{
    if (solape_rectangulos(x, y, w, h, b->xbala, b->ybala, b->anchobala, b->altobala))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
