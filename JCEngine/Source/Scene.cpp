#include "Scene.h"

Scene::Scene()
{
}

void Scene::AddObject(Object* object)
{
	objects.push_back(object);
}

void Scene::Start()
{
	if (!objects.empty())
	{
		for (Object* ob : objects)
		{
			ob->Start();
		}
	}
}
void Scene::Update()
{
	if (!objects.empty())
	{
		for (Object* ob : objects)
		{
			ob->Update();
		}
	}
}

