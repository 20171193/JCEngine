#include "CTransform.h"
#include "Object.h"

#include <iostream>

using namespace std;

CTransform::CTransform() :
	src_object(NULL), ob_child_list(NULL)
{
}
CTransform::CTransform(Object* object) :
	src_object(NULL), ob_child_list(NULL)
{
	src_object = object;
}

void CTransform::Start()
{

}

void CTransform::Update()
{

}
bool CTransform::Enable(Object* object)
{
	cout << "��ġ Ȱ��ȭ" << endl;
	return true;
}

void CTransform::setPosition(float x, float y)
{
	src_object->x_pos += x;
	src_object->y_pos += y;

	for (Object* ptr_chd : ob_child_list)
	{
		ptr_chd->transform->setPosition(x, y);
	}
}

void CTransform::getChildsInfo(Object* src_ob)
{
	ob_child_list.push_back(src_ob);
}