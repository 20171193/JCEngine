#include "Engine.h"

bool Engine::Init(int width, int height)
{
	// SDL 초기화
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout<<"Could not initialize SDL!"<< SDL_GetError()<<endl;
		return false;
	}
	// 윈도우 생성
	window = SDL_CreateWindow("JC Engine", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		cout << "Could not create Window!" << SDL_GetError() << endl;
		return false;
	}
	// 렌더러 생성
	renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	if (renderer == NULL)
	{
		cout << "Could not create Renderer!" << SDL_GetError() << endl;
		return false;
	}
}

void Engine::Render()
{
	SDL_RenderPresent(renderer);
}

void Engine::Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}