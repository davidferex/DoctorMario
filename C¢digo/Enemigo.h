#ifndef __Enemigo_H__
#define __Enemigo_H__
#include "Rafaga.h"
#include "Personaje.h"

/**
    \file Enemigo.h
    \author David Fernández Expósito
    \brief Fichero cabecera para poder usar el TDA enemigo.
*/

/**
    \brief TDA Enemigo
*/
typedef struct EnemigoRep * Enemigo;

/**
    \brief Crea un enemigo con coordenadas (x,y), velocidad horizontal vx, velocidad vertical vy, anchura w, altura h, v vidas, representado en pantalla por imagen y del tipo t (1, 2 o 3).
    \param x Coordenada x del enemigo.
    \param y Coordenada y del enemigo.
    \param vx Velocidad horizontal del enemigo. Si el tipo es 2, para que el enemigo persoga al personaje la velocidad debe ser positiva.
    \param vy Velocidad vertical del enemigo.
    \param w Anchura del enemigo.
    \param h Altura del enemigo.
    \param v Vidas del enemigo.
    \param imagen Imagen que se usará en caso de representar gráficamente al enemigo.
    \param t Tipo del enemigo. Los tipos contemplados son 1 (virus), 2 (setas), 3 (vacunas).
*/
Enemigo crea_enemigo ( double x, double y, double vx, double vy, double w, double h, int v, Imagen imagen, int t );

/**
    \brief Libera la memoria asociada al enemigo e.
    \param e Enemigo al que se quiere liberar.
*/
void libera_enemigo ( Enemigo e );

/**
    \brief Dibuja en pantalla las vidas del enemigo e.
    \param e Enemigo del que se quiere dibujar las vidas.
*/
void dibuja_vidas_enemigo ( Enemigo e );

/**
    \brief Dibuja en pantalla al enemigo e.
    \param e Enemigo que se quiere dibujar.
*/
void dibuja_enemigo ( Enemigo e );

/**
    \brief Mueve al enemigo e.
    \param e Enemigo que se quiere mover.
    \param p Personaje al que perseguirá el enemigo si es del tipo 2.
*/
void mueve_enemigo ( Enemigo e, Personaje p );

/**
    \brief Recupera la coordenada horizontal del enemigo e.
    \param e Enemigo del que recuperar la coordenada horizontal.
    \return Coordenada horizontal del enemigo e.
*/
double get_x_enemigo ( Enemigo e );

/**
    \brief Recupera la coordenada vertical del enemigo e.
    \param e Enemigo del que recuperar la coordenada vertical.
    \return Coordenada vertical del enemigo.
*/
double get_y_enemigo ( Enemigo e );

/**
    \brief Recupera la anchura del enemigo e.
    \param e Enemigo del que recuperar la anchura.
    \return Anchura del enemigo.
*/
double get_w_enemigo ( Enemigo e );

/**
    \brief Recupera la altura del enemigo e.
    \param e Enemigo del que recuperar la altura.
    \return Altura del enemigo.
*/
double get_h_enemigo ( Enemigo e );

/**
    \brief Recupera las vidas del enemigo e.
    \param e Enemigo del que recuperar las vidas.
    \return Vidas del enemigo e.
*/
int get_vidas_enemigo ( Enemigo e );

/**
    \brief Recupera el tipo del enemigo e
    \param e Enemigo del que recuperar el tipo
    \return Tipo del enemigo e
*/
int get_tipo_enemigo ( Enemigo e );

/**
    \brief Comprueba si el enemigo e colisiona con el objeto de coordenadas (x,y), anchura w, altura h.
    \param e Enemigo que se quiere comprobar si colisiona.
    \param x Coordenada x del objeto.
    \param y Coordenada y del objeto.
    \param w Anchura del objeto.
    \param h Altura del objeto.
    \return 1 si colisionan, 0 en caso contrario.
*/
int colision_enemigo ( Enemigo e, double	x,	double	y,	double	w,	double	h );

/**
    \brief Resta al enemigo e tantas vidas como vidasrestadas.
    \param e Enemigo al que se le quieren restar las vidas.
    \param vidasrestadas Vidas que se quieren restar.
*/
void resta_vidas_enemigo ( Enemigo e, int vidasrestadas );

/**
    \brief Hace que el enemigo e dispare.
    \param e Enemigo que se quiere que dispare.
    \param r Ráfaga con las balas que disparará el enemigo e.
*/
void enemigo_dispara ( Enemigo e, Rafaga r );

#endif // __Enemigo_H__
