#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "Scene.h"
#include <list>
using namespace std;

class GameManager
{
public:
	GameManager();
	
	void AddScene(Scene* scene);

	void DestroyScene(Scene* scene);

	void OpenScene(Scene* scene);

	void RunningGame();

	void QuitGame();

	bool rungame;
private:
	list<Scene*> scenes;
	Scene* src_scene;
};

#endif