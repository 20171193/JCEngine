#ifndef __I_COMPONENT_H__
#define __I_COMPONENT_H__

class Object;

class IComponent
{
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual bool Enable(Object*) = 0;
};

#endif