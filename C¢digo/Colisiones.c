#include "Colisiones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dentro_rectangulo( int x, int y, int w, int h, int px, int py )
{
    if ((px <= x + w)&&(px >= x)&&(py >= y)&&(py <= y + h))     //Condición para que 1 punto esté dentro de un rectangulo.
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double distancia_punto_punto( double x1, double y1, double x2, double y2 )
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int solape_circunferencias( int x1, int y1, int r1, int x2, int y2, int r2 )
{
    return (distancia_punto_punto(x1, y1, x2, y2) < r1 + r2);
}

int solape_rectangulos( int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2 )
{
    if ((x1 > x2 + w2) || (x1 + w1 < x2) || (y2 + h2 < y1) || (y1 + h1 < y2))  //Condicion para que 2 rectángulos se solapen.
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
