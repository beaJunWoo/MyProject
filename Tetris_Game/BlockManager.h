#pragma once
#include "Block.h"
class BlockManager
{
	Block* block;
	
public:
	void Initalize();
	void Progress();
	void Render();
	void Release();
};

