#ifndef __FRAME_H__
#define __FRAME_H__

#include <Windows.h>

class Frame
{
// singleton
public:
	static Frame* GetInstance();
private:
	Frame() {}
	static Frame* instance;
// end singleton

public:
	void CalculateFrame(float dsr_frame);

	bool Update();
	bool FixedUpdate();

private:
	LARGE_INTEGER _curtime;
	LARGE_INTEGER _prevtime;
	LARGE_INTEGER _counttime;

	float _frame;
	float _deltaTime;
};

#endif
