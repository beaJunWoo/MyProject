#include "BlockManager.h"

void BlockManager::Initalize(Map*map)
{
	this->map = map;
	block = new Block;
}

void BlockManager::Progress()
{
	if (block != nullptr)
	{
		if (!block->GetIs_Act())
		{
			DoubleBuffer::Get()->WriteBuffer(2, 2, "삭제 되었습니다.", WHITE);
			delete block;
			block = nullptr;
		}
	}
	int random=0;
	
	if(block ==nullptr)
	{
		random = rand() % 7;
		block = new Block;
		block->Initalize(map, random);
		DoubleBuffer::Get()->WriteBuffer(5, 5, to_string(random).c_str(), WHITE);
	}
	block->Progress();
}

void BlockManager::Render()
{
	if (block != nullptr)
	{
		block->Render();
	}
	
}

void BlockManager::Release()
{
	if (block != nullptr)
	{
		block->Release();
	}
}
