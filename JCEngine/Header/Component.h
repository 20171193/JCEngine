#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "Monobehaviour.h"

class Component : public Monobehaviour
{
public:

	virtual void Start() {}
	virtual void Update() {}	
};

#endif