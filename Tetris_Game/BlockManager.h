#pragma once
#include "Block.h"
#include "Map.h"
class BlockManager
{
	Block* block;
	Map* map;
public:
	void Initalize(Map* map);
	void Progress();
	void Render();
	void Release();
};

