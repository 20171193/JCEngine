#include <iostream>

#include "CTransform.h"
#include "Object.h"

using namespace std;

CTransform::CTransform() :
	src_object(NULL), ob_child_list(NULL)
{
}
CTransform::CTransform(Object* object) :
	src_object(NULL), ob_child_list(NULL)
{
	// 모든 오브젝트는 기본적으로 Transform을 가진다.
	// -> 오브젝트의 생성자에서 Transfrom을 생성
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
	return true;
}

void CTransform::setPosition(int x, int y, Object* object)
{
	// 오브젝트의 위치값을 변경하는 함수
	// 받아온 x, y는 해당 오브젝트의 지역좌표 이동값.

	src_object = object;

	src_object->x_pos += x;
	src_object->y_pos += y;

	for (Object* ptr_chd : ob_child_list)
	{
		ptr_chd->transform->setPosition(x, y, ptr_chd);
	}
}
void CTransform::setScale(int x, int y, Object* object)
{
	src_object = object;

	src_object->x_scale = x;
	src_object->y_scale = y;
}

void CTransform::getChildsInfo(Object* src_ob)
{
	ob_child_list.push_back(src_ob);
}