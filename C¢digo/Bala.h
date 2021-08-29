#ifndef __Bala_H__
#define __Bala_H__
#include "Pantalla.h"

/**
    \file Bala.h
    \author David Fernández Expósito
    \brief Fichero cabecera para poder usar el TDA bala.
*/

/**
    \brief  TDA Bala.
*/
typedef struct BalaRep * Bala;

/**
    \brief Crea una bala con coordenadas (x,y), velocidades en el eje x y eje y de valor vx y vy respectivamente, y con una imagen para representarla gráficamente.
    \param x Coordenada horizontal de la bala.
    \param y Coordenada vertical de la bala.
    \param vx Velocidad horizontal de la bala.
    \param vy Velocidad vertical de la bala.
    \param imagenbala Imagen que se usará en caso de representar gráficamente la bala.
*/
Bala crea_bala (double x, double y, double vx, double vy, Imagen imagenbala);

/**
    \brief Libera la memoria asociada a la bala.
    \param b Bala que se quiere liberar.
*/
void libera_bala ( Bala b);

/**
    \brief Mueve la bala.
    \param b Bala que se quiere mover.
*/
void mueve_bala (Bala b);

/**
    \brief Dibuja la bala en pantalla.
    \param b Bala  que se quiere dibujar.
*/
void dibuja_bala (Bala b);

/**
    \brief Obtiene el valor de la coordenada x de la bala.
    \param b Bala de la que queremos obtener la coordenada x.
    \return Coordenada x de la bala.
*/
double get_x_bala (Bala b);

/**
    \brief Obtiene el valor de la coordenada y de la bala.
    \param b Bala de la que queremos obtener la coordenada y.
    \return Coordenada y de la bala.
*/
double get_y_bala (Bala b);

/**
    \brief Comprueba si la bala colisiona con un rectangulo de coordenadas (x,y), ancho w y alto h.
    \param b Bala a considerar.
    \param x Coordenada x del rectangulo.
    \param y Coordenada y del rectangulo.
    \param w Anchura del rectangulo.
    \param h Altura del rectangulo.
    \return 1 si colisiona, 0 en caso contrario.
*/
int	colision_bala (Bala	b,	double	x,	double	y,	double	w,	double	h);


#endif // __Bala_H__
