#include "Pantalla.h"
#include <stdio.h>
#include <stdlib.h>
#include "Colisiones.h"
#include "Bala.h"
#include "Rafaga.h"
#include "Enemigo.h"
#include "Ejercito.h"
#include "Personaje.h"
#define ANCHO_ENEMIGO_TIPO_1 (ANCHO_PANTALLA/13) //80
#define ALTO_ENEMIGO_TIPO_1 (ALTO_PANTALLA/13) //50
#define ANCHO_PERSONAJE (ANCHO_PANTALLA/21) //50
#define ALTO_PERSONAJE (ALTO_PANTALLA/9)//70
#define COORDENADA_X_PERSONAJE (ANCHO_PANTALLA/2)//500
#define COORDENADA_Y_PERSONAJE (ALTO_PANTALLA-ALTO_PERSONAJE-(ALTO_PANTALLA/11))//58
#define ANCHO_VACUNAS (ANCHO_PANTALLA/27)//40
#define ALTO_VACUNAS (ALTO_PANTALLA/9)//70
#define ANCHO_ENEMIGO_TIPO_2 (ANCHO_PANTALLA/27)//40
#define ALTO_ENEMIGO_TIPO_2 (ALTO_PANTALLA/16)//40
#define ANCHO_PANTALLA 1080
#define ALTO_PANTALLA 640
#define MAX_ENEMIGOS 100
#define MAX_VACUNAS 10
#define VX_ENEMIGOS_TIPO_1 5
#define VY_ENEMIGOS_TIPO_1 0
#define VX_VACUNAS 0
#define VY_VACUNAS 5
#define VX_ENEMIGO_TIPO_2 5
#define VY_ENEMIGO_TIPO_2 0
#define VIDAS_TIPO_2 1
#define VIDAS_TIPO_3 1

/**
    \mainpage main
    Descripción general de la aplicación: esto es un juego interactivo que hace uso de la biblioteca Pantalla para representar gráficamente sus elementos.
    El objetivo del juego es que Mario obtenga el mayor número de puntos eliminando a los enemigos y sin perder sus vidas, pues si se agotan se acabará la partida.
*/

/**
    \file main.c
    \author David Fernández Expósito
*/

/**
    \brief Muestra el menú principal del juego, en el que el jugador puede elegir, haciendo uso del ratón, tres opciones: jugar una partida, mostrar la ayuda o salir.
    \return 1 si el jugador selecciona la opción de jugar, 2 si selecciona la ayuda o 3 si desea salir.
*/
int menu ()
{
    Imagen fondo = Pantalla_ImagenLee("menu.bmp",255);
    char jugar [] = "Jugar";
    char ayuda [] = "Ayuda";
    char salir [] = "Salir";
    char * textorecord = malloc (55*sizeof(char) + 1);
    int record;
    FILE * recordheroe = NULL;
    double xraton = 0;
    double yraton = 0;
    int fin = 0;
    recordheroe = fopen("Records1.txt", "r");
    if (recordheroe == NULL)
    {
        printf("Error al abrir fichero");
        return 1;
    }
    int res1 = fscanf (recordheroe, "%d", &record);
    if (res1!= 1)
    {
        printf("Error al leer dato de fichero");
        return 1;
    }
    fclose(recordheroe);
    sprintf(textorecord, "El record actual de puntuacion es de %d puntos.", record);
    while (Pantalla_Activa() && !fin)
    {
        Pantalla_DibujaImagen(fondo, 0, 0, ANCHO_PANTALLA, ALTO_PANTALLA);
        Pantalla_ColorTrazo (0, 0, 0, 255);
        Pantalla_ColorRelleno (0, 0, 0, 0);
        //Dibujamos 3 rectángulos con las 3 opciones a elegir en el menú.
        Pantalla_DibujaTexto(jugar, 510, 220);
        Pantalla_DibujaTexto(ayuda, 510, 320);
        Pantalla_DibujaTexto(salir, 510, 420);
        Pantalla_DibujaTexto(textorecord, 350, 500);
        Pantalla_DibujaRectangulo (500, 210, 60, 40);
        Pantalla_DibujaRectangulo (500, 310, 60, 40);
        Pantalla_DibujaRectangulo (500, 410, 60, 40);
        Pantalla_RatonCoordenadas (&xraton, &yraton);
        //Dependiendo de la posición del ratón, se "pondrá" rojo una opción u otra, o ninguna
        if (dentro_rectangulo (500, 210, 60, 40, xraton, yraton))
        {
            Pantalla_ColorTrazo (255, 0, 0, 255);
            Pantalla_DibujaRectangulo (500, 210, 60, 40);
            Pantalla_DibujaTexto(jugar, 510, 220);
            if (Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT))
            {
                fin = 1; //La función devolverá un código dependiendo de la opción elegida.
            }
        }
        if (dentro_rectangulo (500, 310, 60, 40, xraton, yraton))
        {
            Pantalla_ColorTrazo (255, 0, 0, 255);
            Pantalla_DibujaRectangulo (500, 310, 60, 40);
            Pantalla_DibujaTexto(ayuda, 510, 320);
            if (Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT))
            {
                fin = 2;
            }
        }
        if (dentro_rectangulo (500, 410, 60, 40, xraton, yraton))
        {
            Pantalla_ColorTrazo (255, 0, 0, 255);
            Pantalla_DibujaRectangulo (500, 410, 60, 40);
            Pantalla_DibujaTexto(salir, 510, 420);
            if (Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT))
            {
                fin = 3;
            }
        }
        Pantalla_Actualiza();

    }
    free(textorecord);
    Pantalla_ImagenLibera(fondo);
    return fin;
}

