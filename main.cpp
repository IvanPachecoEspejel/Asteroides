/*	main.cpp
*
*	Programa principal que maneja el desarrollo de un juego.
*
*/

#include <SDL2/SDL.h>

#include "Game.h"

using namespace std;

Game* g_game = 0;

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Opciones invalidas, especifique numero de asteroides a crear." << endl;
		return 1;
	}
	
	g_game = new Game(atoi(argv[1]));
	g_game->init("Asteroides", 100, 50, 800, 600, SDL_WINDOW_SHOWN);
	
	cout << "--------------------------------------------" << endl;
	while(g_game->running()){
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	
	g_game->clean();
	
	return 0;
}
