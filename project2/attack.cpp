#include <stdio.h>
#include <Windows.h>

#define MapX 50
#define MapY 20

#define EnemyCount 30
#define playerBulletCount 100
#define enemyBulletCount 100
#define ItemCount 10

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
enum ItemEffect
{
	HEAL,
	ADD_02,    //2廓 識憲 蹺陛
};
#pragma endregion
int Map[20][50] =
{
	{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,5,5,5,5,5,5,0,0,0,0,0,0,5,0,0,0,0,0,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
};

const char* Weaphone[10][10];

struct Player
{
	int x;
	int y;
	Color color;
	int direction =1;
	int speed[2];  
	int bulletNum[3];//[0]=1廓鼠晦 驕熱
	int hp;
	int weaponNum;
	const char* shape;
	const char* die;
};
Player* player=nullptr;

struct Enemy
{
	int x;
	int y;
	Color color;
	int Lv;
	int hp;
	int rerodingTime[2];
	int responTime;
	int moveDir[2] = { 0,0 };
	const char* shape;
	const char* die;
};
Enemy* enemy[EnemyCount] = {};

struct Item
{
	int x;
	int y;
	Color color;
	ItemEffect itemEffect;
	const char* shape;
};
Item* item[ItemCount] = {};

struct Bullet
{
	double x;
	double y;
	int damage;
	int direction;
	double speed;
	const char* shape[4];
	const char* destroy[8];
};
Bullet* playerBullet1[playerBulletCount] = {};
Bullet* playerBullet2[playerBulletCount] = {};
Bullet* enemyBullet[enemyBulletCount] = {};


#pragma region API
void posXY(int x, int y);
void DeleteCurosr();
void SetColor(int color);
#pragma endregion

#pragma region Player
void ShowPlayer();
void SettingPlayer(int x, int y);
void PlayerMove();
void AttackPlayer();
#pragma endregion

#pragma region Enemy
void ShowEnemy();
void CreateEnemy(int x, int y, int lv);
void SettingEnemy(int x, int y, int hp, int lv, int rerodingTime, const char* shape, const char* die);
void AttackEnemy();
void EnemyMove();
#pragma endregion

#pragma region Bullet
void CreateEnemyBullet(Enemy* enemy);
void CreatePlayerBullet(Bullet* bullet[], double speed, int damage, const char* shape);
#pragma endregion

#pragma region Physics
void PlayerGravity();
void EnemyGravity();
#pragma endregion

#pragma region GameFunction
void ShowMap();
void ShowGunUI();
void Weaphone_MapInitialize();
void CreateItem();
void UseItem();
#pragma endregion


//∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟
//∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟∟
int main()
{
	DeleteCurosr();

	SettingPlayer(20, 10);
	CreateEnemy(10, 10, 1);
	CreateEnemy(15, 10, 1);
	CreateEnemy(30, 10, 1);
	
	Weaphone_MapInitialize();
	CreateItem();
	while (true)
	{
		system("cls");

		//轎溘
		ShowGunUI();
		ShowMap();
		ShowEnemy();
		ShowPlayer();

		//遺霜歜
		PlayerMove();
		EnemyMove();
		
		//奢問
		AttackPlayer();
		AttackEnemy();

		UseItem();

		Sleep(15);
	}
	return 0;
}
//⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿
//⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿⊿

#pragma region API
void posXY(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void DeleteCurosr()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#pragma endregion


#pragma region Player
void ShowPlayer()
{
	SetColor(player->color);
	posXY(player->x, player->y);
	printf(player->shape);

	for (int i = 0; i < player->hp; i++)
	{
		posXY(1 + i, 1);
		printf("%s", "Ⅵ");
	}
	
}
void SettingPlayer(int x, int y)
{
	player = (Player*)malloc(sizeof(Player));
	player->x = x;
	player->y = y;
	player->hp = 10;
	player->color = WHITE;
	player->shape = "褡";
	player->die = "橫<";
	player->weaponNum = 1;
	player->bulletNum[0] = 100;
	player->bulletNum[1] = 100;
	player->bulletNum[2] = 100;
}
void PlayerMove()
{
	if (GetAsyncKeyState(0x31))
	{
		player->weaponNum = 1;
	}
	if (GetAsyncKeyState(0x32) && player->bulletNum[0] > 0)
	{
		player->weaponNum = 2;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		switch (player->weaponNum)
		{
		case 1:
			CreatePlayerBullet(playerBullet1,0.5,1,"o");
			break;
		case 2:
			CreatePlayerBullet(playerBullet2, 0.5,3, "O");
			player->bulletNum[0]--;
			if (player->bulletNum[0] == 0) { player->weaponNum = 1; }
			break;
		default:
			break;
		}
		
	}
	if (player->speed[0] <= player->speed[1])
	{
		if (GetAsyncKeyState(VK_LEFT) && Map[player->y][player->x - 1] < 4)
		{
			player->x--;
			player->direction = 4;
		}
		if (GetAsyncKeyState(VK_RIGHT) && Map[player->y][player->x + 1] < 4)
		{
			player->x++;
			player->direction = 0;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			player->y--;
			player->direction = 2;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			player->y++;
			player->direction = 6;
		}
		if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_UP)) { player->direction = 1; }
		if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_UP)) { player->direction = 3; }
		if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_DOWN)) { player->direction = 5; }
		if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_DOWN)) { player->direction = 7; }
		
		if (GetAsyncKeyState(VK_CONTROL))
		{
			player->speed[0] = 1;
		}
		else
		{
			player->speed[0] = 0;
			player->speed[1] = 0;
		}
	}
	else
		player->speed[1]++;
	
	//PlayerGravity();
}
void BasicGunAttack()
{
	for (int i = 0; i < playerBulletCount; i++)
	{
		if (playerBullet1[i] != nullptr)
		{
			posXY(playerBullet1[i]->x, playerBullet1[i]->y);
			printf(playerBullet1[i]->shape[0]);
			switch (playerBullet1[i]->direction)
			{
			case 0:
				playerBullet1[i]->x+=playerBullet1[i]->speed;
				break;
			case 1:
				playerBullet1[i]->x+= playerBullet1[i]->speed;
				playerBullet1[i]->y-= playerBullet1[i]->speed;
				break;
			case 2:
				playerBullet1[i]->y-= playerBullet1[i]->speed;
				break;
			case 3:
				playerBullet1[i]->x-= playerBullet1[i]->speed;
				playerBullet1[i]->y- playerBullet1[i]->speed;
				break;
			case 4:
				playerBullet1[i]->x-=playerBullet1[i]->speed;
				break;
			case 5:
				playerBullet1[i]->x-= playerBullet1[i]->speed;
				playerBullet1[i]->y+= playerBullet1[i]->speed;
				break;
			case 6:
				playerBullet1[i]->y+= playerBullet1[i]->speed;
				break;
			case 7:
				playerBullet1[i]->x+= playerBullet1[i]->speed;
				playerBullet1[i]->y+= playerBullet1[i]->speed;
				break;
			default:
				playerBullet1[i]->x+= playerBullet1[i]->speed;
				break;
			}
			if (playerBullet1[i]->x < 0 || playerBullet1[i]->x>MapX || playerBullet1[i]->y < 0 || playerBullet1[i]->y>MapY)
			{
				free(playerBullet1[i]);
				playerBullet1[i] = nullptr;
			}
			else if (Map[(int)playerBullet1[i]->y][(int)playerBullet1[i]->x] > 4)
			{
				switch (playerBullet1[i]->direction)
				{
				case 0:
					posXY(playerBullet1[i]->x - 1, playerBullet1[i]->y);
					printf(playerBullet1[i]->destroy[0]);
					break;
				case 1:
					posXY(playerBullet1[i]->x - 1, playerBullet1[i]->y + 1);
					printf(playerBullet1[i]->destroy[1]);
					break;
				case 2:
					posXY(playerBullet1[i]->x, playerBullet1[i]->y + 1);
					printf(playerBullet1[i]->destroy[2]);
					break;
				case 3:
					posXY(playerBullet1[i]->x + 1, playerBullet1[i]->y + 1);
					printf(playerBullet1[i]->destroy[3]);
					break;
				case 4:
					posXY(playerBullet1[i]->x + 1, playerBullet1[i]->y);
					printf(playerBullet1[i]->destroy[4]);
					break;
				case 5:
					posXY(playerBullet1[i]->x + 1, playerBullet1[i]->y - 1);
					printf(playerBullet1[i]->destroy[5]);
					break;
				case 6:
					posXY(playerBullet1[i]->x, playerBullet1[i]->y - 1);
					printf(playerBullet1[i]->destroy[6]);
					break;
				case 7:
					posXY(playerBullet1[i]->x - 1, playerBullet1[i]->y - 1);
					printf(playerBullet1[i]->destroy[7]);
					break;
				}
				free(playerBullet1[i]);
				playerBullet1[i] = nullptr;
				continue;
			}
			for (int j = 0; j < EnemyCount; j++)
			{
				if (enemy[j] != nullptr && playerBullet1[i] != nullptr)
				{
					if (playerBullet1[i]->x == enemy[j]->x && playerBullet1[i]->y == enemy[j]->y)
					{
						enemy[j]->color = RED;
						free(playerBullet1[i]);
						playerBullet1[i] = nullptr;
						enemy[j]->hp--;
					}
				}
			}
		}
	}
}
void StringGunAttack()
{
	for (int i = 0; i < playerBulletCount; i++)
	{
		if (playerBullet2[i] != nullptr)
		{
			posXY(playerBullet2[i]->x, playerBullet2[i]->y);
			printf(playerBullet2[i]->shape[0]);
			switch (playerBullet2[i]->direction)
			{
			case 0:
				playerBullet2[i]->x+= 1/playerBullet2[i]->speed;
				break;
			case 1:
				playerBullet2[i]->x+= 1/playerBullet2[i]->speed;
				playerBullet2[i]->y-= 1/playerBullet2[i]->speed;
				break;
			case 2:
				playerBullet2[i]->y-= 1/playerBullet2[i]->speed;
				break;
			case 3:
				playerBullet2[i]->x-= 1/playerBullet2[i]->speed;
				playerBullet2[i]->y-= 1/playerBullet2[i]->speed;
				break;
			case 4:
				playerBullet2[i]->x-= 1/playerBullet2[i]->speed;
				break;
			case 5:
				playerBullet2[i]->x-= 1/playerBullet2[i]->speed;
				playerBullet2[i]->y+= 1/playerBullet2[i]->speed;
				break;
			case 6:
				playerBullet2[i]->y+= playerBullet2[i]->speed;
				break;
			case 7:
				playerBullet2[i]->x+= playerBullet2[i]->speed;
				playerBullet2[i]->y+= playerBullet2[i]->speed;
				break;
			default:
				playerBullet2[i]->x+= playerBullet2[i]->speed;
				break;
			}
			if (playerBullet2[i]->x < 0 || playerBullet2[i]->x>MapX || playerBullet2[i]->y < 0 || playerBullet2[i]->y>MapY)
			{
				free(playerBullet2[i]);
				playerBullet2[i] = nullptr;
			}
			else if (Map[(int)playerBullet2[i]->y][(int)playerBullet2[i]->x] > 4)
			{
				switch (playerBullet2[i]->direction)
				{
				case 0:
					posXY(playerBullet2[i]->x - 1, playerBullet2[i]->y);
					printf(playerBullet2[i]->destroy[0]);
					break;
				case 1:
					posXY(playerBullet2[i]->x - 1, playerBullet2[i]->y + 1);
					printf(playerBullet2[i]->destroy[1]);
					break;
				case 2:
					posXY(playerBullet2[i]->x, playerBullet2[i]->y + 1);
					printf(playerBullet2[i]->destroy[2]);
					break;
				case 3:
					posXY(playerBullet2[i]->x + 1, playerBullet2[i]->y + 1);
					printf(playerBullet2[i]->destroy[3]);
					break;
				case 4:
					posXY(playerBullet2[i]->x + 1, playerBullet2[i]->y);
					printf(playerBullet2[i]->destroy[4]);
					break;
				case 5:
					posXY(playerBullet2[i]->x + 1, playerBullet2[i]->y - 1);
					printf(playerBullet2[i]->destroy[5]);
					break;
				case 6:
					posXY(playerBullet2[i]->x, playerBullet2[i]->y - 1);
					printf(playerBullet2[i]->destroy[6]);
					break;
				case 7:
					posXY(playerBullet2[i]->x - 1, playerBullet2[i]->y - 1);
					printf(playerBullet2[i]->destroy[7]);
					break;
				}
				free(playerBullet2[i]);
				playerBullet2[i] = nullptr;
				continue;
			}
			for (int j = 0; j < EnemyCount; j++)
			{
				if (enemy[j] != nullptr && playerBullet2[i] != nullptr)
				{
					if (playerBullet2[i]->x == enemy[j]->x && playerBullet2[i]->y == enemy[j]->y)
					{
						enemy[j]->color = RED;
						free(playerBullet2[i]);
						playerBullet2[i] = nullptr;
						enemy[j]->hp--;
					}
				}
			}
		}
	}
}
void AttackPlayer()
{
	
	BasicGunAttack();
	StringGunAttack();
	
}
#pragma endregion


