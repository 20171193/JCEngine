#include "GameManager.h"

using namespace std;

GameManager::GameManager() : 
	engine(NULL),
	src_scene(NULL)
{
	// �⺻ ���ӸŴ��� ���� - ������ â�� ũ�Ⱑ �⺻ ũ��(640, 480)�� ����.

	engine = new Engine();

	if(!engine->Init(640, 480))	// �⺻ ũ��� ����.
	{
		cout << " ���� ���� ����! " << endl << " ������ �����մϴ�. " <<endl;
		delete engine;
	}
}
GameManager::GameManager(int win_width, int win_height) : 
	engine(NULL),
	src_scene(NULL)
{
	// Ŀ���� ���ӸŴ��� ���� - â�� ũ�⸦ ������ ����

	engine = new Engine();

	if (!engine->Init(win_width, win_height)) // Ŀ���� ũ��
	{
		cout << " ���� ���� ����! " << endl << " ������ �����մϴ�. " << endl;
		delete engine;
	}
}

Scene* GameManager::GetScene()
{
	if (src_scene == NULL)
	{
		cout << " �� �ε� ���� " << endl;
		return NULL;
	}

	return src_scene;
}
void GameManager::OpenScene(Scene* scene)
{
	// �� �ε�
	GetScene()->Start();
}
void GameManager::SetGame()
{
	// ����(����) �ʱ� ����
	if (engine != NULL && src_scene != NULL)
	{
		engine->Set();
	}
}
void GameManager::RenderGame()
{
	// ȭ�� ������
	if (engine != NULL && src_scene != NULL)
	{
		engine->Render();
	}
}
void GameManager::QuitGame()
{
	engine->Quit();
}
