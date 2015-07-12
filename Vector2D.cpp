/*	Vector2D.cpp
*
*	Implementacion de la clase Vector2D, con las funciones necesarias para la interaccion con la clase Vector2D
*
*/

#include "Vector2D.h"

Vector2D :: Vector2D(int x, int y) : m_x(x), m_y(y){}

Vector2D :: Vector2D(void) : m_x(0), m_y(0){}

int Vector2D :: getX(){
	return m_x;
}

int Vector2D :: getY(){
	return m_y;
}

void Vector2D :: setX(int x){
	m_x = x;
}

void Vector2D :: setY(int y){
	m_y = y;
}

int Vector2D :: length(){
	return sqrt(pow(m_x,2) + pow(m_y,2));
}

void Vector2D :: normaliza(){
	int z = sqrt(pow(m_x,2) + pow(m_y,2));
	m_x /= z;
	m_y /= z;
}

SDL_Point Vector2D :: punto(){
	SDL_Point tmp = {(int)m_x, (int)m_y};
	return tmp;
}
