#pragma once
#include"game.h"


class gameObject{
public:
	gameObject(const char* texturesheet, SDL_Renderer* ren);
	~gameObject();
	
	void Update();
	void Render();


private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, descRect;
	SDL_Renderer* renderer;






};

