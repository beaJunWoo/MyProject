#pragma once
#include "Scenes.h"
#include "Map.h"
#include "Block.h"
class Stage:public Scenes
{
	Map* map;
	Block* block;
public:
	virtual void Initalize()override;
	virtual void Progress()override;
	virtual void Render()override;
	virtual void Release()override;
};

