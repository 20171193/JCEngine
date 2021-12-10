#include "Scene.h"

Scene::Scene(string name)
{
	scene_name;
}

void Scene::AddObject(Object* object)
{
	objects.push_back(object);
}

void Scene::loop()
{
	
	for (Object* ob : objects)
	{
		ob->Start();
	}
	while (1)
	{
		for (Object* ob : objects)
		{
			ob->Update();
		}
	}

}