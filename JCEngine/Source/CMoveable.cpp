#include "CMoveable.h"
#include "Object.h"

void CMoveable::Start()
{

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

// ----���� ����----
// �浹 �ڽ� on �浹 x : �̵� 
// �浹 �ڽ� on �浹 o : �̵� x -> break
// �浹 �ڽ� off : �̵�
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
					&& !src_ob->collisionManager->CheckCollision(src_ob, DIR_LEFT,move_val))
				{
					src_ob->transform->setPosition(-move_val, 0);
					break;
				}
				else if (src_ob->collider == false)
				{
					src_ob->transform->setPosition(-move_val, 0);
					break;
				}
				else
					break;
			case SDLK_RIGHT:
				if (src_ob->collider == true 
					&& !src_ob->collisionManager->CheckCollision(src_ob, DIR_RIGHT, move_val))
				{
					src_ob->transform->setPosition(move_val, 0);
					break;
				}
				else if (src_ob->collider == false)
				{
					src_ob->transform->setPosition(move_val, 0);
					break;
				}
				else
					break;
			case SDLK_UP:
				if (src_ob->collider == true 
					&& !src_ob->collisionManager->CheckCollision(src_ob, DIR_UP, move_val))
				{
					src_ob->transform->setPosition(0, -move_val);
					break;
				}
				else if (src_ob->collider == false)
				{
					src_ob->transform->setPosition(0, -move_val);
					break;
				}
				else
					break;
			case SDLK_DOWN:
				if (src_ob->collider == true
					&& !src_ob->collisionManager->CheckCollision(src_ob, DIR_DOWN, move_val))
				{
					src_ob->transform->setPosition(0, move_val);
					break;
				}
				else if (src_ob->collider == false)
				{
					src_ob->transform->setPosition(0, move_val);
					break;
				}
				else
					break;
			default:
				break;
			}
		}
	}
}