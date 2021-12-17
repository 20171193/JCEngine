#include "CCollision.h"
#include "CollisionManager.h"
#include "Object.h"

void CCollision::Start()
{
}
void CCollision::Update()
{
}
bool CCollision::Enable(Object* object)
{
	//src_ob = object;
	//// 해당 오브젝트의 충돌박스 활성화
	//src_ob->collider = true;
	//src_ob->collisionManager->col_ob_list.push_back(src_ob);

	return true;
}

void CCollision::setColliderScale(float horizontal, float vertical)
{
	src_ob->col_width += horizontal;
	src_ob->col_height += vertical;
}