#pragma region Enemy
void ShowEnemy()
{
	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemy[i] != nullptr && enemy[i]->hp>0)
		{
			SetColor(enemy[i]->color);
			posXY(enemy[i]->x, enemy[i]->y);
			printf(enemy[i]->shape);
		}
		if (enemy[i] != nullptr && enemy[i]->hp< 0)
		{
			SetColor(enemy[i]->color);
			posXY(enemy[i]->x, enemy[i]->y);
			printf(enemy[i]->die);
			enemy[i]->responTime--;
			if (enemy[i]->responTime<= 0)
			{
				free(enemy[i]);
				enemy[i] = nullptr;
			}
		}
	}
	for (int j = 0; j < EnemyCount; j++)
	{
		if (enemy[j] != nullptr)
		{
			enemy[j]->color = BROWN;
		}
	}
}
void CreateEnemy(int x, int y, int lv) // [瞳儅撩] 殮溘高: x謝ル, y謝ル, 瞳溯漣(1~3)
{
	if (lv == 1)
	{   //         謝ルx,y,HP,lv,shape,die
		SettingEnemy(x, y, 5, 1, 50, "瑪", "ぷ<");
	}
	if (lv == 2)
	{
		SettingEnemy(x, y, 10, 2, 35, "瑪", "ぷ<");
	}
	if (lv == 3)
	{
		SettingEnemy(x, y, 20, 3, 20, "瑪", "ぷ<");
	}
}
void SettingEnemy(int x, int y, int hp, int lv, int rerodingTime, const char* shape, const char* die) //CreateEnemy辨
{
	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemy[i] == nullptr)
		{
			enemy[i] = (Enemy*)malloc(sizeof(Enemy));
			enemy[i]->x = x;
			enemy[i]->y = y;
			enemy[i]->hp = hp;
			enemy[i]->Lv = lv;
			enemy[i]->rerodingTime[0] = rerodingTime;
			enemy[i]->rerodingTime[1] = 0;
			enemy[i]->responTime= 30;
			enemy[i]->shape = shape;
			enemy[i]->die = die;
			enemy[i]->color = BROWN;
			break;
		}
		
	}
}
void AttackEnemy()
{
	if (player != nullptr)
	{
		player->color = WHITE;
		for (int i = 0; i < EnemyCount; i++)
		{
			if (enemy[i] != nullptr && enemy[i]->hp>0)
			{
				
				if (enemy[i]->rerodingTime[0] <= enemy[i]->rerodingTime[1])
				{
					CreateEnemyBullet(enemy[i]); 
					enemy[i]->rerodingTime[1] = 0;
				}
				else
					enemy[i]->rerodingTime[1]++; 
			}
		}

		for (int i = 0; i < enemyBulletCount; i++)
		{
			if (enemyBullet[i] != nullptr)
			{
				if (enemyBullet[i]->x < 0 || enemyBullet[i]->x>30 || enemyBullet[i]->y < 0 || enemyBullet[i]->y>30 )
				{
					free(enemyBullet[i]);
					enemyBullet[i] = nullptr;
				}
				else if (Map[(int)enemyBullet[i]->y][(int)enemyBullet[i]->x] > 4 ||(enemyBullet[i]->x==player->x &&enemyBullet[i]->y==player->y))
				{
					if (enemyBullet[i]->x == player->x && enemyBullet[i]->y == player->y)
					{
						player->color = RED;
						player->hp--;
					}	
					switch (enemyBullet[i]->direction)
					{
					case 0:
						posXY(enemyBullet[i]->x - 1, enemyBullet[i]->y);
						printf(enemyBullet[i]->destroy[0]);
						break;
					case 1:
						posXY(enemyBullet[i]->x - 1, enemyBullet[i]->y + 1);
						printf(enemyBullet[i]->destroy[1]);
						break;
					case 2:
						posXY(enemyBullet[i]->x, enemyBullet[i]->y + 1);
						printf(enemyBullet[i]->destroy[2]);
						break;
					case 3:
						posXY(enemyBullet[i]->x + 1, enemyBullet[i]->y + 1);
						printf(enemyBullet[i]->destroy[3]);
						break;
					case 4:
						posXY(enemyBullet[i]->x + 1, enemyBullet[i]->y);
						printf(enemyBullet[i]->destroy[4]);
						break;
					case 5:
						posXY(enemyBullet[i]->x + 1, enemyBullet[i]->y - 1);
						printf(enemyBullet[i]->destroy[5]);
						break;
					case 6:
						posXY(enemyBullet[i]->x, enemyBullet[i]->y - 1);
						printf(enemyBullet[i]->destroy[6]);
						break;
					case 7:
						posXY(enemyBullet[i]->x - 1, enemyBullet[i]->y - 1);
						printf(enemyBullet[i]->destroy[7]);
						break;
					}
					free(enemyBullet[i]);
					enemyBullet[i] = nullptr;
				}
				else
				{
					posXY(enemyBullet[i]->x, enemyBullet[i]->y);
					printf(enemyBullet[i]->shape[0]);
					switch (enemyBullet[i]->direction)
					{
					case 0:
						enemyBullet[i]->x++;
						break;
					case 1:
						enemyBullet[i]->x++;
						enemyBullet[i]->y--;
						break;
					case 2:
						enemyBullet[i]->y--;
						break;
					case 3:
						enemyBullet[i]->x--;
						enemyBullet[i]->y--;
						break;
					case 4:
						enemyBullet[i]->x--;
						break;
					case 5:
						enemyBullet[i]->x--;
						enemyBullet[i]->y++;
						break;
					case 6:
						enemyBullet[i]->y++;
						break;
					case 7:
						enemyBullet[i]->x++;
						enemyBullet[i]->y++;
						break;
					default:
						break;
					}
				}
			}
		}

	}
}
void EnemyMove()
{
	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemy[i] != nullptr && enemy[i]->hp>0)
		{
			if (rand() % 1000 < 1 && Map[enemy[i]->y][enemy[i]->x + 1] < 5)
			{
				enemy[i]->moveDir[0] = rand() % 4;
			}
			else if (rand() % 100 < 2 && rand() % 100 >= 1 )
			{
				enemy[i]->moveDir[0] = -(rand() % 4);
			}
			else if (rand() % 100 < 3 && rand() % 100 >= 2){
				if (enemy[i]->x < player->x )
				{
					enemy[i]->moveDir[0] = rand() % 4;
				}
				else if(Map[enemy[i]->y][enemy[i]->x - 1] < 5)
				{
					enemy[i]->moveDir[0] = -(rand() % 4);
				}
			}
			if (enemy[i]->moveDir[0] != enemy[i]->moveDir[1])
			{
				if (enemy[i]->moveDir[0] > enemy[i]->moveDir[1] && Map[enemy[i]->y][enemy[i]->x + 1] < 5 )
				{
					enemy[i]->moveDir[1]++;
					enemy[i]->x++;
				}
				if (enemy[i]->moveDir[0] < enemy[i]->moveDir[1] && Map[enemy[i]->y][enemy[i]->x - 1] < 5 )
				{
					enemy[i]->moveDir[1]--;
					enemy[i]->x--;
				}
			}
			else
			{
				enemy[i]->moveDir[0] = 0;
				enemy[i]->moveDir[1] = 0;
			}
		}
	}
	EnemyGravity();
}
#pragma endregion


