#ifndef __Rafaga_H__
#define __Rafaga_H__
#include "Bala.h"

/**
    \file Rafaga.h
    \author David Fernández Expósito
    \brief Fichero cabecera para poder usar el TDA rafaga.
*/

/**
    \brief TDA Ráfaga
*/
typedef struct RafagaRep * Rafaga;

/**
    \brief Crea una ráfaga vacía.
*/
Rafaga crea_rafaga ();

/**
    \brief Inserta una bala a la ráfaga.
    \param r Ráfaga en la que se inserta la bala.
    \param b Bala que se quiere insertar.
*/

void inserta_rafaga( Rafaga	r,	Bala b );

/**
    \brief Libera la memoria asociada a la ráfaga.
    \param r Ráfaga que se quiere liberar.
*/
void libera_rafaga( Rafaga r );

/**
    \brief Mueve la ráfaga.
    \param r Ráfaga que se quiere mover.
*/
void mueve_rafaga( Rafaga r );

/**
    \brief Dibuja la ráfaga en pantalla
    \param r Ráfaga que se quiere dibujar
*/
void dibuja_rafaga( Rafaga r );

/**
    \brief Calcula la longitud de la ráfaga.
    \param r Ráfaga a la que se quiere calcular la longitud.
    \return Número de balas de la ráfaga.
*/
int longitud_rafaga ( Rafaga r );

/**
    \brief Comprueba si la ráfaga se solapa con el rectángulo con esquina superior izquierda en (x,y), anchura w y altura h, y libera la primera bala que lo haga.
    \param r Ráfaga que se quiere comprobar si colisiona.
    \param x Coordenada x de la esquina superior izquierda del rectángulo.
    \param y Coordenada y de la esquina superior izquierda del rectángulo.
    \param w Anchura del rectángulo.
    \param h Altura del rectángulo.
    \return 1 si se solapan, 0 en caso contrario.
*/
int colision_rafaga( Rafaga	r,	double	x,	double	y,	double	w,	double	h );

#endif // __Rafaga_H__
