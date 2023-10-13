#pragma once
#include "Obj.h"
#include "Map.h"

class Engine
{
	class Obj* obj;
	class Map* maps;
	int speed;
	int moveTimeMax;
	int moveTimeNow;
public:
	Engine(Obj* obj_)
	{
		obj = obj_;
		moveTimeMax = 0;
		moveTimeNow = 0;
	}
	void Move(int left_KeyPad, int right_KeyPad, int speed);
	void Move(int left_KeyPad, int right_KeyPad, int up_KeyPad, int down_KeyPad, int speed);
	void SetMap(Map* map_) { maps = map_; };
	void Show_Infomation();
};