#include "Stage.h"
#include "DoubleBuffer.h"
void Stage::Initalize()
{
	map = new Map;
	blockManager = new BlockManager;

	map->Initalize();
	blockManager->Initalize(map);
}

void Stage::Progress()
{
	map->Progress();
	blockManager->Progress();
}

void Stage::Render()
{
	DoubleBuffer::Get()->WriteBuffer(1, 1, "Stage", WHITE);
	map->Render();
	blockManager->Render();
}

void Stage::Release()
{
	map->Release();
	delete map;
	map = nullptr;

	blockManager->Release();
	delete blockManager;
	blockManager = nullptr;
}
