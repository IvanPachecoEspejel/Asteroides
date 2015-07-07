/*	Asteroide.h
*
*	Interfaz de la clase Asteroide, que declara la clase
*
*/

#ifndef _ASTEROIDE_H_
#define _ASTEROIDE_H_

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>

#include "Vector2D.h"

#define MAX_VERTICES	20
#define MAX_RADIO		50
#define MEDIO_GRADO		0.00873

using namespace std;

class Asteroide{
	private:
		vector<Vector2D> vertices;
		SDL_Point *points;
        int radio;
        float velocidadAngular;
        Vector2D centro;
        Vector2D velocidad;
    public:
        Asteroide();
        int numVertices();
        int getRadio();
        Vector2D getCentro();
        Vector2D getVelocidad();
        void setVelocidad(Vector2D);
        void imprimeAsteroide();
        void actualizaAsteroide();
        SDL_Point *puntos();
        bool fueraDePantalla();
        
};

#endif







