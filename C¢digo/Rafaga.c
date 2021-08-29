#include "Rafaga.h"
#include "Bala.h"
#include "Pantalla.h"
#include <stdio.h>
#include <stdlib.h>
#define ANCHO_PANTALLA 1080
#define ALTO_PANTALLA 640

struct RafagaRep
{
    Bala BalaNodo;
    Rafaga sig;
};

Rafaga nuevo_nodo( Bala b )
{
    Rafaga nuevo = malloc(sizeof(struct RafagaRep));
    nuevo->BalaNodo = b;
    nuevo->sig = NULL;
    return nuevo;
};

Rafaga crea_rafaga ()
{
    Rafaga nuevo = nuevo_nodo(NULL);
    return nuevo;
}

void inserta_rafaga( Rafaga	r,	Bala b )
{
    Rafaga nuevo = nuevo_nodo(b);       //Se inserta un nodo en la lista por el principio, con la bala b.
    nuevo->sig = r->sig;
    r->sig = nuevo;
};

void libera_rafaga( Rafaga r )
{
    while (r->sig != NULL)
    {
        Rafaga borrar = r->sig;
        r->sig = borrar->sig;
        libera_bala(borrar->BalaNodo);      //Liberamos primero la bala. Luego el nodo.
        free (borrar);
    }
    free (r);
}

void mueve_rafaga( Rafaga r )
{
    Rafaga aux = r;
    while (aux->sig != NULL)
    {
        mueve_bala(aux->sig->BalaNodo);
        //Si la bala se sale de la pantalla, se libera.
        if ((get_y_bala(aux->sig->BalaNodo) <= 0)||(get_y_bala(aux->sig->BalaNodo) >= ALTO_PANTALLA)||(get_x_bala(aux->sig->BalaNodo) <= 0)||(get_x_bala(aux->sig->BalaNodo) >= ANCHO_PANTALLA))
        {
            Rafaga borrar = aux->sig;
            aux->sig = borrar->sig;
            libera_bala(borrar->BalaNodo);  //Se libera primero la bala, luego el nodo.
            free(borrar);
        }
        else
        {
            aux = aux->sig;
        }
    }
}

void dibuja_rafaga( Rafaga	r )
{
    Rafaga aux = r;
    while (aux->sig != NULL)
    {
        aux = aux->sig;
        dibuja_bala(aux->BalaNodo);
    }
}

int longitud_rafaga ( Rafaga r )
{
    Rafaga aux = r;
    int longitud = 0;
    while (aux->sig != NULL)
    {
        longitud = longitud + 1;
        aux = aux->sig;
    }
    return longitud;
}

int colision_rafaga( Rafaga	r,	double	x,	double	y,	double	w,	double	h )
{
    Rafaga aux = r;
    while ((aux->sig != NULL) && (colision_bala(aux->sig->BalaNodo, x, y , w , h)!= 1))
    {
        aux = aux->sig;
    }
    if (aux->sig != NULL)   //Significa que la bala del nodo siguiente colisiona.
    {
        Rafaga borrar = aux->sig;
        aux->sig = borrar->sig;
        libera_bala(borrar->BalaNodo);  //Liberamos primero la bala. Luego el nodo.
        free(borrar);
        return 1;
    }
    else
    {
        return 0;
    }
}
