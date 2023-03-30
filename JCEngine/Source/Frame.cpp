#include "Frame.h"

Frame& Frame::getInstance()
{
	static Frame instance;
	return instance;
}

void Frame::CalculateFrame(float dsr_frame)
{
	// 초당 정보
	QueryPerformanceFrequency(&_counttime);

	// 초당 프레임 간격 설정
	_frame = _counttime.QuadPart / dsr_frame;

	// 초당 카운트
	QueryPerformanceCounter(&_curtime);

	// 실제 시간
	_deltaTime = _curtime.QuadPart - _prevtime.QuadPart;
}

bool Frame::Update()
{
	// 매 프레임마다 호출됨 - 1초에 한 번 실행
	CalculateFrame(1.0f);

	if (_deltaTime > _frame)
	{
		// 프레임 갱신
		_prevtime = _curtime;
		return true;
	}
	else return false;
}
bool Frame::FixedUpdate()
{
	// 테스트용 : 3초에 한 번씩 실행되게 설정
	// 반복되는 코루틴으로 바꿔도 될지?
	CalculateFrame(0.33f);

	if (_deltaTime > _frame)
	{
		// 프레임 갱신
		_prevtime = _curtime;
		return true;
	}
	else return false;
}