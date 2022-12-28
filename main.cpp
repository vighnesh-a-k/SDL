#define SDL_MAIN_HANDLED
#include <iostream>
#include "SDL.h"
#include "game.h"

game* Game = nullptr;
const int FPS = 60;
const int frameDelay = 1000 / FPS;

Uint32 frameStart;
int FrameTime;


int main() {

	Game = new game();

	 
	Game->init("infinite", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while(Game->running()){

		frameStart = SDL_GetTicks();
		Game->handleEvents();
		Game->update();
		Game->render();

		FrameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > FrameTime) {
			SDL_Delay(frameDelay - FrameTime);

		}






	}
	Game->clean();

	return 0;
   
}