#pragma region Bullet
void CreateEnemyBullet(Enemy* enemy){
	for (int i = 0; i < enemyBulletCount; i++)
	{
		if (enemyBullet[i] == nullptr)
		{
			enemyBullet[i] = (Bullet*)malloc(sizeof(Bullet));
			enemyBullet[i]->x = enemy->x;
			enemyBullet[i]->y = enemy->y;
			if (enemy->Lv == 1)
			{
				enemyBullet[i]->shape[0] = "&";
				enemyBullet[i]->damage = 1;
				enemyBullet[i]->destroy[0] = " :";
				enemyBullet[i]->destroy[1] = "'.";
				enemyBullet[i]->destroy[2] = "''";
				enemyBullet[i]->destroy[3] = ".'";
				enemyBullet[i]->destroy[4] = ": ";
				enemyBullet[i]->destroy[5] = "'.";
				enemyBullet[i]->destroy[6] = "..";
				enemyBullet[i]->destroy[7] = ".'";
			}else if (enemy->Lv == 2)
			{
				enemyBullet[i]->shape[0] = "0";
				enemyBullet[i]->damage = 2;
			}else if (enemy->Lv == 3)
			{
				enemyBullet[i]->shape[0] = "+";
				enemyBullet[i]->damage = 3;
			}
			
			int x = player->x - enemy->x;
			int y = player->y - enemy->y;
			if (y == 0 && x > 0)
			{
				enemyBullet[i]->direction = 0;
				enemyBullet[i]->x = enemy->x + 1;
				enemyBullet[i]->y = enemy->y;
			}	
			else if (x > 0 && y < 0)
			{
				enemyBullet[i]->direction = 1;
				enemyBullet[i]->x = enemy->x + 1;
				enemyBullet[i]->y = enemy->y - 1;
			}
			else if (x == 0 && y < 0)
			{
				enemyBullet[i]->direction = 2;
				enemyBullet[i]->x = enemy->x;
				enemyBullet[i]->y = enemy->y - 1;
			}
			else if (x < 0 && y < 0)
			{
				enemyBullet[i]->direction = 3;
				enemyBullet[i]->x = enemy->x - 1;
				enemyBullet[i]->y = enemy->y - 1;
			}
			else if (y == 0 && x < 0)
			{
				enemyBullet[i]->direction = 4;
				enemyBullet[i]->x = enemy->x - 1;
				enemyBullet[i]->y = enemy->y;
			}	
			else if (x < 0 && y>0)
			{
				enemyBullet[i]->direction = 5;
				enemyBullet[i]->x = enemy->x - 1;
				enemyBullet[i]->y = enemy->y + 1;
			}
			else if (x == 0 && y > 0)
			{
				enemyBullet[i]->direction = 6;
				enemyBullet[i]->x = enemy->x;
				enemyBullet[i]->y = enemy->y + 1;
			}						
			else if (x > 0 && y > 0)
			{
				enemyBullet[i]->direction = 7;
				enemyBullet[i]->x = enemy->x + 1;
				enemyBullet[i]->y = enemy->y + 1;
			}				
			else
			{
				enemyBullet[i]->direction = 0;
				enemyBullet[i]->x = enemy->x + 1;
				enemyBullet[i]->y = enemy->y;
			}
			break;
		}
	}
}
void CreatePlayerBullet(Bullet* bullet[], double speed, int damage,const char* shape)
{
	for (int i = 0; i < playerBulletCount; i++)
	{
		if (bullet[i] == nullptr)
		{
			bullet[i] = (Bullet*)malloc(sizeof(Bullet));
			switch (player->direction)
			{
			case 0:
				bullet[i]->x = player->x + 1;
				bullet[i]->y = player->y;
				break;
			case 1:
				bullet[i]->x = player->x + 1;
				bullet[i]->y = player->y - 1;
				break;
			case 2:
				bullet[i]->x = player->x;
				bullet[i]->y = player->y - 1;
				break;
			case 3:
				bullet[i]->x = player->x - 1;
				bullet[i]->y = player->y - 1;
				break;
			case 4:
				bullet[i]->x = player->x - 1;
				bullet[i]->y = player->y;
				break;
			case 5:
				bullet[i]->x = player->x - 1;
				bullet[i]->y = player->y + 1;
				break;
			case 6:
				bullet[i]->x = player->x;
				bullet[i]->y = player->y + 1;
				break;
			case 7:
				bullet[i]->x = player->x + 1;
				bullet[i]->y = player->y + 1;
				break;
			default:
				bullet[i]->x = player->x + 1;
				bullet[i]->y = player->y;
				break;
			}

			bullet[i]->shape[0] = shape;
			bullet[i]->damage = damage;
			bullet[i]->destroy[0] = " :";
			bullet[i]->destroy[1] = "'.";
			bullet[i]->destroy[2] = "''";
			bullet[i]->destroy[3] = ".'";
			bullet[i]->destroy[4] = ": ";
			bullet[i]->destroy[5] = "'.";
			bullet[i]->destroy[6] = "..";
			bullet[i]->destroy[7] = ".'";
			bullet[i]->direction = player->direction;
			bullet[i]->speed = speed;
			break;
		}
	}
}
#pragma endregion


