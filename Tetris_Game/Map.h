#pragma once
#include "Header.h"
#include "DoubleBuffer.h"
class Map
{
	vector<string> shape;
public:
	vector<string> GetMap() { return shape; }
	vector<string>& GetMapReference(){ return shape; }
	void SetMap(int x, int y, char c);
	void Initalize();
	void Progress();
	void Render();
	void Release();
};

