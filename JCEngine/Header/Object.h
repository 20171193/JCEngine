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

class Object : public Monobehaviour
{
public:
	virtual void Start();
	virtual void Update();

	Object(std::string name);
	~Object() { delete transform; };

	void AddChild(Object*);
	void AddComponent(Component*);

	void AddImage(std::string img_file);

public:	
	int x_pos, y_pos;
	int x_scale, y_scale;
	bool collider;

	std::list<Object*> childs;

	CTransform* transform;
private:	

	std::string ob_image;
	std::string ob_name;

	std::list<Component*> components;
};

#endif