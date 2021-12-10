#include "Frame.h"

Frame* Frame::instance = nullptr;

Frame* Frame::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Frame;
	}
	return instance;
}

void Frame::CalculateFrame(float dsr_frame)
{
	QueryPerformanceFrequency(&_counttime);

	_frame = _counttime.QuadPart / dsr_frame;

	QueryPerformanceCounter(&_curtime);

	_deltaTime = _curtime.QuadPart - _prevtime.QuadPart;
}

bool Frame::Update()
{
	CalculateFrame(1.0f);

	if (_deltaTime > _frame)
	{
		_prevtime = _curtime;
		return true;
	}
	else return false;
}
bool Frame::FixedUpdate()
{
	CalculateFrame(0.33f);

	if (_deltaTime > _frame)
	{
		_prevtime = _curtime;
		return true;
	}
	else return false;
}