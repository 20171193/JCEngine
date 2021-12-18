#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <iostream>

#include "SDL.h"

class Engine 
{
public:
	bool Init(int width, int height);

	void Set();

	void Render();

	void Quit();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
};

#endif