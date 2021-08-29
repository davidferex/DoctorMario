#ifndef __Ejercito_H__
#define __Ejercito_H__
#include "Rafaga.h"
#include "Pantalla.h"
#include "Personaje.h"

/**
    \file Ejercito.h
    \author David Fernández Expósito
    \brief Fichero cabecera para poder usar el TDA ejercito.
*/

/**
    \brief TDA Ejercito.
*/
typedef struct EjercitoRep * Ejercito;

/**
    \brief Crea un ejército del tamaño máximo que se indique.
    \param max_enemigos Tamaño máximo del ejército.
*/
Ejercito crea_ejercito ( int max_enemigos );

/**
    \brief Libera la memoria asociada al ejército.
    \param e Ejército cuya memoria se desea liberar.
*/
void libera_ejercito ( Ejercito e );

/**
    \brief Inserta al ejército un enemigo de coordenadas (x,y), velocidad horizontal vx, velocidad vertical vy, anchura w, altura h, v vidas y tipo t (1, 2 o 3).
    \param e Ejército al que se le inserta el enemigo.
    \param x Coordenada x del enemigo a insertar.
    \param y Coordenada y del enemigo a insertar.
    \param vx Velocidad horizontal del enemigo a insertar.
    \param vy Velocidad vertical del enemigo a insertar.
    \param w Anchura del enemigo a insertar.
    \param h Altura del enemigo a insertar.
    \param v Vidas del enemigo a insertar.
    \param tipo Tipo del enemigo a insertar. Los tipos considerados son: 1 (virus), 2 (setas), 3 (vacunas).
*/
void inserta_enemigo ( Ejercito e, double x, double y, double vx, double vy, double w, double h, int v, int t );

/**
    \brief Mueve el ejército.
    \param e Ejército que se quiere mover.
    \param p Personaje al que perseguirán los enemigos del segundo tipo del ejército.
*/
void mueve_ejercito ( Ejercito e, Personaje p );

/**
    \brief Dibuja el ejército en pantalla.
    \param e Ejército a dibujar.
*/
void dibuja_ejercito ( Ejercito e );

/**
    \brief Comprueba si el ejército colisiona con el objeto de coordenadas (x,y), anchura w y altura h.
    \param e Ejército que se quiere comprobar si colisiona.
    \param x Coordenada x del objeto.
    \param y Coordenada y del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return 1 si se produce la colisión, 0 en caso contrario.
*/
int colision_ejercito_objeto ( Ejercito e, double x, double y, double w, double h );

/**
    \brief Comprueba si el ejército colisiona con la ráfaga r, resta vidas a los enemigos que lo hagan y libera a los enemigos que no tengan vidas.
    \param e Ejército que se quiere comprobar si colisiona.
    \param r Ráfaga que se quiere comprobar si colisiona.
    \return Numero de enemigos que son eliminados por la rafaga.
*/
int colision_ejercito_rafaga ( Ejercito e, Rafaga r );

/**
    \brief Hace que tantos enemigos del ejército como numEnemigosDisparan disparen.
    \param e Ejército que se quiere que dispare.
    \param numEnemigosDisparan Número de enemigos del ejército que dispararán.
    \param r Ráfaga con las balas que disparará el ejército.
*/
void ejercito_dispara ( Ejercito e, int numEnemigosDisparan, Rafaga r );

/**
    \brief Comprueba si el ejército colisiona con el personaje p.
    \param e Ejército que se quiere comprobar si colisiona.
    \param p Personaje que se quiere comprobar si colisiona.
    \return Numero de enemigos que alcanzan al personaje (quitando a los enemigos del tipo 2 que son "chafados").
*/
int colision_ejercito_personaje ( Ejercito e, Personaje p );

#endif // __Ejercito_H__
