#include "GameManager.h"

using namespace std;

GameManager::GameManager() : 
	engine(NULL),
	src_scene(NULL)
{
	engine = new Engine();
	if(!engine->Init(640, 480))	// �⺻ ũ��� ����.
	{
		cout << "Engine Setting Error" << endl << "Quit Game" <<endl;
		delete engine;
	}
}
GameManager::GameManager(int win_width, int win_height) : 
	engine(NULL),
	src_scene(NULL)
{
	engine = new Engine();
	if (!engine->Init(win_width, win_height))
	{
		cout << "Engine Setting Error" << endl << "Quit Game" << endl;
		delete engine;
	}
}

Scene* GameManager::GetScene()
{
	if (src_scene == NULL)
	{
		cout << "�� �ε� ����" << endl;
		return NULL;
	}
	return src_scene;
}
void GameManager::OpenScene(Scene* scene)
{
	src_scene = scene;
	src_scene->Start();
}
void GameManager::SetGame()
{
	if (engine != NULL && src_scene != NULL)
	{
		engine->Set();
	}
}
void GameManager::RenderGame()
{
	if (engine != NULL && src_scene != NULL)
	{
		engine->Render();
	}
}
void GameManager::QuitGame()
{
	engine->Quit();
}
