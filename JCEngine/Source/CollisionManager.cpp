#include "CollisionManager.h"
#include "Object.h"

bool CollisionManager::CheckCollision(Object* target, Direction dir, float val)
{
	float target_left, target_right, target_top, target_bottom;

	if (dir == DIR_LEFT) 
	{
		target_left = target->x_pos - (target->col_width / 2) - val;
	}
	else
	{
		target_left = target->x_pos - (target->col_width / 2);
	}
	if (dir == DIR_RIGHT)
	{
		target_right = target->x_pos + (target->col_width / 2) + val;
	}
	else
	{
		target_right = target->x_pos + (target->col_width / 2);
	}
	if (dir == DIR_UP)
	{
		target_top = target->y_pos - (target->col_height / 2) - val;
	}
	else 
	{
		target_top = target->y_pos - (target->col_height / 2);
	}
	if (dir == DIR_DOWN)
	{
		target_bottom = target->y_pos + (target->col_height / 2) + val;
	}
	else
	{
		target_bottom = target->y_pos + (target->col_height / 2);
	}


	for (Object* other : col_ob_list)
	{
		float other_left = other->x_pos - (other->col_width / 2);
		float other_right = other->x_pos + (other->col_width / 2);
		float other_top = other->y_pos - (other->col_height / 2);
		float other_bottom = other->y_pos + (other->col_height / 2);

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