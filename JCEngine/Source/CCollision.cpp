#include "CCollision.h"
#include "Object.h"

void CCollision::Start()
{
}
void CCollision::Update()
{
	if (CheckCollision())
	{
		// �浹 �̺�Ʈ �߻�
		cout << "�浹 �߻�!" << endl;
	}
}
bool CCollision::CheckCollision(Object* ob1, Object* ob2)
{
	return false;
}