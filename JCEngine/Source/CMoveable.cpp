#include "CMoveable.h"
#include "Object.h"
CMoveable::CMoveable(Object* object) :
	move_val(1)
{
	src_ob = object;
}

void CMoveable::Start()
{
}
void CMoveable::Update()
{
	inputMove();
}

void CMoveable::inputMove()
{
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
			case SDLK_LEFT:
				src_ob->transform->setPosition(-move_val, 0, 0);
				break;
			case SDLK_RIGHT:
				src_ob->transform->setPosition(move_val, 0, 0);
				break;
			case SDLK_UP:
				src_ob->transform->setPosition(0, -move_val, 0);
				break;
			case SDLK_DOWN:
				src_ob->transform->setPosition(0, move_val, 0);
				break;
			default:
				break;
			}
		}
	}
}