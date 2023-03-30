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

	// 해당 오브젝트의 콜리전 활성화
	src_ob->collider = true;

	// 콜리전매니저에 오브젝트 등록 (리스트 추가 - 충돌이 활성화 된 오브젝트)
	CollisionManager::getInstance().col_ob_list.push_back(src_ob);

	return true;
}

void CCollision::destroyComponent()
{
	// 콜리전 비활성화
	src_ob->collider = false;

	list<Object*>::iterator iter = CollisionManager::getInstance().col_ob_list.begin();

	// 콜리전매니저에 등록된 오브젝트 삭제
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