#ifndef __CCOLLISION_H__
#define __CCOLLISION_H__

#include <iostream>

#include "Component.h"

class Object;

using namespace std;

class CCollision : public Component
{

public:

	virtual void Start();
	virtual void Update();
	virtual bool Enable(Object* object);

	void setColliderScale(float horizontal, float vertical);
	
private:
	Object* src_ob;
};

#endif