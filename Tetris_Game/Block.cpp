#include "Block.h"
#include <ctime>

void Block::Initalize(Map* map, int index)
{
	Fall_DelayTime = 20;
	Fall_NowTime = 0;

	ChangeShape_NowTime=0;
	Move_NowTIme = 0;

	is_Act = true;
	Index = index*4;
	ChangeIndex = 0;
	x = 5;
	y = 0;

//┌ 블럭	
#pragma region Shapeㄱ(R:)
	
	shape[0].push_back("11");
	shape[0].push_back("10");
	shape[0].push_back("10");

	shape[1].push_back("000");
	shape[1].push_back("111");
	shape[1].push_back("001");

	shape[2].push_back("01");
	shape[2].push_back("01");
	shape[2].push_back("11");

	shape[3].push_back("00");
	shape[3].push_back("10");
	shape[3].push_back("111");
#pragma endregion

//┐ 블럭	
#pragma region Shapeㄱ
	
	shape[4].push_back("11");
	shape[4].push_back("01");
	shape[4].push_back("01");

	shape[5].push_back("000");
	shape[5].push_back("001");
	shape[5].push_back("111");

	shape[6].push_back("10");
	shape[6].push_back("10");
	shape[6].push_back("11");

	shape[7].push_back("000");
	shape[7].push_back("111");
	shape[7].push_back("100");
#pragma endregion

//| 블럭	
#pragma region Shape|
	
	shape[8].push_back("1");
	shape[8].push_back("1");
	shape[8].push_back("1");
	shape[8].push_back("1");

	shape[9].push_back("");
	shape[9].push_back("");
	shape[9].push_back("1111");

	shape[10].push_back("1");
	shape[10].push_back("1");
	shape[10].push_back("1");
	shape[10].push_back("1");

	shape[11].push_back("");
	shape[11].push_back("");
	shape[11].push_back("1111");
#pragma endregion

//ㅁ블럭
#pragma region Shapeㅁ
	
	shape[12].push_back("");
	shape[12].push_back("11");
	shape[12].push_back("11");

	shape[13].push_back("");
	shape[13].push_back("11");
	shape[13].push_back("11");

	shape[14].push_back("");
	shape[14].push_back("11");
	shape[14].push_back("11");

	shape[15].push_back("");
	shape[15].push_back("11");
	shape[15].push_back("11");
#pragma endregion

// Z블럭(좌우반전)
#pragma region ShapeZ(R:)
	
	shape[16].push_back("10");
	shape[16].push_back("11");
	shape[16].push_back("01");

	shape[17].push_back("000");
	shape[17].push_back("011");
	shape[17].push_back("110");

	shape[18].push_back("10");
	shape[18].push_back("11");
	shape[18].push_back("01");

	shape[19].push_back("000");
	shape[19].push_back("011");
	shape[19].push_back("110");
#pragma endregion

// Z블럭
#pragma region ShapeZ

	shape[20].push_back("01");
	shape[20].push_back("11");
	shape[20].push_back("10");

	shape[21].push_back("000");
	shape[21].push_back("110");
	shape[21].push_back("011");

	shape[22].push_back("01");
	shape[22].push_back("11");
	shape[22].push_back("10");

	shape[23].push_back("000");
	shape[23].push_back("110");
	shape[23].push_back("011");
#pragma endregion

//T 블럭
#pragma region Shapeㅏ

	shape[24].push_back("10");
	shape[24].push_back("11");
	shape[24].push_back("10");

	shape[25].push_back("000");
	shape[25].push_back("111");
	shape[25].push_back("010");

	shape[26].push_back("01");
	shape[26].push_back("11");
	shape[26].push_back("01");

	shape[27].push_back("000");
	shape[27].push_back("010");
	shape[27].push_back("111");
#pragma endregion
	this->map = map;
}

void Block::Progress()
{
	int Idx = Index + ChangeIndex;
	//블럭이 공중에 있어서 컨트롤이 가능할때
	if (map->GetMap()[y + shape[Idx].size()][x] < '1')
	{
		
		//떨어지는 속도 조절을 위해 딜레이타임 설정

		//낙하
		Fall_NowTime++;
		if (Fall_DelayTime <= Fall_NowTime) { y++; Fall_NowTime = 0; }
		
		//모양 변경
		ChangeShape_NowTime++;
		if (GetAsyncKeyState(VK_SPACE) && ChangeShape_NowTime>= ChangeShape_DelayTime)
		{
			ChangeIndex++;
			if (ChangeIndex > 3) { ChangeIndex = 0; }
			ChangeShape_NowTime = 0;
		}

		//좌우 이동
		Move_NowTIme++;
		if (GetAsyncKeyState(VK_LEFT) && x> 1 && Move_NowTIme>=Move_DelayTime)
		{
			x--;
			Move_NowTIme = 0;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			int max = 0;
			for (int i = 0; i < shape[Idx].size(); i++)
			{
				if (max <shape[Idx][i].size()) { max = shape[Idx][i].size(); }
			}
			DoubleBuffer::Get()->WriteBuffer(3, 3, to_string(max).c_str(), WHITE);
			if (x + max < 11 && Move_NowTIme >= Move_DelayTime)
			{
				
				x++;
				Move_NowTIme = 0;
			}
			
		}
	}
	else { //블럭이 바닥에 맞닿았을경우
		for (int y = 0; y < shape[Idx].size(); y++)
		{
			for (int x = 0; x < shape[Idx][y].size(); x++)
			{
				switch (shape[Idx][y][x])
				{
				case '1':
					map->SetMap(x + this->x, y + this->y, '2');
					break;
				default:
					break;
				}
			}
		}
		is_Act = false;
	}
}

void Block::Render()
{
	int Idx = Index + ChangeIndex;
	if(is_Act){
		for (int y = 0; y < shape[Idx].size(); y++)
		{
			for (int x = 0; x < shape[Idx][y].size(); x++)
			{
				switch (shape[Idx][y][x])
				{
				case '1':
					DoubleBuffer::Get()->WriteBuffer(x + this->x, y + this->y, "□", WHITE);
					break;
				default:
					break;
				}
			}
		}
	}
	
}

void Block::Release()
{
}