/**
    \brief Muestra la ayuda del juego, en la que se explica en qué consiste el mismo y los controles para poder jugar.
    \return 4 si el jugador desea salir de la ayuda.
*/
int ayuda ()
{
    Imagen imagenayuda = Pantalla_ImagenLee ("ayuda.bmp", 255);
    char salir[] = "SALIR";
    double xraton = 0;
    double yraton = 0;
    int fin = 0;
    while (Pantalla_Activa() && !fin)
    {
        Pantalla_DibujaImagen (imagenayuda, 0, 0, ANCHO_PANTALLA, ALTO_PANTALLA);
        Pantalla_ColorTrazo (0, 0, 0, 255);
        Pantalla_ColorRelleno (0, 0, 0, 0);
        //Dibujamos el rectangulo con la opción SALIR.
        Pantalla_DibujaTexto (salir, 510, 580);
        Pantalla_DibujaRectangulo (500, 570, 60, 40);
        Pantalla_RatonCoordenadas (&xraton, &yraton);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_X))
        {
            fin = 4;
        }
        if (dentro_rectangulo(500, 570, 60, 40, xraton, yraton))
        {
            Pantalla_ColorTrazo(255, 0, 0, 255);
            Pantalla_DibujaRectangulo(500, 570, 60, 40);
            Pantalla_DibujaTexto (salir, 510, 580);
            if (Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT))
            {
                fin = 4;
            }
        }
        Pantalla_Actualiza();
    }
    Pantalla_ImagenLibera(imagenayuda);
    return fin;
}

