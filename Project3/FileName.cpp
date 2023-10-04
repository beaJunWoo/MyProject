#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#define MapX 40
#define MapY 40
#define RIGHT x+1
#define LEFT x-1
#define UP y-1
#define DOWN y+1

#pragma region DoubleBuffer
#define BufferWidth 120
#define BufferHeight 60

HANDLE hBuffer[2];
int screenIndex;

void InitBuffer();
void FlipBuffer();
void ClearBuffer();
void WriteBuffer(int x, int y, const char* shape, int color);
void ReleaseBuffer();
#pragma endregion

int map[MapY][MapX] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
int Cpy_Map[MapY][MapX] = {};

struct Obj
{
	int x, y;
	int MoveNum;
	const char* shape;
};
Obj* player;
Obj* enemy;
Obj* bullet;

char d;
#pragma region MapResearch
void CPY_Map();
void Map_AllClear();
void Map_Change();
void Map_Clear();
#pragma endregion

#pragma region Render
void Render_Map();
void Render_Player();
void Render_enemy();
void Render_Bullet();
#pragma endregion


#pragma region Move
void Move_Player();
void Move_Bullet();
void Move_Enemy();
#pragma endregion

#pragma region Init
void Init_player();
void Init_Bullet();
void Init_enemy();
#pragma endregion


int main()
{
	CPY_Map();
	InitBuffer();
	Init_player();
	Init_enemy();
	Init_Bullet();

	while (true)
	{

		Move_Bullet();
		Move_Player();
		Move_Enemy();

		Render_Map();
		Render_Player();
		Render_enemy();
		Render_Bullet();

		FlipBuffer();
		ClearBuffer();
		Sleep(10);
	}

	ReleaseBuffer();


	return 0;
}

#pragma region DoubleBuffer
void InitBuffer()
{
	screenIndex = 0;

	COORD size = { BufferWidth, BufferHeight };

	SMALL_RECT rect = { 0, 0, BufferWidth - 1, BufferHeight - 1 };

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;

	SetConsoleCursorInfo(hBuffer[0], &info);
	SetConsoleCursorInfo(hBuffer[1], &info);

}

void FlipBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[screenIndex]);
	screenIndex = !screenIndex;
}

void ClearBuffer()
{
	COORD pos = { 0,0 };
	DWORD dw;

	FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', BufferWidth * BufferHeight, pos, &dw);
}

void WriteBuffer(int x, int y, const char* shape, int color)
{
	COORD pos = { x * 2, y };

	SetConsoleCursorPosition(hBuffer[screenIndex], pos);
	SetConsoleTextAttribute(hBuffer[screenIndex], color);

	DWORD dw;
	WriteFile(hBuffer[screenIndex], shape, strlen(shape), &dw, NULL);
}

void ReleaseBuffer()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}

#pragma endregion

