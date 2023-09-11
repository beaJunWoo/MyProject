#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

struct Obj
{
	double x, y;
	double speed;
	const char* shape;
};
struct NSWEobj
{
	double x, y;
	double speed;
	const char* leftshape;
	const char* rightshape;
	const char* upshape;
	const char* downshape;
};

NSWEobj* player = (NSWEobj*)malloc(sizeof(NSWEobj));
Obj* weapon = (Obj*)malloc(sizeof(Obj));
Obj* enemy[100];

int score = 0;
int playerLife = 5;
int Level = 1;
int increase = 0;
bool OnWeapon = false;

//기본
void SetPosition(int x, int y, const char* shape);
void CreatePlayer();
void CreateWeapon();
void Move();
void SetInterface(int x, int y, const char* shape, int info);
void DeleteCursor();
//기본

//적
void CreateEnemy(int i);
void MoveEnemy(int i);
void EnemyRespone();
//적

void ShowScoreAndLife()
{
	score++;
	SetInterface(1, 1, "스코어:", score);
	for (int i = 0; i < playerLife; i++)
	{
		SetPosition(10 + i, 1, "♥");
	}
}

int main()
{
	for (int i = 0; i < 100; i++)
	{
		enemy[i] = (Obj*)malloc(sizeof(Obj));
	}
	for (int i = 0; i < 100; i++)
	{
		CreateEnemy(i);
	}

	CreatePlayer();
	CreateWeapon();
	DeleteCursor();

	while (true)
	{
		system("cls");
		
		Move();
		EnemyRespone();
	
		if (playerLife == 0) { break; }
		ShowScoreAndLife();

		Sleep(40);
	}
	system("cls");
	printf("패배!\n");
	printf("점수: %d\n", score);
}

void SetPosition(int x, int y, const char* shape)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf(shape);
}
void SetInterface(int x, int y, const char* shape, int info)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s : %d", shape, info);
}
void CreatePlayer()
{
	player->x = 10;
	player->y = 10;
	player->leftshape = "ㅠ옷";
	player->rightshape = "옷ㅠ";
	player->upshape = "옷";
	player->downshape = "옷";
	player->speed = 1;
}
void CreateWeapon()
{
	weapon->x = player->x;
	weapon->y = player->y;
	weapon->shape = "|";
}
void CreateEnemy(int i)
{
	enemy[i]->x = rand() % 20;
	enemy[i]->y = rand() % 17;
	enemy[i]->shape = "★";
	enemy[i]->speed = 1;
}
void Move()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		player->x -= 1 * player->speed;
		SetPosition(player->x, player->y, player->leftshape);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		player->x += 1 * player->speed;
		SetPosition(player->x, player->y, player->rightshape);
	}
	if (GetAsyncKeyState(VK_UP))
	{
		player->y -= 1 * player->speed;
		SetPosition(player->x, player->y, player->upshape);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		player->y += 1 * player->speed;
		SetPosition(player->x, player->y, player->downshape);
	}
	if (GetAsyncKeyState(VK_CONTROL))
	{
		player->speed = 0.3;
	}
	else { player->speed = 1; }

	//발사
	if ( GetAsyncKeyState(0x5A))
	{
		OnWeapon = true;
	}
	if (OnWeapon)
	{
		weapon->y--;
		if (weapon->y == -1) { OnWeapon = false; weapon->y = player->y; weapon->x = player->x; }
		SetPosition(weapon->x, weapon->y, "|");
	}
	else { weapon->y = player->y; weapon->x = player->x; }


	if (!(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN)))
	{
		SetPosition(player->x, player->y, "옷");
	}
	
}
void DeleteCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void MoveEnemy(int i)
{
	if (enemy[i]->x > player->x) { enemy[i]->x -= 0.2; }
	if (enemy[i]->x < player->x) { enemy[i]->x += 0.2; }
	if (enemy[i]->y > player->y) { enemy[i]->y -= 0.2; }
	if (enemy[i]->y < player->y) { enemy[i]->y += 0.2; }
	SetPosition(enemy[i]->x, enemy[i]->y, enemy[i]->shape);
}

void EnemyRespone()
{
	int Enemycount = 0;
	for (int i = 0; i < 1 + increase; i++)
	{
		if (enemy[i] != nullptr && (int)player->x == (int)enemy[i]->x && (int)player->y == (int)enemy[i]->y)
		{
			playerLife--;
		}
		if (enemy[i] != nullptr && (int)weapon->x == (int)enemy[i]->x && (int)weapon->y == (int)enemy[i]->y)
		{
			free(enemy[i]);
			enemy[i] = nullptr;
		}
		if (enemy[i] != nullptr)
		{
			MoveEnemy(i);
			Enemycount++;
		}
	}
	if (Enemycount == 0)
	{

		increase += Level;
		Level++;
	}
}