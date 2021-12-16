#include "CTransform.h"
#include "Object.h"

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

void CTransform::setPosition(float x, float y, float z)
{
	src_object->x_pos += x;
	src_object->y_pos += y;
	src_object->z_pos += z;

	for (Object* ptr_chd : ob_child_list)
	{
		ptr_chd->transform->setPosition(x, y, z);
	}
}

void CTransform::setScale(float x, float y, float z)
{

}
void CTransform::getChildsInfo(Object* src_ob)
{
	ob_child_list.push_back(src_ob);
}