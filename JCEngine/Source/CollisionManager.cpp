#include "CollisionManager.h"
#include "Object.h"

using namespace std;

CollisionManager& CollisionManager::getInstance()
{
	static CollisionManager instance;
	return instance;
}

bool CollisionManager::CheckCollision(Object* target, Direction dir, int val)
{
	// 이동하는 오브젝트가 함수를 호출.
	// 충돌을 확인할 대상, 움직이려는 방향, 이동 속도를 매개변수로 받아 계산.

	// 타겟 오브젝트의 크기 복사
	int target_left = target->x_pos;
	int target_right = target->x_pos + target->x_scale;
	int target_top = target->y_pos;
	int target_bottom = target->y_pos + target->y_scale;

	// 방향에 따른 충돌 예상지점 할당
	switch(dir)
	{
		case DIR_LEFT:
		{
			target_left = target->x_pos - val;
			break;
		}
		case DIR_RIGHT:
		{
			target_right = target->x_pos + target->x_scale + val;
			break;
		}
		case DIR_UP:
		{
			target_top = target->y_pos - val;
			break;
		}
		case DIR_DOWN:
		{
			target_bottom = target->y_pos + target->y_scale + val;
			break;
		}
		default:
		{
			break;
		}
	}

	// 충돌 체크
	for (Object* other : col_ob_list)
	{
		if (target == other)
		{
			continue;
		}
		float other_left = other->x_pos;
		float other_right = other->x_pos + other->x_scale;
		float other_top = other->y_pos;
		float other_bottom = other->y_pos + other->y_scale;

		if (target_left >= other_right)
		{
			continue;
		}
		if (target_right <= other_left)
		{
			continue;
		}
		if (target_top >= other_bottom)
		{
			continue;
		}
		if (target_bottom <= other_top)
		{
			continue;
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool CollisionManager::CustomCheckCollision(Object* ob1, Object* ob2)
{
	// 이동하는 오브젝트에서 호출하는 것이 아닌 엔진의 사용자가 호출.
	// 충돌박스를 가진 두 오브젝트에 대해 충돌여부를 확인하고자 할 때 사용.

	// 오브젝트 둘 중 하나는 꼭 충돌박스를 가져야 함.
	if (ob1->collider || ob2->collider)
	{
		int ob1_left = ob1->x_pos;
		int ob1_right = ob1->x_pos + ob1->x_scale;
		int ob1_top = ob1->y_pos;
		int ob1_bottom = ob1->y_pos + ob1->y_scale;

		int ob2_left = ob2->x_pos;
		int ob2_right = ob2->x_pos + ob2->x_scale;
		int ob2_top = ob2->y_pos;
		int ob2_bottom = ob2->y_pos + ob2->y_scale;

		if (ob1_left >= ob2_right)
		{
			return false;
		}
		if (ob1_right <= ob2_left)
		{
			return false;
		}
		if (ob1_top >= ob2_bottom)
		{
			return false;
		}
		if (ob1_bottom <= ob2_top)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return false;
}