#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <list>
#include <iostream>

#include "Scene.h"
#include "Engine.h"

using namespace std;

class GameManager
{
public:
	GameManager();
	GameManager(int win_width, int win_height);
	
	void CreateScene(Scene* scene);

	void DestroyScene(Scene* scene);

	void OpenScene(Scene* scene);

	void QuitGame();

	bool rungame;

private:
	void RunningGame();		//외부에서 실행이 불가

private:
	Engine* engine;

	list<Scene*> scenes;
	Scene* src_scene;
};

#endif