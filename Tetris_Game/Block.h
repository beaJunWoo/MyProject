#pragma once
#include "Header.h"
#include "DoubleBuffer.h"
#include "Map.h"
class Block
{
	int x;
	int y;
	int Index;
	int ChangeIndex;
	bool is_Act;
	vector<string> shape[28];
	Map* map;

	//µÙ∑π¿Ã 
	int Fall_DelayTime;
	int Fall_NowTime;

	const int ChangeShape_DelayTime=20;
	int ChangeShape_NowTime;

	const int Move_DelayTime =3;
	int Move_NowTIme;

public:
	bool GetIs_Act() { return is_Act; }

	void Initalize(Map *map, int index);
	void Progress();
	void Render();
	void Release();
};

