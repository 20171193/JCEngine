#ifndef __CTRANSFORM_H__
#define __CTRANSFORM_H__

#include <list>

#include "Monobehaviour.h"
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

	void setPosition(float x, float y, float z);
	void setScale(float x, float y, float z);

	void getChildsInfo(Object* src_ob);
private:
	Object* src_object;
	list<Object*> ob_child_list;
};

#endif