#pragma region Physics
void PlayerGravity()
{
	if (player != nullptr)
	{
		if (Map[player->y+1][player->x] < 4)
			player->y++;
	}
}
void EnemyGravity()
{
	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemy[i] != nullptr)
		{
			if (Map[enemy[i]->y + 1][enemy[i]->x] < 4)
				enemy[i]->y++;
		}
	}
}
#pragma endregion


#pragma region GameFunction
void ShowMap()
{
	SetColor(WHITE);
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			posXY(x, y);
			switch (Map[y][x])
			{
			case 5:
				printf("﹤");
				break;
			case 6:
				printf("十");
			default:
				break;
			}
		}
		printf("\n");
	}
}
void ShowGunUI()
{
	if (player->weaponNum == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			SetColor(CYAN);
			posXY(1, 20 + i);
			printf(Weaphone[0][i]);
		}

		for (int i = 0; i < 3; i++)
		{
			SetColor(WHITE);
			posXY(7, 20 + i);
			printf(Weaphone[1][i]);
		}
		posXY(10, 23);
		printf("X %d嫦", player->bulletNum[0]);
	}
	if (player->weaponNum == 2)
	{

		for (int i = 0; i < 3; i++)
		{
			SetColor(WHITE);
			posXY(1, 20 + i);
			printf(Weaphone[0][i]);
		}

		for (int i = 0; i < 3; i++)
		{
			SetColor(CYAN);
			posXY(6, 20 + i);
			printf(Weaphone[1][i]);
		}
		printf("X %d嫦", player->bulletNum[0]);
	}
}
void Weaphone_MapInitialize()
{
	Weaphone[0][0] = "忙式式式式式式忖 ";
	Weaphone[0][1] = "戌式式式式忖 弛 ";
	Weaphone[0][2] = "     戌式戎";

	Weaphone[1][0] = "忙式式式式式式式式式式式式式式式式忖 ";
	Weaphone[1][1] = "戌式式式式式式式忖  弛式式式忖 弛 ";
	Weaphone[1][2] = "        戌式式戎   戌式戎 ";



}
void CreateItem()
{
	item[0] = (Item*)malloc(sizeof(Item));
	item[0]->x = 15;
	item[0]->y = 15;
	item[0]->color = RED;
	item[0]->shape = "Ⅴ";
	item[0]->itemEffect = HEAL;

	item[1] = (Item*)malloc(sizeof(Item));
	item[1]->x = 18;
	item[1]->y = 18;
	item[1]->color = YELLOW;
	item[1]->shape = "∟";
	item[1]->itemEffect = ADD_02;
}
void UseItem()
{
	for (int i = 0; i < ItemCount; i++)
	{
		if (item[i] != nullptr)
		{
			SetColor(item[i]->color);
			posXY(item[i]->x, item[i]->y);
			printf(item[i]->shape);
			if (item[i]->x == player->x && item[i]->y == player->y)
			{
				switch (item[i]->itemEffect)
				{
				case HEAL:
					player->hp++;
					posXY(21, 21);
					printf("+Ⅵ");
					break;
				case ADD_02:
					player->bulletNum[0] += 50;
					posXY(8, 20);
					printf("+ 50");
					break;
				default:
					break;
				}
				free(item[i]);
				item[i] = nullptr;
			}
		}
	}
}
#pragma endregion
