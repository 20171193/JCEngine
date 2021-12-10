//int SDL_main(int argc, char* argv[])
//{
//	printf("Start\n");
//
//	 SDL 초기화
//	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
//	{
//		printf("Could not initialize SDL! (%s)\n", SDL_GetError());
//		return -1;
//	}
//
//	 윈도우 생성
//	window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED,
//		SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
//	if (window == NULL) 
//	{
//		printf("Could not create window! (%s)\n", SDL_GetError());
//		return -1;
//	}
//
//	 렌더러 생성
//	renderer = SDL_CreateRenderer(window, -1,
//		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
//	if (renderer == NULL) 
//	{
//		printf("Could not create renderer! (%s)\n", SDL_GetError());
//		return -1;
//	}
//
//	 렌더러를 흰색으로 초기화
//	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
//	SDL_RenderClear(renderer);	// ***렌더러 초기화 코드
//
//
//	SDL_Rect r = { 50, 50, 100, 100 };
//	SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
//	SDL_RenderDrawRect(renderer, &r);
//
//	 스크린 업데이트
//	SDL_RenderPresent(renderer);
//
//	SDL_Event event;
//	int done = 0;
//
//	while (!done) 
//	{
//		SDL_PollEvent(&event);
//
//		if (event.type == SDL_QUIT) 
//		{
//			done = 1;
//		}
//	}
//
//	 Destroy 순서
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//
//	printf("End\n");
//
//	return 0;
//}


#include "GameManager.h"
#include "Scene.h"
#include "Object.h"
#include "Component.h"

void main()
{
	GameManager* _game = new GameManager();
	Scene* level1 = new Scene("Level 1");

	_game->CreateScene(level1);
	
	Object



	_game->RunningGame();
	_game->QuitGame();

	delete _game;
	delete level1;
}