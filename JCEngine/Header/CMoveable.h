#ifndef __C_MOVEABLE_H__
#define __C_MOVEABLE_H__

#include "Monobehaviour.h"
#include "Component.h"

#include "SDL.h"
#include "SDL_keycode.h"

class Object;

class CMoveable : public Component
{
public:
	CMoveable(Object* object);

	virtual void Start();
	virtual void Update();

	void inputMove();

	int move_val;

private:
	Object* src_ob;

	SDL_Event event;
};

#endif