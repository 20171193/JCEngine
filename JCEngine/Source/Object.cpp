#include "Object.h"

Object::Object(string name) :
	collider(false),
	x_pos(0),
	y_pos(0),
	x_scale(50),
	y_scale(50)
{
	ob_name = name;
	AddComponent(transform = new CTransform());
}

void Object::Start()
{
	if (!ob_image.empty())
	{
		TextureManager::getInstance().LoadImage(ob_image, ob_name);
	}

	// 추가된 컴포넌트들 Start
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
	if (!ob_image.empty())
	{
		TextureManager::getInstance().DrawImage(ob_image, ob_name, x_pos, y_pos, x_scale, y_scale
		);
	}
	// 추가된 컴포넌트들 Update
	if (!components.empty())
	{
		for (Component* src_comp : components)
		{
			src_comp->Update();
		}
	}
}
void Object::AddImage(string img_file)
{
	ob_image = img_file;
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


