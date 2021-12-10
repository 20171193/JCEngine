#ifndef __C_MOVEABLE_H__
#define __C_MOVEABLE_H__

class CMoveable : public Component
{

public:
	void SetMove(int left, int right, int up, int down);
};

#endif