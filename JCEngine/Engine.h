#ifndef __ENGINE_H__
#define __ENGINE_H__

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#include <iostream>
#include "SDL2-devel-2.0.16-VC/SDL2-2.0.16/include/SDL.h"

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