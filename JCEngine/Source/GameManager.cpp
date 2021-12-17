#include "GameManager.h"

GameManager::GameManager() : 
	engine(NULL),
	src_scene(NULL),
	rungame(false)
{
	engine = new Engine();
	if(!engine->Init(640, 480))	// 기본 크기로 설정.
	{
		cout << "Engine Setting Error" << endl << "Quit Game" <<endl;
		delete engine;
	}
	rungame = true;
}
GameManager::GameManager(int win_width, int win_height) : 
	engine(NULL),
	src_scene(NULL),
	rungame(false)
{
	engine = new Engine();
	if (!engine->Init(win_width, win_height))
	{
		cout << "Engine Setting Error" << endl << "Quit Game" << endl;
		delete engine;
	}
	rungame = true;
}

void GameManager::CreateScene(Scene* scene)
{
	scenes.push_back(scene);
}
void GameManager::DestroyScene(Scene* scene)
{

}
void GameManager::OpenScene(Scene* scene)
{
	src_scene = scene;
	RunningGame();
}
void GameManager::RunningGame()
{
	src_scene->Start();

	while (rungame)
	{
		engine->SetRender();

		src_scene->Update();

		engine->Render();
	}
}
void GameManager::QuitGame()
{
	engine->Quit();
}
