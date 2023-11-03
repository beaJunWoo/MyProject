#pragma once
#include "Block.h"
#include "Map.h"
class BlockManager
{
	Block* block;
	Map* map;
	int NextBlock;

	int LV;
	int Defalt_Fall_DelayTime;
	int Time;
public:
	void Initalize(Map* map);
	void Progress();
	void Render();
	void Release();
};

