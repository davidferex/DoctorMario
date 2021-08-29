#include "Ejercito.h"
#include "Rafaga.h"
#include "Enemigo.h"
#include "stdlib.h"
#include "Pantalla.h"
#include "Personaje.h"
#define ALTO_PANTALLA 640


struct EjercitoRep
{
    int NumEnemigos;
    int MaxEnemigos;
    Enemigo * ejercito;
    Imagen imagenCoronavirus;       //Cargo las 3 imágenes para poder tener los 3 tipos de "enemigos" usando el mismo TDA.
    Imagen imagenSeta;              //Se cargan aquí las imagenes para poder tener la "Imagen_compartida"
    Imagen imagenVacuna;
};


Ejercito crea_ejercito ( int max_enemigos )
{
    Ejercito nuevo = malloc(sizeof(struct EjercitoRep));
    nuevo->NumEnemigos = 0;
    nuevo->MaxEnemigos = max_enemigos;
    nuevo->ejercito = malloc (max_enemigos*sizeof(Enemigo)); //Para ejercito Dinamico, el tamaño del array depende de una variable.
    nuevo->imagenCoronavirus = Pantalla_ImagenLee("coronavirus.bmp", 255);
    nuevo->imagenSeta = Pantalla_ImagenLee("seta.bmp", 255);
    nuevo->imagenVacuna = Pantalla_ImagenLee("Vacuna.bmp", 255);
    return nuevo;
}

void libera_ejercito ( Ejercito e )
{
    for (int i=0; i<e->NumEnemigos; i=i+1)
    {
        libera_enemigo(e->ejercito[i]);     //Liberamos cada enemigo del array.
    }
    free(e->ejercito);                      //Liberamos el array.
    Pantalla_ImagenLibera(e->imagenCoronavirus);    //Liberamos las 3 imágenes.
    Pantalla_ImagenLibera(e->imagenSeta);
    Pantalla_ImagenLibera(e->imagenVacuna);
    free(e);                                    //Se libera la estructura en sí.
}

void inserta_enemigo ( Ejercito e, double x, double y, double vx, double vy, double w, double h, int v, int t )
{
    if (e->NumEnemigos < e->MaxEnemigos)  //Se inserta el enemigo con una imagen u otra según el tipo.
    {
        if (t == 1)
        {
            e->ejercito[e->NumEnemigos]=crea_enemigo(x, y, vx, vy, w, h, v, e->imagenCoronavirus, t);
        }
        if (t == 2)
        {
            e->ejercito[e->NumEnemigos]=crea_enemigo(x, y, vx, vy, w, h, v, e->imagenSeta, t);
        }
        if (t == 3)
        {
            e->ejercito[e->NumEnemigos]=crea_enemigo(x, y, vx, vy, w, h, v, e->imagenVacuna, t);
        }
        e->NumEnemigos = e->NumEnemigos + 1;
    }
}

void mueve_ejercito ( Ejercito e, Personaje p )
{
    int i = 0;
    while (i < e->NumEnemigos)
    {
        mueve_enemigo(e->ejercito[i], p);
        if (get_tipo_enemigo(e->ejercito[i]) == 3)      //Si es una vacuna, si se sale de la pantalla se libera. Los otros tipos, como uno persigue y otro rebota, no es necesario.
        {
            if (get_y_enemigo(e->ejercito[i]) + get_h_enemigo(e->ejercito[i])>ALTO_PANTALLA)
            {
                libera_enemigo(e->ejercito[i]);
                e->ejercito[i] = e->ejercito[e->NumEnemigos - 1];           //"Recolocamos" el array.
                e->NumEnemigos = e->NumEnemigos - 1;
            }
            else
            {
                i = i + 1;
            }
        }
        else
        {
            i = i + 1;
        }
    }
}

void dibuja_ejercito ( Ejercito e )
{
    for (int i=0; i<e->NumEnemigos; i=i+1)
    {
        dibuja_enemigo(e->ejercito[i]);
        if (get_tipo_enemigo(e->ejercito[i]) == 1)      //Si es un virus, se dibuja también sus vidas.
        {
            dibuja_vidas_enemigo(e->ejercito[i]);
        }
    }
}

int colision_ejercito_objeto ( Ejercito e, double x, double y, double w, double h )
{
    int i = 0;
    while ((i<e->NumEnemigos)&&!(colision_enemigo(e->ejercito[i], x, y, w, h)))
    {
        i = i+1;
    }
    if (i<e->NumEnemigos)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int colision_ejercito_rafaga ( Ejercito e, Rafaga r )
{
    int EnemigosElim = 0;
    int i = 0;
    while (i<e->NumEnemigos)
    {
        if (colision_rafaga(r, get_x_enemigo(e->ejercito[i]), get_y_enemigo(e->ejercito[i]), get_w_enemigo(e->ejercito[i]), get_h_enemigo(e->ejercito[i])))
        {
            resta_vidas_enemigo(e->ejercito[i], 1);
            if (get_vidas_enemigo (e->ejercito[i])<= 0)
            {
                libera_enemigo(e->ejercito[i]);
                EnemigosElim = EnemigosElim + 1;
                e->ejercito[i] = e->ejercito[e->NumEnemigos - 1];
                e->NumEnemigos = e->NumEnemigos - 1;
            }
            else
            {
                i = i + 1;
            }
        }
        else
        {
            i = i + 1;
        }
    }
    return EnemigosElim;
}


void ejercito_dispara ( Ejercito e, int numEnemigosDisparan, Rafaga r )
{
    int contador = 0;
    for (int i = 0; i<e->NumEnemigos; i = i + 1)
    {
        if (get_tipo_enemigo(e->ejercito[i]) == 1 && contador < numEnemigosDisparan)  //Solo disparan los virus.
        {
            enemigo_dispara (e->ejercito[i], r);
            contador = contador + 1;
        }
    }
}

int colision_ejercito_personaje ( Ejercito e, Personaje p )
{
    int ElementosAlcanzados = 0;
    int i = 0;
    while ((i<e->NumEnemigos))
    {
        //Cualquier enemigo que toque al personaje, se liberará.
        if (colision_enemigo(e->ejercito[i], get_x_personaje(p), get_y_personaje(p), get_w_personaje(p), get_h_personaje(p)))
        {
            if (get_tipo_enemigo(e->ejercito[i]) == 2 && get_x_enemigo(e->ejercito[i]) < (get_x_personaje(p) + get_w_personaje(p)) && get_x_personaje(p) < (get_x_enemigo(e->ejercito[i]) + get_w_enemigo(e->ejercito[i])) && (get_y_personaje(p) + get_h_personaje(p)) < (get_y_enemigo(e->ejercito[i]) + 15))
            {
                suma_puntos(p, 1);
                libera_enemigo(e->ejercito[i]);
                e->ejercito[i] = e->ejercito[e->NumEnemigos - 1];
                e->NumEnemigos = e->NumEnemigos - 1;
            }
            else
            {
                if (get_tipo_enemigo(e->ejercito[i]) != 3)
                {
                    personaje_activa_invulnerabilidad(p);
                }
                libera_enemigo(e->ejercito[i]);
                ElementosAlcanzados = ElementosAlcanzados + 1;
                e->ejercito[i] = e->ejercito[e->NumEnemigos - 1];
                e->NumEnemigos = e->NumEnemigos - 1;
            }

        }
        else
        {
            i = i + 1;
        }
    }
    return ElementosAlcanzados;
}
