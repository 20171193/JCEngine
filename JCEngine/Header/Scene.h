#ifndef __SCENE_H__
#define __SCENE_H__ 

#include <string>
#include <list>

#include "Monobehaviour.h"
#include "Object.h"

class Scene : public Monobehaviour
{
public:
	Scene(std::string name);
	
	virtual void Start();
	virtual void Update();

	void AddObject(Object*);
private:
	std::list<Object*> objects;
	
	std::string scene_name;
};

#endif