#pragma region MapResearch
void CPY_Map()
{
	for (int y = 0; y < MapY; y++)
	{
		for (int x = 0; x < MapX; x++)
		{
			Cpy_Map[y][x] = map[y][x];
		}
	}
}
void Map_AllClear()
{
	for (int y = 0; y < MapY; y++)
	{
		for (int x = 0; x < MapX; x++)
		{
			if (Cpy_Map[y][x] != 1)
			{
				Cpy_Map[y][x] = 0;
			}
		}
	}
}
void Map_Change()
{
	int number = -2;
	Cpy_Map[bullet->y][bullet->x] = number;
	while (Cpy_Map[enemy->y][enemy->x] == 0)
	{
		for (int y = 0; y < MapY; y++)
		{
			for (int x = 0; x < MapX; x++)
			{
				if (Cpy_Map[y][x] == number)
				{
					if (0 < y && y < MapY && 0 < RIGHT && RIGHT < MapX && Cpy_Map[y][RIGHT] == 0)
						Cpy_Map[y][RIGHT] = number - 1;

					if (0 < y && y < MapY && 0 < LEFT && LEFT < MapX && Cpy_Map[y][LEFT] == 0)
						Cpy_Map[y][LEFT] = number - 1;

					if (0 < UP && UP < MapY && 0 < x && x < MapX && Cpy_Map[UP][x] == 0)
						Cpy_Map[UP][x] = number - 1;

					if (0 < DOWN && DOWN < MapY && 0 < x && x < MapX && Cpy_Map[DOWN][x] == 0)
						Cpy_Map[DOWN][x] = number - 1;

					if (0 < UP && UP < MapY && 0 < RIGHT && RIGHT < MapX && Cpy_Map[UP][RIGHT] == 0)
						Cpy_Map[UP][RIGHT] = number - 1;

					if (0 < UP && UP < MapY && 0 < LEFT && LEFT < MapX && Cpy_Map[UP][LEFT] == 0)
						Cpy_Map[UP][LEFT] = number - 1;

					if (0 < DOWN && DOWN < MapY && 0 < LEFT && LEFT < MapX && Cpy_Map[DOWN][LEFT] == 0)
						Cpy_Map[DOWN][LEFT] = number - 1;

					if (0 < DOWN && DOWN < MapY && 0 < RIGHT && RIGHT < MapX && Cpy_Map[DOWN][RIGHT] == 0)
						Cpy_Map[DOWN][RIGHT] = number - 1;
				}
			}
		}
		number--;
	}
}
void Map_NextChange()
{
	if (bullet != nullptr)
	{
		int number = Cpy_Map[bullet->y][bullet->x];
		while (Cpy_Map[enemy->y][enemy->x] == 0)
		{
			for (int y = 0; y < MapY; y++)
			{
				for (int x = 0; x < MapX; x++)
				{
					if (Cpy_Map[y][x] == number)
					{
						if (0 < y && y < MapY && 0 < RIGHT && RIGHT < MapX && Cpy_Map[y][RIGHT] == 0)
							Cpy_Map[y][RIGHT] = number - 1;

						if (0 < y && y < MapY && 0 < LEFT && LEFT < MapX && Cpy_Map[y][LEFT] == 0)
							Cpy_Map[y][LEFT] = number - 1;

						if (0 < UP && UP < MapY && 0 < x && x < MapX && Cpy_Map[UP][x] == 0)
							Cpy_Map[UP][x] = number - 1;

						if (0 < DOWN && DOWN < MapY && 0 < x && x < MapX && Cpy_Map[DOWN][x] == 0)
							Cpy_Map[DOWN][x] = number - 1;

						if (0 < UP && UP < MapY && 0 < RIGHT && RIGHT < MapX && Cpy_Map[UP][RIGHT] == 0)
							Cpy_Map[UP][RIGHT] = number - 1;

						if (0 < UP && UP < MapY && 0 < LEFT && LEFT < MapX && Cpy_Map[UP][LEFT] == 0)
							Cpy_Map[UP][LEFT] = number - 1;

						if (0 < DOWN && DOWN < MapY && 0 < LEFT && LEFT < MapX && Cpy_Map[DOWN][LEFT] == 0)
							Cpy_Map[DOWN][LEFT] = number - 1;

						if (0 < DOWN && DOWN < MapY && 0 < RIGHT && RIGHT < MapX && Cpy_Map[DOWN][RIGHT] == 0)
							Cpy_Map[DOWN][RIGHT] = number - 1;
					}
				}
			}
			number--;
		}
	}
	
}
void Map_Clear()
{
	int number = Cpy_Map[enemy->y][enemy->x];
	for (int y = 0; y < MapY; y++)
	{
		for (int x = 0; x < MapX; x++)
		{
			if (number == Cpy_Map[y][x] && (enemy->y != y || enemy->x != x))
			{
				Cpy_Map[y][x] = 0;

			}
		}
	}
	int x1, y1;
	while (number<-2)
	{
		bool find = false;
		for (int y = 0; y < MapY; y++)
		{
			for (int x = 0; x < MapX; x++)
			{
				if (Cpy_Map[y][x] == number && !find)
				{
					if (Cpy_Map[y][LEFT] == number+1)
					{
						y1 = y; x1 = LEFT;
					}
					else if (Cpy_Map[y][RIGHT] == number +1)
					{
						y1 = y; x1 = RIGHT;
					}
					else if (Cpy_Map[UP][x] == number + 1)
					{
						y1 = UP; x1 = x;
					}
					else if (Cpy_Map[DOWN][x] == number + 1)
					{
						y1 = DOWN; x1 = x;
					}
					else if (Cpy_Map[UP][LEFT] == number + 1)
					{
						y1 = UP; x1 = LEFT;
					}
					else if (Cpy_Map[DOWN][RIGHT] == number + 1)
					{
						y1 = DOWN; x1 = RIGHT;
					}
					else if (Cpy_Map[DOWN][LEFT] == number + 1)
					{
						y1 = DOWN; x1 = LEFT;
					}
					else if (Cpy_Map[UP][RIGHT] == number + 1)
					{
						y1 = UP; x1 = RIGHT;
					}
					find = true;
				}
			}
		}
		for (int y = 0; y < MapY; y++)
		{
			for (int x = 0; x < MapX; x++)
			{
				if (Cpy_Map[y][x] == number +1 && (y != y1 || x != x1) && Cpy_Map[y][x] != 1)
				{
					Cpy_Map[y][x] = 0;
				}

			}
		}
		number++;
	}

}
#pragma endregion

