#include "ScenesManager.h"

ScenesManager* ScenesManager::scenesManager = nullptr;

bool ScenesManager::FinishGame = false;

void ScenesManager::Initalize(SceneId id)
{

	if (scene != nullptr)
	{
		Release();
		delete scene;
		scene = nullptr;
	}
	
	switch (id)
	{
	case MENU:
		scene = new Menu;
		break;
	case LOGO:
		scene = new Logo;
		break;
	case STAGE:
		scene = new Stage;
		break;
	case RANKING:
		scene = new Ranking;
		break;
	case EXIT:
		FinishGame = true;
		break;
	default:
		break;
	}
	if (!FinishGame) {
		scene->Initalize();
	}
	
}

void ScenesManager::Progress()
{
	if(scene!=nullptr)
		scene->Progress();
}

void ScenesManager::Render()
{
	if (scene != nullptr)
		scene->Render();
}

void ScenesManager::Release()
{
	if (scene != nullptr)
	{
	delete scene;
	scene = nullptr;
	}
}
