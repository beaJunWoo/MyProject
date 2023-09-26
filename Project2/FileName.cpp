#include <stdio.h>
#include <Windows.h>

#define BoxSizeX 3
#define BoxSizeY 3
#define PlayerSizeX 5
#define PlayerSizeY 2


enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE,

};

#pragma region Buffer
#define BufferWidth 100
#define BufferHeight 60
HANDLE hBuffer[2];
int screenIndex;
void InitBuffer();
void WriteBuffer(int x, int y, const char* shape, int color);
void FlipBuffer();
void ClearBuffer();
#pragma endregion

struct Player
{
	int x, y;
	Color color;
	const char* shape[2];
};
Player* player;

struct Box
{
	int x, y;
	Color color;
	const char* shape[3];
};
Box* box;

#pragma region Player
void PlayerInit();
void PlayerMove();
void PlayerRander();
#pragma endregion
#pragma region Box
void BoxInit();
void BoxRander();
#pragma endregion

void Objcrash()
{
	if (box->x<player->x+PlayerSizeX && box->y-BoxSizeX<player->y && player->x<box->x+BoxSizeX && player->y-PlayerSizeY<box->x)
	{
		box->color = RED;
	}
	else
	{
		box->color = WHITE;
	}
}
int main()
{
	InitBuffer();
	PlayerInit();
	BoxInit();
	while (true)
	{
		PlayerMove();
		Objcrash();

		PlayerRander();
		BoxRander();

		FlipBuffer();
		ClearBuffer();
		
		Sleep(50);
	}


	return 0;
}


#pragma region Buffer

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
void WriteBuffer(int x, int y, const char* shape, int color)
{
	COORD pos = { x * 2, y };

	SetConsoleCursorPosition(hBuffer[screenIndex], pos);
	SetConsoleTextAttribute(hBuffer[screenIndex], color);

	DWORD dw;
	WriteFile(hBuffer[screenIndex], shape, strlen(shape), &dw, NULL);
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
#pragma endregion

#pragma region Player
void PlayerInit()
{
	player = (Player*)malloc(sizeof(Player));
	player->x = 10;
	player->y = 10;
	player->color = WHITE;
	player->shape[0] = "¡Ý¡Ý¡Ý¡Ý¡Ý";
	player->shape[1] = "¡Ý¡Ý¡Ý¡Ý¡Ý";

}
void PlayerMove()
{
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
}
void PlayerRander()
{
	for (int i = 0; i < PlayerSizeY; i++)
	{
		WriteBuffer(player->x, player->y-i, player->shape[i], player->color);
	}

}
#pragma endregion

#pragma region Box
void BoxInit()
{
	box = (Box*)malloc(sizeof(Box));
	box->x = 20;
	box->y = 20;
	box->color = WHITE;
	box->shape[0] = "¡à¡à¡à";
	box->shape[1] = "¡à¡à¡à";
	box->shape[2] = "¡à¡à¡à";
}
void BoxRander()
{
	for (int i = 0; i < BoxSizeY; i++)
	{
		WriteBuffer(box->x, box->y - i, box->shape[i], box->color);
	}
}
#pragma endregion