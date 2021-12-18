#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <list>
#include <iostream>

#include "Scene.h"
#include "Engine.h"

class GameManager
{
public:
	GameManager();
	GameManager(int win_width, int win_height);
	

	void OpenScene(Scene* scene);
	
	void SetGame();

	void RenderGame();

	Scene* GetScene();

	void QuitGame();

private:
	Engine* engine;
	Scene* src_scene;
};

#endif