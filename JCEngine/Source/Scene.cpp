
// 씬 - 오브젝트 - 컴포넌트 구조
// 씬 실행 
//  -> 오브젝트 실행
//    -> 컴포넌트 실행

#include "Scene.h"
#include "Frame.h"

using namespace std;

Scene::Scene(string name)
{
	scene_name = name;
}

void Scene::AddObject(Object* object)
{
	// 씬에 오브젝트 등록
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

