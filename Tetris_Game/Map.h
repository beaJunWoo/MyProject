#pragma once
#include "Header.h"
#include "DoubleBuffer.h"
class Map
{
	vector<string> shape;
public:
	vector<string> GetMap() { return shape; }
	void Initalize();
	void Progress();
	void Render();
	void Release();
};

