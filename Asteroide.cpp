/*	Asteroide.cpp
*
*	Implementacion de la clase Asteroide, con todas las funciones que permiten la creacion,
*	actualizacion e interaccion con la clase.
*
*/

#include "Asteroide.h"

Asteroide :: Asteroide(){
	int nVer = (rand() % (MAX_VERTICES - 5)) + 5;
	int i;
	float r, x, y, ang;
	Vector2D v;
	
	points = new SDL_Point[nVer + 1];
	radio = fmod(rand(), 4 * MAX_RADIO / 5) + (MAX_RADIO / 5);
	ang = fmod(rand(),M_PI/3) + (M_PI / 3);
	velocidadAngular = (MEDIO_GRADO * MAX_RADIO) / radio;
	
	if(rand() % 2 == 0)
		velocidadAngular *= -1;
	/*
	switch(rand() % 4){
		case 0:
			centro = Vector2D(rand() % 800, -100);
			break;
		case 1:
			ang *= -1;
			centro = Vector2D(rand() % 800, 700);
			break;
		case 2:
			ang += (3 * M_PI / 2);
			centro = Vector2D(-100,rand() % 600);
			break;
		default:
			ang += (M_PI / 2);
			centro = Vector2D(900,rand() % 600);
			break;
	}*/
	if(rand() % 2 == 0){
			centro = Vector2D((rand() % 300) + 250, -100);
	}
	else{
			ang *= -1;
			centro = Vector2D((rand() % 300) + 250, 700);
	}
	
	velocidad = Vector2D((50/radio) * cos(ang),(50/radio) * sin(ang));
        
    for(i = 0; i < nVer; i++){
    	ang = fmod(rand(), (360 / nVer));
    	ang += ((360 / nVer) * i);
    	ang = (ang / 180) * M_PI;
    	r = fmod(rand(), (radio / 3)) + (2 * radio / 3);
    	x = r * cos(ang);
    	y = r * sin(ang);
    	
    	v = Vector2D(x,y);
    	v = v + centro;
    	
    	vertices.emplace_back(v);
		points[i] = v.punto();
    }
	points[i] = points[0];
}

int Asteroide :: numVertices(){
	return vertices.size();
}

int Asteroide :: getRadio(){
	return radio;
}

Vector2D Asteroide :: getCentro(){
	return centro;
}

Vector2D Asteroide :: getVelocidad(){
	return velocidad;
}

void Asteroide :: setVelocidad(Vector2D vel){
	velocidad = vel;
}

void Asteroide :: imprimeAsteroide(){
	cout << "Asteroide:\tC =" << centro.getX() << "," << centro.getY() << "\tR = " << radio << endl;
}

void Asteroide :: actualizaAsteroide(){
    int i;
    float r, ang, x, y;
    
    centro += velocidad;
    for(i = 0; i < vertices.size(); i++){
    	vertices[i] += velocidad;

    	x = vertices[i].getX() - centro.getX();
    	y = vertices[i].getY() - centro.getY();
    	if(x > 0 and y >= 0)
	    	ang = atan(y / x);
	    if(x == 0 and y > 0)
	    	ang = M_PI / 2;
	    if(x < 0)
	    	ang = atan(y / x) + M_PI;
	    if(x == 0 and y < 0)
	    	ang = (3 * M_PI) / 2;
	    if(x > 0 and y < 0)
	    	ang = atan(y / x) + (2 * M_PI);
	    
    	ang += velocidadAngular;
    	r = sqrt(pow(x,2) + pow(y,2));
    	vertices[i] = {(r * cos(ang)) + centro.getX(), (r * sin(ang)) + centro.getY()};

		points[i] = vertices[i].punto();
    }
	points[i] = points[0];
}

SDL_Point* Asteroide :: puntos(){
	return points;
}

bool Asteroide :: fueraDePantalla(){
	return centro.getX() < -100 or centro.getX() > 900 or centro.getY() < (-100) or centro.getY() > 700;
}