#pragma region Render
void Render_Map()
{

	char* a = &d;
	for (int y = 0; y < MapY; y++)
	{
		for (int x = 0; x < MapX; x++)
		{

			_itoa((int)(Cpy_Map[y][x]), a, 10);
			switch (Cpy_Map[y][x])
			{
			case 1:
				WriteBuffer(x, y, "¡á", 1);
				break;
			default:
				WriteBuffer(x, y, a, 2);
			case 0:
				break;
			}
		}
	}

}
void Render_Player()
{
	WriteBuffer(player->x, player->y, player->shape,6);
}
void Render_enemy()
{
	WriteBuffer(enemy->x, enemy->y, enemy->shape, 3);
}
void Render_Bullet()
{
	if (bullet != nullptr)
	{
		WriteBuffer(bullet->x, bullet->y, bullet->shape, 4);
	}
	
}
#pragma endregion

#pragma region Move
void Move_Player()
{
	int distance = map[enemy->y][enemy->x];
	if (GetAsyncKeyState(VK_LEFT))
	{
		player->x--;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		player->x++;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		player->y--;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		player->y++;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		Init_Bullet();
		bullet->x = player->x;
		bullet->y = player->y;
		bullet->MoveNum = -2;
		Map_AllClear();
		Map_Change();
		Map_Clear();

	}
}
void Move_Bullet()
{
	if (bullet != nullptr)
	{
		for (int y = 0; y < MapY; y++)
		{
			for (int x = 0; x < MapX; x++)
			{
				if (Cpy_Map[y][x] == bullet->MoveNum)
				{
					bullet->x = x;
					bullet->y = y;
					break;
				}
			}
		}
		bullet->MoveNum--;
		if (bullet->x == enemy->x && bullet->y == enemy->y)
		{
			free(bullet);
			bullet = nullptr;
		}
	}

	

}
void Move_Enemy()
{
	if (GetAsyncKeyState(0x44))
	{
		enemy->x++;
		if (Cpy_Map[enemy->y][enemy->x] == 1)
		{
			enemy->x--;
		}
		Map_NextChange();
		Map_Clear();
		
	}
	if (GetAsyncKeyState(0x41))
	{
		enemy->x--;
		if (Cpy_Map[enemy->y][enemy->x] == 1)
		{
			enemy->x++;
		}
		Map_NextChange();
		Map_Clear();
	}
	if (GetAsyncKeyState(0x57))
	{
		enemy->y--;
		if (Cpy_Map[enemy->y][enemy->x] == 1)
		{
			enemy->y++;
		}
		Map_NextChange();
		Map_Clear();

	}
	if (GetAsyncKeyState(0x53))
	{
		enemy->y++;
		if (Cpy_Map[enemy->y][enemy->x] == 1)
		{
			enemy->y--;
		}
		Map_NextChange();
		Map_Clear();
	}
}
#pragma endregion

#pragma region Init
void Init_player()
{
	
	player = (Obj*)malloc(sizeof(Obj));
	player->x = 1;
	player->y = 1;
	player->shape = "¿Ê";
}
void Init_Bullet()
{
	if (bullet == nullptr)
	{
		bullet = (Obj*)malloc(sizeof(Obj));
		bullet->x = player->x;
		bullet->y = player->y;
		bullet->MoveNum = -2;
		bullet->shape = "£ª";
	}
}
void Init_enemy()
{
	enemy = (Obj*)malloc(sizeof(Obj));
	enemy->x = 36;
	enemy->y = 36;
	enemy->shape = "º¿";
}
#pragma endregion