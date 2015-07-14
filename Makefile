AG: main.cpp Game.h Game.cpp Nave.cpp Nave.h ObjetoEspacial.h Vector2D.cpp Vector2D.h
	g++ *.cpp -o AG -std=c++11 -lSDL2 -lm

clean:
	rm *.o
