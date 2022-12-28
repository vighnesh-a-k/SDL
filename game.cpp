#include "game.h"
#define SDL_MAIN_HANDLED

#include "TextureManager.h"

SDL_Rect srcR, destR;



SDL_Texture* playerTex;
game::game() {

}
game::~game() {

}

void game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {
		
		int flags = 0;
		if(fullScreen) {
				flags = fullScreen;
		}

		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

			std::cout << "initialized";
		}

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {

			std::cout << "window created";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			
			SDL_SetRenderDrawColor(renderer, 255, 255,255,255);

			std::cout << "created renderer";
			isrunning = true;
			
		}
		else {
			isrunning = false;
		}
		playerTex = TextureManager::LoadTexture("assets/ant.png", renderer);
};

void game::handleEvents() {


	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isrunning = false;
		break;
	default:
		break;




	}

}

bool game::running() {
	return isrunning;

}

void game::update(){

	count++;
	std::cout << count;
	destR.h = 32;
	destR.w = 32;
	destR.x = count;


}

void game::render(){

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL,&destR);
	SDL_RenderPresent(renderer);



}

void game::clean(){

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned";


}


