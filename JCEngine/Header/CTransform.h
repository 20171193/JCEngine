#ifndef __CTRANSFORM_H__
#define __CTRANSFORM_H__

#include <list>

#include "Component.h"

class Object;

using namespace std;

class CTransform : public Component
{
public:
	CTransform();
	CTransform(Object* src_ob);


	virtual void Start();
	virtual void Update();
	virtual bool Enable(Object* object);

	void setPosition(float x, float y);

	void getChildsInfo(Object* src_ob);

private:
	Object* src_object;
	list<Object*> ob_child_list;
};

#endif