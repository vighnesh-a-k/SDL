#pragma once

#include <iostream>
#include "SDL.h"
#define SDL_MAIN_HANDLED
#include "SDL_image.h"





class game
{
public:
    game();
    ~game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
    void update();
    void render();
    void clean();
    void handleEvents();
    bool running();
private:
    int count=0;
    bool isrunning;
    SDL_Window* window;
    SDL_Renderer* renderer;




};

