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
	src_ob = object;
	// �ش� ������Ʈ�� �浹�ڽ� Ȱ��ȭ
	src_ob->collider = true;
	CollisionManager::getInstance().col_ob_list.push_back(src_ob);

	return true;
}
