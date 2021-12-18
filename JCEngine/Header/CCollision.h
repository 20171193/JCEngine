#ifndef __CCOLLISION_H__
#define __CCOLLISION_H__

#include <iostream>

#include "Component.h"

class Object;

class CCollision : public Component
{

public:

	virtual void Start();
	virtual void Update();
	virtual bool Enable(Object* object);

	
private:
	Object* src_ob;
};

#endif