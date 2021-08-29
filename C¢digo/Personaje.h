#ifndef __Personaje_H__
#define __Personaje_H__
#include "Rafaga.h"

/**
    \file Personaje.h
    \author David Fernández Expósito
    \brief Fichero cabecera para poder usar el TDA personaje.
*/

/**
    \brief TDA Personaje.
*/
typedef struct PersonajeRep * Personaje;

/**
    \brief Crea un personaje de coordenadas (x,y), anchura w y altura h.
    \param x Coordenada x del personaje.
    \param y Coordenada y del personaje.
    \param w Anchura del personaje.
    \param h Altura del personaje.
*/
Personaje crea_personaje ( double x, double y, double w, double h );

/**
    \brief Libera la memoria asociada al personaje p.
    \param p Personaje al que se quiere liberar.
*/
void libera_personaje ( Personaje p );

/**
    \brief Dibuja al personaje p en pantalla.
    \param p Personaje que se quiera dibujar.
*/
void dibuja_personaje ( Personaje p );

/**
    \brief Mueve al personaje p.
    \param p Personaje al que se quiera mover.
*/
void mueve_personaje ( Personaje p );

/**
    \brief Hace que el personaje p salte.
    \param p Personaje que se quiera que salte.
*/
void salta_personaje ( Personaje p );

/**
    \brief Mueve al personaje p durante el salto. Si el personaje no ha saltado no hace nada.
    \param p Personaje que se quiere mover durante el salto.
*/
void mueve_personaje_salto ( Personaje p );

/**
    \brief Suma al personaje p tantos puntos como punt.
    \param p Personaje al que se le quiera sumar los puntos.
    \param punt Puntos a sumar al personaje.
*/
void suma_puntos ( Personaje p, int punt );

/**
    \brief Suma al personaje p tantas vidas como v.
    \param p Personaje al que se le quiera sumar las vidas.
    \param v Vidas a sumar al personaje.
*/
void suma_vidas ( Personaje p, int v );

/**
    \brief Recupera la coordenada x del personaje p.
    \param p Personaje del que recuperar la coordenada x.
    \return Coordenada x del personaje p.
*/
double get_x_personaje ( Personaje p );

/**
    \brief Recupera la coordenada y del personaje p.
    \param p Personaje del que recuperar la coordenada y.
    \return Coordenada y del personaje p.
*/
double get_y_personaje ( Personaje p );

/**
    \brief Recupera el ancho del personaje p.
    \param p Personaje del que recuperar el ancho.
    \return Ancho del personaje p.
*/
double get_w_personaje ( Personaje p );

/**
    \brief Recupera la altura del personaje p.
    \param p Personaje del que recuperar la altura.
    \return Altura del personaje p.
*/
double get_h_personaje ( Personaje p );

/**
    \brief Recupera las vidas del personaje p.
    \param p Personaje del que recuperar las vidas.
    \return Vidas del personaje p.
*/
int get_vidas_personaje ( Personaje p );

/**
    \brief Recupera los puntos del personaje p.
    \param p Personaje del que recuperar los puntos.
    \return Puntos del personaje p.
*/
int get_puntos_personaje ( Personaje p );

/**
    \brief Hace que el personaje p dispare.
    \param p Personaje que disparará.
    \param r Ráfaga con las balas que disparará el personaje.
*/
void personaje_dispara ( Personaje p, Rafaga r );

/**
    \brief Activa la invulnerabilidad del personaje p durante un determinado tiempo.
    \param p Personaje al que se quiera hacer invulnerable.
*/
void personaje_activa_invulnerabilidad ( Personaje p );

/**
    \brief Comprueba si el personaje p es invulnerable.
    \param p Personaje del que se quiera saber si es invulnerable.
    \return 1 si es invulnerable, 0 en caso contrario.
*/
int personaje_comprueba_invulnerabilidad ( Personaje p );

/**
    \brief Comprueba si el personaje p colisiona con la ráfaga r.
    \param p Personaje que se quiere comprobar si colisiona.
    \param r Ráfaga que se quiere comprobar que colisiona.
    \return 1 si colisionan, 0 en caso contrario.
*/
int colision_personaje_rafaga ( Personaje p, Rafaga r );

#endif // __Personaje_H__
