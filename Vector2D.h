/*	Vector2D.h
*
*	Interfaz de la clase Vector2D, que declara los elementos y funciones de la clase.
*
*/

#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <SDL2/SDL.h>
#include <cmath>

class Vector2D
{
	public:
		Vector2D(int, int);
		Vector2D(void);
		int getX();
		int getY();
		void setX(int x);
		void setY(int y);
		int length();
		void normaliza();
		SDL_Point punto();
		
		//Sobrecarga para adición de 2 vectores
		Vector2D operator+(const Vector2D& v2) const {
			return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
		}
		
		friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2){
			v1.m_x += v2.m_x;
			v1.m_y += v2.m_y;
			return v1;
		}
		
		//Sobrecara para multiplicar un vector por un escalar
		Vector2D operator*(int scalar){
			return Vector2D(m_x * scalar, m_y * scalar);
		} 
		
		Vector2D& operator*=(int scalar){
			m_x *= scalar;
			m_y *= scalar;
			return *this;
		}
		
	private:
		int m_x;
		int m_y;
};

#endif
