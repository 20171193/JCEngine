#include <iostream>

#include "CMoveable.h"
#include "Object.h"
#include "CollisionManager.h"

using namespace std;

void CMoveable::Start()
{
	move_val = 20;
}
void CMoveable::Update()
{
	inputMove();
}
bool CMoveable::Enable(Object* object)
{
	src_ob = object;
	return true;
}
void CMoveable::setMoveSpeed(int val)
{
	move_val = val;
}

// ----동작 구조----
// 충돌 박스 on 충돌 x : 이동 
// 충돌 박스 on 충돌 o : 이동 x -> break
// 충돌 박스 off : 이동
void CMoveable::inputMove()
{
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
			case SDLK_LEFT:
				if (src_ob->collider == true
					&& !CollisionManager::getInstance().CheckCollision(src_ob, DIR_LEFT, move_val))
				{
					src_ob->transform->setPosition(-move_val, 0, src_ob);
					break;
				}
				else if (src_ob->collider == false)
				{
					src_ob->transform->setPosition(-move_val, 0, src_ob);
					break;
				}
				else
					cout << "충돌 발생!" << endl;
					break;
			case SDLK_RIGHT:
				if (src_ob->collider == true 
					&& !CollisionManager::getInstance().CheckCollision(src_ob, DIR_RIGHT, move_val))
				{
					src_ob->transform->setPosition(move_val, 0, src_ob);
					break;
				}
				else if (src_ob->collider == false)
				{
					src_ob->transform->setPosition(move_val, 0, src_ob);
					break;
				}
				else
					cout << "충돌 발생!" << endl;
					break;
			case SDLK_UP:
				if (src_ob->collider == true 
					&& !CollisionManager::getInstance().CheckCollision(src_ob, DIR_UP, move_val))
				{
					src_ob->transform->setPosition(0, -move_val, src_ob);
					break;
				}
				else if (src_ob->collider == false)
				{
					src_ob->transform->setPosition(0, -move_val, src_ob);
					break;
				}
				else
					cout << "충돌 발생!" << endl;
					break;
			case SDLK_DOWN:
				if (src_ob->collider == true
					&& !CollisionManager::getInstance().CheckCollision(src_ob, DIR_DOWN, move_val))
				{
					src_ob->transform->setPosition(0, move_val, src_ob);
					break;
				}
				else if (src_ob->collider == false)
				{
					src_ob->transform->setPosition(0, move_val, src_ob);
					break;
				}
				else
					cout << "충돌 발생!" << endl;
					break;
			default:
				break;
			}
		}
	}
}