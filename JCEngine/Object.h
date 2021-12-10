#ifndef __OBJECT_H__
#define __OBJECT_H__ 

#include "Monobehaviour.h"
#include "Component.h"
#include "CTransform.h"

#include <string>
#include <algorithm>
#include <list>
using namespace std;

class Object : public Monobehaviour
{
public:
	virtual void Start();
	virtual void Update();
	virtual void FixedUpdate();

	Object(string name);

	void AddChild(Object*);
	void RemoveChild(Object*);
	void AddComponent(Component*);

	void SetPosition(float x, float y, float z);
	void SetScale(float x, float y, float z);
public:
	float x_pos, y_pos, z_pos;
	float x_scale, y_scale, z_scale;

private:
	string ob_name;

	list<Object*> childs;
	list<Component*> components;
};

#endif