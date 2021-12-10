#include "GameManager.h"

GameManager::GameManager()
{
	rungame = true;

	engine = new Engine();
	engine->Init();
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
	while (rungame)
	{
		engine->SetRender();

		src_scene->loop();
		
		engine->Render();
	}
}
void GameManager::QuitGame()
{
	engine->Quit();
}
