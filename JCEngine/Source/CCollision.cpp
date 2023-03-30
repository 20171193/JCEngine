#include <list>

#include "CCollision.h"
#include "CollisionManager.h"
#include "Object.h"

using namespace std;

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

void CCollision::destroyComponent()
{
	src_ob->collider = false;
	list<Object*>::iterator iter = CollisionManager::getInstance().col_ob_list.begin();
	for (
		iter = CollisionManager::getInstance().col_ob_list.begin();
		iter != CollisionManager::getInstance().col_ob_list.end();
		iter++
		)
	{
		if (src_ob == (*iter))
		{
			CollisionManager::getInstance().col_ob_list.erase(iter);
		}
	}
}