#ifndef __OBJECT_H__
#define __OBJECT_H__ 

#include "Monobehaviour.h"
#include "Component.h"
#include "CCollision.h"
#include "CTransform.h"
#include "CMoveable.h"

#include <string>
#include <algorithm>
#include <list>
using namespace std;


class Object : public Monobehaviour
{
public:
	virtual void Start();
	virtual void Update();

	Object();

	void InitObject();
	void AddChild(Object*);
	void RemoveChild(Object*);
	void AddComponent(Component*);

public:
	float x_pos, y_pos, z_pos;
	float x_scale, y_scale, z_scale;
	
	bool collider;

	list<Object*> childs;

	CTransform* transform;
private:
	string ob_name;

	list<Component*> components;
};

#endif