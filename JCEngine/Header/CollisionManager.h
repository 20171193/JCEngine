#ifndef __COLLISION_MANAGER_H__
#define __COLLISION_MANAGER_H__

#include <list>

using namespace std;

enum Direction
{
	DIR_LEFT,
	DIR_RIGHT,
	DIR_UP,
	DIR_DOWN
};

class Object;

class CollisionManager
{
public:
	bool CheckCollision(Object* target, Direction dir, float val);

	list<Object*> col_ob_list;	// 콜라이더를 가진 모든 오브젝트
};

#endif