/**
    \brief Ejecuta una partida del juego.
    \return 4 si se sale o se acaba la partida.
*/
int jugar_partida()
{
    Pantalla_ColorTrazo(0,0,0, 255);
    Rafaga RafagaBalasHeroe1 = crea_rafaga();
    Rafaga RafagaBalasEnemigos = crea_rafaga();
    Imagen GameOver = Pantalla_ImagenLee ("game over.bmp", 0);
    int RecordPuntosHeroe1;
    FILE * recordheroe1 = NULL;
    int NumIteraciones = 0;
    int vidasvirus = 1;         //Vidas del tipo 1 de enemigos, que irán aumentando según aumenta la puntuación.
    char * textovidasheroe = malloc (15*sizeof (char) + 1);
    char * textopuntos = malloc (16*sizeof (char) + 1);
    char * textoGameOver = malloc (35*sizeof (char) + 1);
    char * textoRecord = malloc (80*sizeof (char) + 1);
    char textoMarioInvulnerable[] = "MARIO es INVULNERABLE";
    Personaje Mario = crea_personaje(COORDENADA_X_PERSONAJE, COORDENADA_Y_PERSONAJE, ANCHO_PERSONAJE, ALTO_PERSONAJE);
    Ejercito enemigos = crea_ejercito(MAX_ENEMIGOS);
    Ejercito vacunas = crea_ejercito(MAX_VACUNAS);
    //Insertamos dos enemigos de inicio.
    inserta_enemigo(enemigos, 10, 100, VX_ENEMIGOS_TIPO_1, VY_ENEMIGOS_TIPO_1, ANCHO_ENEMIGO_TIPO_1, ALTO_ENEMIGO_TIPO_1, vidasvirus, 1);
    inserta_enemigo(enemigos, 500, 100, VX_ENEMIGOS_TIPO_1, VY_ENEMIGOS_TIPO_1, ANCHO_ENEMIGO_TIPO_1, ALTO_ENEMIGO_TIPO_1, vidasvirus, 1);
    int terminado = 0;
    int RitmoAparicionEnemigo = 40;
    int RitmoDisparoEnemigo = 50;
    int NumeroDisparosEnemigos = 1;
    int insertarVacunasySetas = 1;   //Usamos esta variable para, cuando queramos añadir una vacuna o seta a los 10 puntos, solo se haga una vez, porque la partida puede estar con 10 puntos indefinidamente.
    Imagen fondo = Pantalla_ImagenLee("fondo.bmp",0);
    recordheroe1 = fopen("Records1.txt", "r");
    if (recordheroe1 == NULL)
    {
        printf("Error al abrir fichero");
        return 1;
    }
    int res1 = fscanf (recordheroe1, "%d", &RecordPuntosHeroe1);
    if (res1!= 1)
    {
        printf("Error al leer dato de fichero");
        return 1;
    }
    fclose(recordheroe1);
    //Bucle principal:
    while ( Pantalla_Activa() && !terminado && get_vidas_personaje(Mario)>0)
    {
        mueve_personaje(Mario);
        salta_personaje(Mario);
        mueve_personaje_salto(Mario);
        personaje_dispara(Mario, RafagaBalasHeroe1);
        if (NumIteraciones % RitmoAparicionEnemigo == 0)    //añadimos los enemigos cada cierto numero de iteraciones.
        {
            inserta_enemigo(enemigos, rand() % (ANCHO_PANTALLA-ANCHO_ENEMIGO_TIPO_1), rand() % (ALTO_PANTALLA-ALTO_PERSONAJE-150), VX_ENEMIGOS_TIPO_1, VY_ENEMIGOS_TIPO_1, ANCHO_ENEMIGO_TIPO_1, ALTO_ENEMIGO_TIPO_1, vidasvirus, 1);
        }
        if (NumIteraciones % RitmoDisparoEnemigo == 0)  //los enemigos disparan cada ciertas iteraciones
        {
            ejercito_dispara(enemigos, NumeroDisparosEnemigos, RafagaBalasEnemigos);
        }
        //Cada 10 puntos aparece una seta y una vacuna, y se actualizan los ritmos.
        if (get_puntos_personaje(Mario) % 10 == 0 && get_puntos_personaje(Mario) != 0 && insertarVacunasySetas == 1)
        {
            inserta_enemigo(vacunas, rand() % (ANCHO_PANTALLA - ANCHO_VACUNAS), 0, VX_VACUNAS, VY_VACUNAS, ANCHO_VACUNAS, ALTO_VACUNAS, VIDAS_TIPO_3, 3);
            inserta_enemigo(enemigos, 0, ALTO_PANTALLA-ALTO_ENEMIGO_TIPO_2-55, VX_ENEMIGO_TIPO_2, 0, ANCHO_ENEMIGO_TIPO_2, ALTO_ENEMIGO_TIPO_2, VIDAS_TIPO_2, 2);
            insertarVacunasySetas = 0;
            if (RitmoAparicionEnemigo > 20)     //Se reduce el tiempo entre apariciones de enemigos.
            {
                RitmoAparicionEnemigo = RitmoAparicionEnemigo - 5;
            }
            if (RitmoDisparoEnemigo > 20)       //Se reduce el tiempo entre disparos de enemigos.
            {
                RitmoDisparoEnemigo = RitmoDisparoEnemigo - 5;
            }
            if (NumeroDisparosEnemigos < 5)        //Aumenta el número de enemigos que disparan.
            {
                NumeroDisparosEnemigos = NumeroDisparosEnemigos + 1;
            }
            if (vidasvirus < 4)
            {
                vidasvirus = vidasvirus + 1;
            }
        }
        mueve_rafaga(RafagaBalasEnemigos);
        mueve_rafaga(RafagaBalasHeroe1);
        mueve_ejercito(enemigos, Mario);
        mueve_ejercito(vacunas, NULL);
        suma_puntos(Mario, colision_ejercito_rafaga (enemigos, RafagaBalasHeroe1));
        if ( !personaje_comprueba_invulnerabilidad(Mario) && colision_personaje_rafaga(Mario, RafagaBalasEnemigos))
        {
            suma_vidas(Mario, -1);
        }
        if (!personaje_comprueba_invulnerabilidad(Mario) && colision_ejercito_objeto(enemigos, get_x_personaje(Mario),get_y_personaje(Mario),get_w_personaje(Mario),get_h_personaje(Mario) ))
        {
            suma_vidas(Mario, -colision_ejercito_personaje(enemigos, Mario));
        }
        suma_vidas(Mario, colision_ejercito_personaje(vacunas, Mario));
        if (get_puntos_personaje(Mario) % 10 != 0)
        {
            insertarVacunasySetas = 1;
        }
        Pantalla_DibujaImagen(fondo, 0, 0, ANCHO_PANTALLA, ALTO_PANTALLA);
        //Si el personaje no es invulnerable, dibujamos normal.
        if (!personaje_comprueba_invulnerabilidad(Mario))
        {
            dibuja_personaje(Mario);
        }
        //Si el personaje es invulnerable, dibujamos cada 3 iteraciones para que parpadee.
        if (personaje_comprueba_invulnerabilidad(Mario) && NumIteraciones % 3 == 0)
        {
            dibuja_personaje(Mario);
        }

        dibuja_ejercito(enemigos);
        dibuja_rafaga(RafagaBalasHeroe1);
        dibuja_rafaga(RafagaBalasEnemigos);
        dibuja_ejercito(vacunas);
        //Preparamos las cadenas con los puntos y las vidas.
        sprintf(textovidasheroe, "VIDAS: %d VIDAS", get_vidas_personaje(Mario));
        Pantalla_DibujaTexto (textovidasheroe, 900, 20);
        sprintf(textopuntos, "SCORE: %d PUNTOS", get_puntos_personaje(Mario));
        Pantalla_DibujaTexto (textopuntos, 900, 40);
        if (personaje_comprueba_invulnerabilidad(Mario))
        {
            Pantalla_DibujaTexto (textoMarioInvulnerable, 200, 20);
        }
        if (get_vidas_personaje(Mario) == 0)
        {
            sprintf(textoGameOver, "Has conseguido %d puntos", get_puntos_personaje(Mario));
            //Comprobamos si se ha batido el récord.
            if (get_puntos_personaje(Mario)> RecordPuntosHeroe1)
            {
                recordheroe1 = fopen ("Records1.txt", "w");
                if (recordheroe1 == NULL)
                {
                    printf("Error al abrir el fichero");
                    return 0;
                }
                fprintf (recordheroe1, "%d\n", get_puntos_personaje(Mario));
                fclose(recordheroe1);
                sprintf (textoRecord, "Mario ha superado su record de puntuacion. El nuevo record es %d. Bien hecho", get_puntos_personaje(Mario));
            }
            //Mostramos el menú de game over.
            while (Pantalla_Activa() && !terminado)
            {
                Pantalla_DibujaImagen(GameOver, 0, 0, ANCHO_PANTALLA, ALTO_PANTALLA);
                Pantalla_DibujaTexto (textoGameOver, 300, 300);
                if (get_puntos_personaje(Mario)> RecordPuntosHeroe1)
                {
                    Pantalla_DibujaTexto (textoRecord, 300, 350);
                }
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_X))
                {
                    terminado = 1;
                }
                Pantalla_Actualiza();
            }
        }
        NumIteraciones = NumIteraciones + 1;    //Actualizamos el contador de iteraciones.
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }
    //Liberamos la memoria
    libera_personaje(Mario);
    Pantalla_ImagenLibera(fondo);
    libera_ejercito(enemigos);
    libera_rafaga(RafagaBalasHeroe1);
    libera_rafaga(RafagaBalasEnemigos);
    libera_ejercito(vacunas);
    Pantalla_ImagenLibera (GameOver);
    free (textovidasheroe);
    free (textopuntos);
    free (textoGameOver);
    free (textoRecord);
    return 3;
}


int main( int argc, char * argv[] )
{
    int codigo = 0;
    Pantalla_Crea("DOCTOR MARIO: CORONAVIRUS ESCAPE", ANCHO_PANTALLA,ALTO_PANTALLA);
    Pantalla_ColorTrazo(0,0,0, 255);
    codigo = menu();
    //Dependiendo del código se ejecuta una opción u otra.
    while (Pantalla_Activa())
    {
        if (codigo == 1)
        {
            codigo = jugar_partida();
        }
        if (codigo == 2)
        {
            codigo = ayuda();
        }
        if (codigo == 3)
        {
            Pantalla_Libera();
            return 0;
        }
        if (codigo == 4)
        {
            codigo = menu ();
        }
    }
    Pantalla_Libera();
    return 0;
}
