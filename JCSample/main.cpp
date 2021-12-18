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

	GameManager* _game = new GameManager(640, 480);

	// set level 1
	// -----------------------
	Scene* level1 = new Scene();
	_game->CreateScene(level1);

	Object* player = new Object("player");
	Component* p_move = new CMoveable();
	Component* p_col = new CCollision();
	player->AddImage("assets/player.bmp");
	level1->AddObject(player);
	player->AddComponent(p_move);
	player->AddComponent(p_col);
	player->transform->setPosition(60, 370, player);

	Object* weapon = new Object("p_weapon");
	weapon->AddImage("assets/dummy.bmp");
	level1->AddObject(weapon);
	player->AddChild(weapon);
	weapon->transform->setScale(20, 10, weapon);
	weapon->transform->setPosition(100, 390, weapon);

	/*Object* weapon = new Object();
	level1->AddObject(weapon);
	weapon->AddImage("assets/.bmp", "ad");
	weapon->transform->setPosition(30, 0, weapon);
	Component* collision = new CCollision();
	weapon->AddComponent(collision);
	player->AddChild(weapon);*/


// 화면 테두리 벽
	Object* wall_top = new Object("Wall_top");
	Component* w1_col = new CCollision();
	level1->AddObject(wall_top);
	wall_top->AddImage("assets/wall.bmp");
	wall_top->AddComponent(w1_col);
	wall_top->transform->setScale(640, 50, wall_top);

	Object* wall_left = new Object("Wall_left");
	Component* w2_col = new CCollision();
	level1->AddObject(wall_left);
	wall_left->AddImage("assets/wall.bmp");
	wall_left->AddComponent(w1_col);
	wall_left->transform->setScale(30, 480, wall_left);

	Object* wall_bottom = new Object("Wall_bottom");
	Component* w3_col = new CCollision();
	level1->AddObject(wall_bottom);
	wall_bottom->AddImage("assets/wall.bmp");
	wall_bottom->AddComponent(w3_col);
	wall_bottom->transform->setScale(640, 50, wall_bottom);
	wall_bottom->transform->setPosition(0, 430, wall_bottom);

	Object* wall_right = new Object("Wall_right");
	Component* w4_col = new CCollision();
	level1->AddObject(wall_right);
	wall_right->AddImage("assets/wall.bmp");
	wall_right->AddComponent(w4_col);
	wall_right->transform->setScale(30, 480, wall_right);
	wall_right->transform->setPosition(610, 0, wall_right);

	Object* otc1 = new Object("Obstacle1");
	Component* otc1_col = new CCollision();
	level1->AddObject(otc1);
	otc1->AddImage("assets/wall.bmp");
	otc1->AddComponent(w4_col);
	otc1->transform->setScale(50, 320, otc1);
	otc1->transform->setPosition(150, 150, otc1);

	Object* otc2 = new Object("Obstacle1");
	Component* otc2_col = new CCollision();
	level1->AddObject(otc2);
	otc2->AddImage("assets/wall.bmp");
	otc2->AddComponent(otc2_col);
	otc2->transform->setScale(50, 320, otc2);
	otc2->transform->setPosition(320, 30, otc2);

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
	//delete weapon;

	//delete level2;

	return 0;
}
