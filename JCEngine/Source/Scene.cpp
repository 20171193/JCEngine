#include "Scene.h"

Scene::Scene()
{
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