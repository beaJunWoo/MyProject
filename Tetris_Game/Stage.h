#pragma once
#include "Scenes.h"
#include "Map.h"
#include "BlockManager.h"
class Stage:public Scenes
{
	Map* map;
	BlockManager* blockManager;
public:
	virtual void Initalize()override;
	virtual void Progress()override;
	virtual void Render()override;
	virtual void Release()override;
};

