#include "Frame.h"

Frame& Frame::getInstance()
{
	static Frame instance;
	return instance;
}

void Frame::CalculateFrame(float dsr_frame)
{
	// �ʴ� ����
	QueryPerformanceFrequency(&_counttime);

	// �ʴ� ������ ���� ����
	_frame = _counttime.QuadPart / dsr_frame;

	// �ʴ� ī��Ʈ
	QueryPerformanceCounter(&_curtime);

	// ���� �ð�
	_deltaTime = _curtime.QuadPart - _prevtime.QuadPart;
}

bool Frame::Update()
{
	// �� �����Ӹ��� ȣ��� - 1�ʿ� �� �� ����
	CalculateFrame(1.0f);

	if (_deltaTime > _frame)
	{
		// ������ ����
		_prevtime = _curtime;
		return true;
	}
	else return false;
}
bool Frame::FixedUpdate()
{
	// �׽�Ʈ�� : 3�ʿ� �� ���� ����ǰ� ����
	// �ݺ��Ǵ� �ڷ�ƾ���� �ٲ㵵 ����?
	CalculateFrame(0.33f);

	if (_deltaTime > _frame)
	{
		// ������ ����
		_prevtime = _curtime;
		return true;
	}
	else return false;
}