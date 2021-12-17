//JC Sample Game Custom

#include <iostream>

#include "Monobehaviour.h"
#include "GameManager.h"
#include "Scene.h"
#include "Object.h"
#include "IComponent.h"
#include "Component.h"
#include "CCollision.h"
#include "CMoveable.h"

using namespace std;

int main(int, char **)
{
	cout << "hello" << endl;

	GameManager* _game = new GameManager();

	// set level 1
	// -----------------------
	Scene* level1 = new Scene();
	_game->CreateScene(level1);

	Object* player = new Object();
	level1->AddObject(player);
	Component* p_move = new CMoveable();
	player->AddComponent(p_move);

	Object* weapon = new Object();
	level1->AddObject(weapon);
	Component* collision = new CCollision();
	weapon->AddComponent(collision);
	player->AddChild(weapon);

	Object* Enemy = new Object();
	level1->AddObject(Enemy);

	// -----------------------
	// end level 1

	// set level 2
	// -----------------------
	//Scene* level2 = new Scene();
	//_game->CreateScene(level2);


	// -----------------------
	// end level 2

	_game->OpenScene(level1);

	//_game->QuitGame();

	delete _game;
	delete level1;
	delete player;
	delete p_move;
	//delete collision;
	delete weapon;

	//delete level2;

	return 0;
}
