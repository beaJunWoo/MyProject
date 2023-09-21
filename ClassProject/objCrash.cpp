#include <stdio.h>
#include <Windows.h>

#define BufferHeight 100
#define BufferWidth 80

#define boxHight 3
#define boxWidth 4

#define playerHight 2
#define playerWidth 3
#pragma region Enum
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
#pragma endregion

#pragma region DoubleBuffer
HANDLE hBuffer[2];
int screenIndex;
void InitBuffer();
void WriteBuffer(int x, int y, const char* shape, int color);
void FlipBuffer();
void ClearBuffer();
void DestroyBuffer();
#pragma endregion

struct Obj
{
	int x;
	int y;
	Color color;
	const char* shape[3];
};
Obj* player = {};
Obj* box = {};

#pragma region Player
void playerInit();
void playerMove();
void playerShow();
#pragma endregion

#pragma region Box
void BoxInit();
void BoxShow();
#pragma endregion

void Objcrash();

int main()
{
	InitBuffer();
	playerInit();
	BoxInit();
	while (true)
	{

		playerMove();
		playerShow();
		BoxShow();
		Objcrash();

		FlipBuffer();
		ClearBuffer();
		Sleep(50);
	}

	DestroyBuffer();
	return 0;
}

#pragma region DoubleBuffer
void InitBuffer()
{
	screenIndex = 0;

	COORD size = { BufferWidth, BufferHeight };
	SMALL_RECT rect = { 0, 0, BufferWidth, BufferHeight };

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	CONSOLE_CURSOR_INFO Info;
	Info.dwSize = 1;
	Info.bVisible = FALSE;

	SetConsoleCursorInfo(hBuffer[0], &Info);
	SetConsoleCursorInfo(hBuffer[1], &Info);


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
void DestroyBuffer()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}
#pragma endregion

#pragma region Player
void playerInit()
{
	player = (Obj*)malloc(sizeof(Obj));
	player->x = 10;
	player->y = 10;
	player->color = WHITE;
	player->shape[0] = "£À£À£À";
	player->shape[1] = "£À£À£À";

}
void playerMove()
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
void playerShow()
{
	for (int i = 0; i < playerHight; i++)
	{
		WriteBuffer(player->x, player->y + i, player->shape[i], WHITE);
	}

}
#pragma endregion

#pragma region Box
void BoxInit()
{
	box = (Obj*)malloc(sizeof(Obj));
	box->x = 20;
	box->y = 20;
	box->color = WHITE;
	box->shape[0] = "¡à¡à¡à¡à";
	box->shape[1] = "¡à¡à¡à¡à";
	box->shape[2] = "¡à¡à¡à¡à";
}
void BoxShow()
{
	for (int i = 0; i < boxHight; i++)
	{
		WriteBuffer(box->x, box->y + i, box->shape[i], box->color);
	}
}
#pragma endregion

void Objcrash()
{
	if (player->x + playerWidth > box->x && player->y + playerHight > box->y && player->x < box->x + boxWidth && player->y < box->y + boxHight)
	{
		box->color = RED;
	}
	else
	{
		box->color = WHITE;
	}
}