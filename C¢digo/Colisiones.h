#ifndef __Colisiones_H__
#define __Colesiones_H__

/**
    \file Colisiones.h
    \author David Fernández Expósito
    \brief Fichero cabecera para poder usar el módulo Colisiones.
*/

/**
    \brief Comprueba si un punto (px,py) está dentro de un rectángulo con esquina superior izquierda de coordenadas (x,y), anchura w y altura h.
    \param x Coordenada x de la coordenada superior izquierda del rectángulo.
    \param y Coordenada y de la coordenada superior izquierda del rectángulo.
    \param w Anchura del rectángulo.
    \param h Altura del rectángulo.
    \param px Coordenada x del punto.
    \param py Coordenada y del punto.
    \return 1 si el punto está dentro del rectángulo, 0 en caso contrario.
*/
int dentro_rectangulo ( int x, int y, int w, int h, int px, int py );

/**
    \brief Calcula la distancia entre dos puntos de coordenadas (x1,y1) y (x2,y2).
    \param x1 Coordenada x del primer punto.
    \param y1 Coordenada y del primer punto.
    \param x2 Coordenada x del segundo punto.
    \param y2 Coordenada y del segundo punto.
    \return Distancia euclídea entre los puntos.
*/
double distancia_punto_punto ( double x1, double y1, double x2, double y2 );

/**
    \brief Comprueba si una circunferencia de radio r1 y centro (x1,y1) se solapa con la de radio r2 y centro (x2,y2).
    \param x1 Coordenada x del centro de la primera circunferencia.
    \param y1 Coordenada y del centro de la primera circunferencia.
    \param r1 Radio de la primera circunferencia.
    \param x2 Coordenada x del centro de la segunda circunferencia.
    \param y2 Coordenada y del centro de la segunda circunferencia.
    \param r2 Radio de la segunda circunferencia.
    \return 1 si el solape se produce, 0 en caso contrario.
*/
int solape_circunferencias ( int x1, int y1, int r1, int x2, int y2, int r2 );

/**
    \brief Comprueba si el rectangulo con esquina superior izquierda de coordenadas (x1,y1), anchura w1 y altura h1, se solapa con el de coordenadas de su esquina superior izquierda (x2,y2), anchura w2 y altura h2.
    \param x1 Coordenada x de la coordenada superior izquierda del primer rectangulo.
    \param y1 Coordenada y de la coordenada superior izquierda del primer rectangulo.
    \param w1 Anchura del primer rectangulo.
    \param h1 Altura del primer rectangulo
    \param x2 Coordenada x de la coordenada superior izquierda del segundo rectangulo.
    \param y2 Coordenada y de la coordenada superior izquierda del segundo rectangulo.
    \param w2 Anchura del segundo rectangulo.
    \param h2 Altura del segundo rectangulo.
    \return 1 si el solape se produce, 0 en caso contrario.
*/
int solape_rectangulos ( int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2 );

#endif // __Colisiones_H__
