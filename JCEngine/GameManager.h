#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "Scene.h"
#include "Engine.h"

#include <list>
using namespace std;

class GameManager
{
public:
	GameManager();
	
	void CreateScene(Scene* scene);

	void DestroyScene(Scene* scene);

	void OpenScene(Scene* scene);

	void QuitGame();

	bool rungame;

private:
	void RunningGame();		//�ܺο��� ������ �Ұ�

private:
	Engine* engine;

	list<Scene*> scenes;
	Scene* src_scene;
};

#endif