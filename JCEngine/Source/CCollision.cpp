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

	// �ش� ������Ʈ�� �ݸ��� Ȱ��ȭ
	src_ob->collider = true;

	// �ݸ����Ŵ����� ������Ʈ ��� (����Ʈ �߰� - �浹�� Ȱ��ȭ �� ������Ʈ)
	CollisionManager::getInstance().col_ob_list.push_back(src_ob);

	return true;
}

void CCollision::destroyComponent()
{
	// �ݸ��� ��Ȱ��ȭ
	src_ob->collider = false;

	list<Object*>::iterator iter = CollisionManager::getInstance().col_ob_list.begin();

	// �ݸ����Ŵ����� ��ϵ� ������Ʈ ����
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