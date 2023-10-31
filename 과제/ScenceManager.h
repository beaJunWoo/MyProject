#pragma once
#include "Scene.h"
#include "Menu.h"
#include "Logo.h"
#include "Stage.h"

class ScenceManager
{
	static Scene* scene;
public:
	static ScenceManager* ScenceControl;

	static ScenceManager* Get()
	{
		if (ScenceControl == nullptr)
		{
			ScenceControl = new ScenceManager;
		}
		return ScenceControl;
	}
	void Initialize(SceneId id)
	{
		if (ScenceControl != nullptr)
		{
			delete ScenceControl;
			ScenceControl = nullptr;
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
		scene->Initialize();
	}
	void Progress()
	{
		scene->Progress();
	}
	void Render()
	{
		scene->Render();
	}
	void Release()
	{
		scene->Release();
	}
};

