#ifndef __C_MOVEABLE_H__
#define __C_MOVEABLE_H__

#include "Component.h"

#include "SDL.h"
#include "SDL_keycode.h"

class Object;

class CMoveable : public Component
{
public:

	virtual void Start();
	virtual void Update();
	virtual bool Enable(Object* object);

	void inputMove();

	float move_val;
	Object* src_ob;

private:
	SDL_Event event;
};

#endif