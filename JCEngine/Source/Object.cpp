#include "Object.h"
#include "Frame.h"

using namespace std;

Object::Object(string name) :
	collider(false),
	x_pos(0),
	y_pos(0),
	x_scale(50),
	y_scale(50)
{
	// 생성된 모든 오브젝트는 Transform을 가지고 Transform은 기본 값으로 설정됨.

	ob_name = name;
	AddComponent(transform = new CTransform());
}

void Object::Start()
{
	if (!ob_image.empty())
	{
		TextureManager::getInstance().Loadimage(ob_image, ob_name);
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
		// 오브젝트 이미지 렌더링
		TextureManager::getInstance().Drawimage(ob_image, ob_name, x_pos, y_pos, x_scale, y_scale);
	}
	
	// 추가된 컴포넌트들 Update
	if (Frame::getInstance().Update() && !components.empty())
	{
		for (Component* src_comp : components)
		{
			src_comp->Update();
		}
	}
}

void Object::AddImage(string img_file)
{
	// 오브젝트 이미지 추가 (string 파일명)
	ob_image = img_file;
}

void Object::AddChild(Object* child)
{
	childs.push_back(child);
	
	//Transform 컴포넌트에 추가된 자식의 정보를 업데이트
	transform->getChildsInfo(child);
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


