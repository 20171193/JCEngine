#include "CollisionManager.h"
#include "Object.h"

CollisionManager& CollisionManager::getInstance()
{
	static CollisionManager instance;
	return instance;
}

bool CollisionManager::CheckCollision(Object* target, Direction dir, int val)
{
	int target_left = target->x_pos;
	int target_right = target->x_pos + target->x_scale;
	int target_top = target->y_pos;
	int target_bottom = target->y_pos + target->y_scale;

	switch (dir)
	{
	case DIR_LEFT:
		target_left = target->x_pos - val;
		break;
	case DIR_RIGHT:
		target_right = target->x_pos + target->x_scale + val;
		break;
	case DIR_UP:
		target_top = target->y_pos - val;
		break;
	case DIR_DOWN:
		target_bottom = target->y_pos + target->y_scale + val;
		break;
	default:
		break;
	}

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