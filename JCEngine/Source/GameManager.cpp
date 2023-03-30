#include "GameManager.h"

using namespace std;

GameManager::GameManager() : 
	engine(NULL),
	src_scene(NULL)
{
	// 기본 게임매니저 생성 - 윈도우 창의 크기가 기본 크기(640, 480)로 설정.

	engine = new Engine();

	if(!engine->Init(640, 480))	// 기본 크기로 설정.
	{
		cout << " 엔진 세팅 오류! " << endl << " 게임을 종료합니다. " <<endl;
		delete engine;
	}
}
GameManager::GameManager(int win_width, int win_height) : 
	engine(NULL),
	src_scene(NULL)
{
	// 커스텀 게임매니저 생성 - 창의 크기를 유저가 설정

	engine = new Engine();

	if (!engine->Init(win_width, win_height)) // 커스텀 크기
	{
		cout << " 엔진 세팅 오류! " << endl << " 게임을 종료합니다. " << endl;
		delete engine;
	}
}

Scene* GameManager::GetScene()
{
	if (src_scene == NULL)
	{
		cout << " 씬 로드 실패 " << endl;
		return NULL;
	}

	return src_scene;
}
void GameManager::OpenScene(Scene* scene)
{
	// 씬 로드
	GetScene()->Start();
}
void GameManager::SetGame()
{
	// 게임(엔진) 초기 세팅
	if (engine != NULL && src_scene != NULL)
	{
		engine->Set();
	}
}
void GameManager::RenderGame()
{
	// 화면 렌더링
	if (engine != NULL && src_scene != NULL)
	{
		engine->Render();
	}
}
void GameManager::QuitGame()
{
	engine->Quit();
}
