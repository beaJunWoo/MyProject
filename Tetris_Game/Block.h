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
	Color color;
	bool fastFall;
	vector<string> shape[28];
	Map* map;


	//������ 
	int Push_DelayTime; //�Է� ���� ������
	int push_NowTime;

	int Fall_DelayTime; //���� ������
	int Fall_NowTime;
	int Defalt_Fall_DelayTime;

	const int ChangeShape_DelayTime=15;
	int ChangeShape_NowTime;

	int Push_MoveDelay;
	int Push_MoveNow;

	int Move_DelayTime =6;
	int Move_NowTIme;

public:
	bool GetIs_Act() { return is_Act; }
	vector<string> GetShape(int index) { return shape[index]; }
	
	void Set_FallDelayTime(int time) { Defalt_Fall_DelayTime = time; }

	void Initalize(Map *map, int index);
	void Progress();
	void Render();
	void Release();
};

