#ifndef __CCOLLISION_H__
#define __CCOLLISION_H__

#include <iostream>

#include "Monobehaviour.h"
#include "Component.h"

class Object;

using namespace std;

class CCollision : public Component
{
public:
	CCollision() {}

	virtual void Start();
	virtual void Update();

	bool CheckCollision(Object* ob1, Object* ob2);

private:
	list<Object*> ob_collision_list;

};

#endif