#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <iostream>

#include "SDL.h"

using namespace std;

class Engine 
{
public:
	bool Init(int width, int height);

	void SetRender();

	void Render();

	void Quit();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif