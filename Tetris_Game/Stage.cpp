#include "Stage.h"
#include "DoubleBuffer.h"
void Stage::Initalize()
{
	map = new Map;
	block = new Block;

	map->Initalize();
	block->Initalize(map);
}

void Stage::Progress()
{
	map->Progress();
	block->Progress();
}

void Stage::Render()
{
	DoubleBuffer::Get()->WriteBuffer(1, 1, "Stage", WHITE);
	map->Render();
	block->Render();
}

void Stage::Release()
{
	map->Release();
	delete map;
	map = nullptr;

	block->Release();
	delete block;
	block = nullptr;
}
