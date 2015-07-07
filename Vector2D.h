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
		Vector2D(float, float);
		Vector2D(void);
		float getX();
		float getY();
		void setX(float x);
		void setY(float y);
		float length();
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
		Vector2D operator*(float scalar){
			return Vector2D(m_x * scalar, m_y * scalar);
		} 
		
		Vector2D& operator*=(float scalar){
			m_x *= scalar;
			m_y *= scalar;
			return *this;
		}
		
	private:
		float m_x;
		float m_y;
};

#endif
