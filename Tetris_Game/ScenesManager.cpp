#include "ScenesManager.h"

ScenesManager* ScenesManager::scenesManager = nullptr;

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
	default:
		break;
	}
	scene->Initalize();
}

void ScenesManager::Progress()
{
	scene->Progress();
}

void ScenesManager::Render()
{
	scene->Render();
}

void ScenesManager::Release()
{
	delete scene;
	scene = nullptr;
}
