/*	Game.h
*
*	Interfaz con los elementos necesarios para implmentar un videojuego por medio de la clase Game.
*
*/

#ifndef _Game_H_
#define _Game_H_

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

//#include "Asteroide.h"
#include "Nave.h"

#define NUMERO_NAVES 4

using namespace std;

class Game{
	public:
		Game(int);
		Game();
		~Game();
		void init(const char*, int, int, int, int, int);
		void render();
		void update();
		void handleEvents();
		void clean();
		bool running();
		int anchoDisplay;
		int altoDisplay;
	private:
		//int nAsteroides;
		//Asteroide<vector> asteroides;
		vector<Nave> naves;
		bool m_bRunning;
		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;
		SDL_Surface* m_pSurface;
		SDL_Texture* m_pTexture;
};

#endif








