#include "Map.h"
#include "SetPos.h"
#include "SetPos.h"

vector<string> Map::GetMap() { return map; }

void Map::Show()
{
	SetPos s;
	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map[y].size(); x++)
		{
			
			s.SetPosition(x, y);
			switch (map[y][x])
			{
			case '1':
				cout << "бс";
				break;
			default:
				break;
			}
		}
	}
}
