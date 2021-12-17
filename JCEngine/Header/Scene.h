#ifndef __SCENE_H__
#define __SCENE_H__ 

#include <string>
#include <list>

#include "Monobehaviour.h"
#include "Object.h"

using namespace std;

class Scene : public Monobehaviour
{
public:
	Scene();
	
	virtual void Start();
	virtual void Update();

	void AddObject(Object*);
private:
	list<Object*> objects;
	
	string scene_name;
};

#endif