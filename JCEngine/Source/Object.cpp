#include "Object.h"

Object::Object() : 
	collider(false),
	x_pos(0),
	y_pos(0)
{
	collisionManager = new CollisionManager();
	AddComponent(transform = new CTransform());
}

void Object::AddChild(Object* child)
{
	childs.push_back(child);
	
	//Transform 컴포넌트에 추가된 자식의 정보를 업데이트
	transform->getChildsInfo(child);
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
	if (component->Enable(this))
	{
		components.push_back(component);
	}
	else
	{
		cout << "컴포넌트 추가 실패!" << endl;
	}
}

void Object::Start()
{
	if (!components.empty())
	{
		for (Component* src_comp : components)
		{
			src_comp->Start();
		}
	}
}
void Object::Update()
{
	if (!components.empty())
	{
		for (Component* src_comp : components)
		{
			src_comp->Update();
		}
		cout << "(" << x_pos << ", " << y_pos << ")" << endl;
	}
}

