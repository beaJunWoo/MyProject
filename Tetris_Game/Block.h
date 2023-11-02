#pragma once
#include "Header.h"
#include "DoubleBuffer.h"
#include "Map.h"
class Block
{
	int x;
	int y;
	int Index;
	vector<string> shape[28];
	Map* map;
public:
	void Initalize(Map *map);
	void Progress();
	void Render();
	void Release();
};

