#ifndef __CCOLLISION_H__
#define __CCOLLISION_H__
#include "Component.h"

class CCollision : public Component
{
public:
	virtual void Start();
	virtual void Update();

	bool CheckCollision();
};

#endif