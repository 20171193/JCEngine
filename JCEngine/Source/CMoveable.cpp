#include <iostream>

#include "CMoveable.h"
#include "Object.h"
#include "CollisionManager.h"

using namespace std;

void CMoveable::Start()
{
	// �⺻ �̵��ӵ� 20���� �ʱ�ȭ
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
	// �̵��ӵ� ����
	move_val = val;
}

void CMoveable::inputMove()
{
	// ----���� ����----
	// case 1. �浹 �ڽ� on ��ü�� �浹���� ���� ��� : �̵� 
	// case 2. �浹 �ڽ� on ��ü�� �浹�� ��� : �̵� �Ұ�
	// case 3. �浹 �ڽ� off ��ü�� �浹�ڽ��� ���� ���: �̵�

	// �̵� �Ǵ� : �����̷��� ��ü�� �浹�ڽ��� Ȱ��ȭ �Ǿ� �ִ���?
	// if Ȱ��ȭ �Ǿ� �ְ� �浹���� ���� ��� : �̵�
	// else if Ȱ��ȭ �Ǿ� ���� ���� ��� : �̵� 
	// else Ȱ��ȭ �Ǿ� �ְ� ��ü�� �浹�� ��� ��� : �̵� �Ұ� 

	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_LEFT:	// ���� �̵�
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
						cout << "�浹 �߻�!" << endl;
						break;
					}
				}
				case SDLK_RIGHT: // ���� �̵�
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
						cout << "�浹 �߻�!" << endl;
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
						cout << "�浹 �߻�!" << endl;
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
						cout << "�浹 �߻�!" << endl;
						break;
					}
				}
				default: 
					break;
			}
		}
	}
}