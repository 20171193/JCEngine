#ifndef __MONOBEHAVIOUR_H__
#define __MONOBEHAVIOUR_H__

#include <Windows.h>

class Monobehaviour
{
public:
	virtual ~Monobehaviour() {};

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() {};

};

#endif 