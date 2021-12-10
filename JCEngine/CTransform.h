#ifndef __CTRANSFORM_H__
#define __CTRANSFORM_H__
#include "Component.h"

class CTransform : public Component
{
public:
	virtual void Start();
	virtual void Update();

	void setPosition(float x, float y, float z);
	void setScale(float x, float y, float z);

};

#endif