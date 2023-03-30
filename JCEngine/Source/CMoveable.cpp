#include <iostream>

#include "CMoveable.h"
#include "Object.h"
#include "CollisionManager.h"

using namespace std;

void CMoveable::Start()
{
	// 기본 이동속도 20으로 초기화
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
	// 이동속도 변경
	move_val = val;
}

void CMoveable::inputMove()
{
	// ----동작 구조----
	// case 1. 충돌 박스 on 물체에 충돌하지 않은 경우 : 이동 
	// case 2. 충돌 박스 on 물체에 충돌한 경우 : 이동 불가
	// case 3. 충돌 박스 off 물체에 충돌박스가 없는 경우: 이동

	// 이동 판단 : 움직이려는 물체에 충돌박스가 활성화 되어 있는지?
	// if 활성화 되어 있고 충돌하지 않은 경우 : 이동
	// else if 활성화 되어 있지 않은 경우 : 이동 
	// else 활성화 되어 있고 물체에 충돌한 모든 경우 : 이동 불가 

	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_LEFT:	// 좌측 이동
				{
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
					{
						cout << "충돌 발생!" << endl;
						break;
					}
				}
				case SDLK_RIGHT: // 우측 이동
				{
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
					{
						cout << "충돌 발생!" << endl;
						break;
					}
				}
				case SDLK_UP:
				{
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
					{
						cout << "충돌 발생!" << endl;
						break;
					}
				}
				case SDLK_DOWN:
				{
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
					{
						cout << "충돌 발생!" << endl;
						break;
					}
				}
				default: 
					break;
			}
		}
	}
}