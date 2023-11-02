#include "Block.h"
#include <ctime>

void Block::Initalize(Map* map)
{
	is_Act = true;
	Index = rand()%6*4;
	x = 5;
	y = 10;

	//격자 블록
#pragma region Shape1
	
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
	
#pragma region Shape2

	shape[4].push_back("10");
	shape[4].push_back("111");
	shape[4].push_back("001");

	shape[5].push_back("011");
	shape[5].push_back("010");
	shape[5].push_back("110");

	shape[6].push_back("10");
	shape[6].push_back("111");
	shape[6].push_back("001");

	shape[7].push_back("011");
	shape[7].push_back("010");
	shape[7].push_back("110");
#pragma endregion
	
#pragma region Shape3

	shape[8].push_back("11");
	shape[8].push_back("10");
	shape[8].push_back("10");

	shape[9].push_back("000");
	shape[9].push_back("111");
	shape[9].push_back("001");

	shape[10].push_back("01");
	shape[10].push_back("01");
	shape[10].push_back("11");

	shape[11].push_back("00");
	shape[11].push_back("10");
	shape[11].push_back("111");
#pragma endregion

#pragma region Shape4

	shape[12].push_back("11");
	shape[12].push_back("10");
	shape[12].push_back("10");

	shape[13].push_back("000");
	shape[13].push_back("111");
	shape[13].push_back("001");

	shape[14].push_back("01");
	shape[14].push_back("01");
	shape[14].push_back("11");

	shape[15].push_back("00");
	shape[15].push_back("10");
	shape[15].push_back("111");
#pragma endregion

#pragma region Shape5

	shape[16].push_back("11");
	shape[16].push_back("10");
	shape[16].push_back("10");

	shape[17].push_back("000");
	shape[17].push_back("111");
	shape[17].push_back("001");

	shape[18].push_back("01");
	shape[18].push_back("01");
	shape[18].push_back("11");

	shape[19].push_back("00");
	shape[19].push_back("10");
	shape[19].push_back("111");
#pragma endregion
#pragma region Shape6

	shape[20].push_back("11");
	shape[20].push_back("10");
	shape[20].push_back("10");

	shape[21].push_back("000");
	shape[21].push_back("111");
	shape[21].push_back("001");

	shape[22].push_back("01");
	shape[22].push_back("01");
	shape[22].push_back("11");

	shape[23].push_back("00");
	shape[23].push_back("10");
	shape[23].push_back("111");
#pragma endregion
#pragma region Shape7

	shape[24].push_back("11");
	shape[24].push_back("10");
	shape[24].push_back("10");

	shape[25].push_back("000");
	shape[25].push_back("111");
	shape[25].push_back("001");

	shape[26].push_back("01");
	shape[26].push_back("01");
	shape[26].push_back("11");

	shape[27].push_back("00");
	shape[27].push_back("10");
	shape[27].push_back("111");
#pragma endregion
	this->map = map;
}

void Block::Progress()
{
	if (map->GetMap()[y + shape[Index].size()][x] != '1')
	{
		y++;
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (Index % 7 == 0){ Index -= 3; }
			else { Index++; }
		}
	}
	else {
		for (int y = 0; y < shape[Index].size(); y++)
		{
			for (int x = 0; x < shape[y].size(); x++)
			{
			
				map->GetMap()[y][x] = '2';

			}
		}
		is_Act = false;
	}
}

void Block::Render()
{
	if(is_Act){}
	for (int y = 0; y < shape[Index].size(); y++)
	{
		for (int x = 0; x < shape[y].size(); x++)
		{
			switch (shape[Index][y][x])
			{
			case '1':
				DoubleBuffer::Get()->WriteBuffer(x+this->x, y+this->y, "□", WHITE);
				break;
			default:
				break;
			}
		}
	}
}

void Block::Release()
{
}
