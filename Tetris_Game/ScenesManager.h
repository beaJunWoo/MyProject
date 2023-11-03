#pragma once
#include "Scenes.h"
#include "Header.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "Ranking.h"
#include "DataBase.h"
class ScenesManager
{
	Scenes* scene = nullptr;
	static ScenesManager* scenesManager;
	DataBase database;
public:
	DataBase& GetDataBase() { return database; }
	static ScenesManager* Get()
	{
		if (scenesManager == nullptr)
		{
			scenesManager = new ScenesManager;
		}
		return scenesManager;
	}
	void Initalize(SceneId id);
	void Progress();
	void Render();
	void Release();
};

