#ifndef __Rafaga_H__
#define __Rafaga_H__
#include "Bala.h"

/**
    \file Rafaga.h
    \author David Fern�ndez Exp�sito
    \brief Fichero cabecera para poder usar el TDA rafaga.
*/

/**
    \brief TDA R�faga
*/
typedef struct RafagaRep * Rafaga;

/**
    \brief Crea una r�faga vac�a.
*/
Rafaga crea_rafaga ();

/**
    \brief Inserta una bala a la r�faga.
    \param r R�faga en la que se inserta la bala.
    \param b Bala que se quiere insertar.
*/

void inserta_rafaga( Rafaga	r,	Bala b );

/**
    \brief Libera la memoria asociada a la r�faga.
    \param r R�faga que se quiere liberar.
*/
void libera_rafaga( Rafaga r );

/**
    \brief Mueve la r�faga.
    \param r R�faga que se quiere mover.
*/
void mueve_rafaga( Rafaga r );

/**
    \brief Dibuja la r�faga en pantalla
    \param r R�faga que se quiere dibujar
*/
void dibuja_rafaga( Rafaga r );

/**
    \brief Calcula la longitud de la r�faga.
    \param r R�faga a la que se quiere calcular la longitud.
    \return N�mero de balas de la r�faga.
*/
int longitud_rafaga ( Rafaga r );

/**
    \brief Comprueba si la r�faga se solapa con el rect�ngulo con esquina superior izquierda en (x,y), anchura w y altura h, y libera la primera bala que lo haga.
    \param r R�faga que se quiere comprobar si colisiona.
    \param x Coordenada x de la esquina superior izquierda del rect�ngulo.
    \param y Coordenada y de la esquina superior izquierda del rect�ngulo.
    \param w Anchura del rect�ngulo.
    \param h Altura del rect�ngulo.
    \return 1 si se solapan, 0 en caso contrario.
*/
int colision_rafaga( Rafaga	r,	double	x,	double	y,	double	w,	double	h );

#endif // __Rafaga_H__
