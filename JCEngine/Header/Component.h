#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "IComponent.h"

class Object;

class Component : public IComponent
{
public:
	virtual void Start() {}
	virtual void Update() {}
	virtual bool Enable(Object* object) { return false; }
};

#endif