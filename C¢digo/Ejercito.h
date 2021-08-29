#ifndef __Ejercito_H__
#define __Ejercito_H__
#include "Rafaga.h"
#include "Pantalla.h"
#include "Personaje.h"

/**
    \file Ejercito.h
    \author David Fern�ndez Exp�sito
    \brief Fichero cabecera para poder usar el TDA ejercito.
*/

/**
    \brief TDA Ejercito.
*/
typedef struct EjercitoRep * Ejercito;

/**
    \brief Crea un ej�rcito del tama�o m�ximo que se indique.
    \param max_enemigos Tama�o m�ximo del ej�rcito.
*/
Ejercito crea_ejercito ( int max_enemigos );

/**
    \brief Libera la memoria asociada al ej�rcito.
    \param e Ej�rcito cuya memoria se desea liberar.
*/
void libera_ejercito ( Ejercito e );

/**
    \brief Inserta al ej�rcito un enemigo de coordenadas (x,y), velocidad horizontal vx, velocidad vertical vy, anchura w, altura h, v vidas y tipo t (1, 2 o 3).
    \param e Ej�rcito al que se le inserta el enemigo.
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
    \brief Mueve el ej�rcito.
    \param e Ej�rcito que se quiere mover.
    \param p Personaje al que perseguir�n los enemigos del segundo tipo del ej�rcito.
*/
void mueve_ejercito ( Ejercito e, Personaje p );

/**
    \brief Dibuja el ej�rcito en pantalla.
    \param e Ej�rcito a dibujar.
*/
void dibuja_ejercito ( Ejercito e );

/**
    \brief Comprueba si el ej�rcito colisiona con el objeto de coordenadas (x,y), anchura w y altura h.
    \param e Ej�rcito que se quiere comprobar si colisiona.
    \param x Coordenada x del objeto.
    \param y Coordenada y del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return 1 si se produce la colisi�n, 0 en caso contrario.
*/
int colision_ejercito_objeto ( Ejercito e, double x, double y, double w, double h );

/**
    \brief Comprueba si el ej�rcito colisiona con la r�faga r, resta vidas a los enemigos que lo hagan y libera a los enemigos que no tengan vidas.
    \param e Ej�rcito que se quiere comprobar si colisiona.
    \param r R�faga que se quiere comprobar si colisiona.
    \return Numero de enemigos que son eliminados por la rafaga.
*/
int colision_ejercito_rafaga ( Ejercito e, Rafaga r );

/**
    \brief Hace que tantos enemigos del ej�rcito como numEnemigosDisparan disparen.
    \param e Ej�rcito que se quiere que dispare.
    \param numEnemigosDisparan N�mero de enemigos del ej�rcito que disparar�n.
    \param r R�faga con las balas que disparar� el ej�rcito.
*/
void ejercito_dispara ( Ejercito e, int numEnemigosDisparan, Rafaga r );

/**
    \brief Comprueba si el ej�rcito colisiona con el personaje p.
    \param e Ej�rcito que se quiere comprobar si colisiona.
    \param p Personaje que se quiere comprobar si colisiona.
    \return Numero de enemigos que alcanzan al personaje (quitando a los enemigos del tipo 2 que son "chafados").
*/
int colision_ejercito_personaje ( Ejercito e, Personaje p );

#endif // __Ejercito_H__
