#ifndef __OBJECT_H__
#define __OBJECT_H__ 

#include <iostream>
#include <string>
#include <algorithm>
#include <list>

#include "Monobehaviour.h"
#include "Component.h"
#include "CollisionManager.h"
#include "CCollision.h"
#include "CTransform.h"
#include "CMoveable.h"

using namespace std;


class Object : public Monobehaviour
{
public:
	virtual void Start();
	virtual void Update();

	Object();

	void AddChild(Object*);
	void RemoveChild(Object*);
	void AddComponent(Component*);

public:
	float x_pos, y_pos;
	float col_width, col_height;
	
	bool collider;

	list<Object*> childs;

	CTransform* transform;

	CollisionManager* collisionManager;

private:
	string ob_name;

	list<Component*> components;
};

#endif