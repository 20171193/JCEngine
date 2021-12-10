#include "Object.h"

Object::Object(string name)
{
	ob_name = name;

	x_pos = 0;
	y_pos = 0;
	z_pos = 0;

	x_scale = 0;
	y_scale = 0;
	z_scale = 0;
}


void Object::AddChild(Object* child)
{
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

void Object::SetPosition(float x, float y, float z)
{
	x_pos += x;
	y_pos += y;
	z_pos += z;

	if (!childs.empty())
	{
		for (Object* i : childs)
		{
			i->setPosition(x, y, z);
		}
	}
}
void Object::SetScale(float x, float y, float z)
{
	x_scale = x;
	y_scale = y;
	z_scale = z;

	//if (!childs.empty())
	//{
	//	for (Object* i : childs)
	//	{
	//		i->setPosition(x, y, z);
	//	}
	//}
}
void Object::Awake()
{

}
void Object::Start()
{

}
void Object::Update()
{

}
void Object::FixedUpdate()
{

}
