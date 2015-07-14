/*	Game.cpp
*
*	Implementacion de la clase Game, que separa cada una de las tareas necesarias para un videojuego
*
*/

#include "Game.h"

#define NVO_PLG_INTERVALO		10
#define LADOS_POLIGONO_MAX		20
#define DIAMETRO_POLIGONO_MAX	400

using namespace std;

//Game :: Game(int n) : nAsteroides(n){}
Game :: Game(){}

Game :: ~Game(){}

void Game :: init(const char* titulo, int xpos, int ypos, int alto, int ancho, int banderas){
	int i;
	Uint32 rmask, gmask, bmask, amask;

	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		rmask = 0xff000000;
		gmask = 0x00ff0000;
		bmask = 0x0000ff00;
		amask = 0x000000ff;
	#else
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = 0xff000000;
	#endif

	srand(time(NULL));
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		
		m_bRunning = false;
		return;
	}

	m_pWindow = SDL_CreateWindow(titulo, xpos, ypos, alto, ancho, banderas);
	SDL_GetWindowSize(m_pWindow, &anchoDisplay, &altoDisplay);
	
	if (m_pWindow == NULL){
		cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
		
		m_bRunning = false;
		return;
	}

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_pRenderer == NULL){
		cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
		
		m_bRunning = false;
		return;
	}
	
	m_pSurface = SDL_CreateRGBSurface(0, ancho, alto, 32, rmask, gmask, bmask, amask);
	if (m_pSurface == NULL){
		cout << "SDL_CreateRGBSurface Error: " << SDL_GetError() << endl;
		
		m_bRunning = false;
		return;
	}
	/*
	for(i = 0 ; i < nAsteroides; i++){
		asteroides.emplace_back(Asteroide());
		asteroides[i].imprimeAsteroide();
	}
	*/
	
	for(i = 0; i < NUMERO_NAVES; i++){
		std::cout << "iniciando..." <<std::endl;
		naves.emplace_back(Nave(i));
	}
	
	m_bRunning = true;
	return;
}

void Game :: render(){
	//SDL_Point *pts;
	//int i;
		
	//SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pSurface);
	SDL_RenderClear(m_pRenderer);
	/*SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	for(i = 0 ; i < asteroides.size() ; i++){
		SDL_RenderDrawLines(m_pRenderer, asteroides[i].puntos(), asteroides[i].numVertices() + 1);		
	}
	*/
	SDL_RenderPresent(m_pRenderer);
}

void Game :: update(){
	
	
	/*
	int i, j;
	float distancia;
	
	for(i = 0; i < nAsteroides; i++){
		asteroides[i].actualizaAsteroide();
		if(asteroides[i].fueraDePantalla()){
			asteroides.erase(asteroides.begin() + i);
			asteroides.emplace_back(Asteroide());
			asteroides[nAsteroides - 1].imprimeAsteroide();
		}
		for(j = 0; j < nAsteroides; j++)
			if(j != i){
				distancia = sqrt(pow(asteroides[i].getCentro().getX() - asteroides[j].getCentro().getX(), 2) + 
								 pow(asteroides[i].getCentro().getY() - asteroides[j].getCentro().getY(), 2));
				if(distancia < (asteroides[i].getRadio() + asteroides[j].getRadio())){
					if(asteroides[i].getRadio() < asteroides[j].getRadio()){
						asteroides[j].setVelocidad((asteroides[i].getVelocidad() * 0.5)+ asteroides[j].getVelocidad());
						asteroides.erase(asteroides.begin() + i);
					}
					else{
						asteroides[i].setVelocidad((asteroides[i].getVelocidad() * 0.5) + asteroides[j].getVelocidad());
						asteroides.erase(asteroides.begin() + j);
					}
					asteroides.emplace_back(Asteroide());
					asteroides[nAsteroides - 1].imprimeAsteroide();
				}
			}
	}// */
}

void Game::handleEvents(){
	SDL_Event event;

	if(SDL_PollEvent(&event)){
		switch (event.type){
			case SDL_QUIT:
				m_bRunning = false;
				break;
			default:
				break;
		}
	}
}

void Game :: clean(){
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_FreeSurface(m_pSurface);
	SDL_DestroyTexture(m_pTexture);
	SDL_Quit();
}

bool Game :: running(){
	return m_bRunning;
}







