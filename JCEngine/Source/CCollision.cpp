#include "CCollision.h"
#include "Object.h"

void CCollision::Start()
{
}
void CCollision::Update()
{
	if (CheckCollision())
	{
		// 충돌 이벤트 발생
		cout << "충돌 발생!" << endl;
	}
}
bool CCollision::CheckCollision(Object* ob1, Object* ob2)
{
	return false;
}