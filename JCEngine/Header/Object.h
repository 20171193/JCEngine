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
#include "TextureManager.h"

using namespace std;


class Object : public Monobehaviour
{
public:
	virtual void Start();
	virtual void Update();

	Object(string name);

	void AddChild(Object*);
	void RemoveChild(Object*);
	void AddComponent(Component*);

	void AddImage(string img_file);

public:	
	int x_pos, y_pos;
	int x_scale, y_scale;
	bool collider;

	list<Object*> childs;

	CTransform* transform;
	CCollision* collison;
private:	

	string ob_image;
	string ob_name;

	list<Component*> components;
};

#endif