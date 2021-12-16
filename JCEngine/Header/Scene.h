#ifndef __SCENE_H__
#define __SCENE_H__ 

#include <string>
#include <list>

#include "Object.h"

using namespace std;

class Scene
{
public:
	Scene();
	void loop();
	
	void AddObject(Object*);
private:
	list<Object*> objects;
	
	string scene_name;
};

#endif