#include "Map.h"
void Map::SetMap(int x, int y, char c)
{
	shape[y][x] = c;
}
void Map::Initalize()
{
	shape.push_back("111111111111");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("100000000001");
	shape.push_back("111111111111");
}

void Map::Progress()
{
}

void Map::Render()
{
	for (int y = 0; y < shape.size(); y++)
	{
		for (int x = 0; x < shape[y].size(); x++)
		{
			switch (shape[y][x])
			{
			case '1':
				DoubleBuffer::Get()->WriteBuffer(x, y, "бр", WHITE);
				break;
			case '2':
				DoubleBuffer::Get()->WriteBuffer(x, y, "бр", RED);
				break;
			default:
				break;
			}
		}
	}
}

void Map::Release()
{
}
