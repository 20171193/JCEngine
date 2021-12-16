#include "Object.h"

Object::Object() : 
	collider(false)
{
	InitObject();
	transform = new CTransform(this);
}

void Object::InitObject()
{
	x_pos = 0;
	y_pos = 0;
	z_pos = 0;

	x_scale = 0;
	y_scale = 0;
	z_scale = 0;
}

void Object::AddChild(Object* child)
{
	transform->getChildsInfo(child);
	childs.push_back(child);
}
void Object::RemoveChild(Object* child)
{
	list<Object*>::iterator src_child;
	// find 값이 없을 경우 맨 마지막을 가리킨다.
	src_child = find(childs.begin(), childs.end(), child);

	if (src_child != childs.end())
	{
		
	}
}
void Object::AddComponent(Component* component)
{
	components.push_back(component);
}

void Object::Start()
{
	for (Component* src_comp : components)
	{
		src_comp->Start();
	}
}
void Object::Update()
{
	for (Component* src_comp : components)
	{
		src_comp->Update();
	}
}

