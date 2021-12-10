#include "GameManager.h"

GameManager::GameManager()
{
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
}
void GameManager::RunningGame()
{
	while (rungame)
	{
		src_scene->loop();
	}
}
void GameManager::QuitGame()
{

}
