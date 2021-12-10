#ifndef __SCENE_H__
#define __SCENE_H__ 

#include "Object.h"

#include <string>
#include <list>
using namespace std;

class Scene
{
public:
	Scene(string name);
	void loop();
	
	void AddObject(Object*);
private:
	list<Object*> objects;
	
	string scene_name;
};

#endif