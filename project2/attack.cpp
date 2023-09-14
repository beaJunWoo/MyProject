#include <stdio.h>
#include <Windows.h>
#define EnemyCount 30
#define playerBulletCount 10
#define enemyBulletCount 100
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
	{5,0,0,0,0,5,5,5,5,5,5,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
};

struct Player
{
	int x;
	int y;
	int speed[2] = { 2,2 };
	int hp;
	const char* shape;
	const char* die;
};
Player* player;

struct Enemy
{
	int x;
	int y;
	int Lv;
	int hp;
	int rerodingTime[2];
	int responTime;
	const char* shape;
	const char* die;
};
Enemy* enemy[EnemyCount];

struct Bullet
{
	int x;
	int y;
	int damage;
	int direction;
	const char* shape[4];
	const char* destroy[8];
};
Bullet* playerBullet[playerBulletCount];
Bullet* enemyBullet[enemyBulletCount];


#pragma region API
void posXY(int x, int y);
void DeleteCurosr();
#pragma endregion

#pragma region Player
void ShowPlayer();
void SettingPlayer(int x, int y);
void PlayerMove();
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
#pragma endregion
void ShowMap();

#pragma region Physics
void PlayerGravity();
void EnemyGravity();
#pragma endregion


int main()
{
	SettingPlayer(20, 10);
	CreateEnemy(10, 10, 1);
	DeleteCurosr();
	while (true)
	{
		system("cls");
		ShowMap();
		ShowEnemy();
		ShowPlayer();
		PlayerMove();
		AttackEnemy();
		EnemyMove();
		Sleep(5);
	}
	return 0;
}

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
#pragma endregion

#pragma region Player
void ShowPlayer()
{
	posXY(player->x, player->y);
	printf(player->shape);
}
void SettingPlayer(int x, int y)
{
	player = (Player*)malloc(sizeof(Player));
	player->x = x;
	player->y = y;
	player->hp = 10;
	player->shape = "¿Ê";
	player->die = "¾î<";
}
void PlayerMove()
{
	if (player->speed[0] <= player->speed[1])
	{
		if (GetAsyncKeyState(VK_LEFT) && Map[player->y][player->x - 1] < 4)
		{
			player->x--;
		}
		if (GetAsyncKeyState(VK_RIGHT) && Map[player->y][player->x + 1] < 4)
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
		if (GetAsyncKeyState(VK_CONTROL))
		{
			player->speed[0] = 1;
		}
		else
			player->speed[0] = 3;
		player->speed[1] = 0;
	}
	else
		player->speed[1]++;
	//PlayerGravity();
}
#pragma endregion

#pragma region Enemy
void ShowEnemy()
{
	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemy[i] != nullptr)
		{
			posXY(enemy[i]->x, enemy[i]->y);
			printf(enemy[i]->shape);
		}
	}
}
void CreateEnemy(int x, int y, int lv) // [Àû»ý¼º] ÀÔ·Â°ª: xÁÂÇ¥, yÁÂÇ¥, Àû·¹º§(1~3)
{
	if (lv == 1)
	{   //         ÁÂÇ¥x,y,HP,lv,shape,die
		SettingEnemy(x, y, 5, 1, 50, "º¿", "ÆÛ<");
	}
	if (lv == 2)
	{
		SettingEnemy(x, y, 10, 2, 35, "º¿", "ÆÛ<");
	}
	if (lv == 3)
	{
		SettingEnemy(x, y, 20, 3, 20, "º¿", "ÆÛ<");
	}
}
void SettingEnemy(int x, int y, int hp, int lv, int rerodingTime, const char* shape, const char* die) //CreateEnemy¿ë
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
			enemy[i]->responTime= 10;
			enemy[i]->shape = shape;
			enemy[i]->die = die;
			break;
		}
	}
}
void AttackEnemy()
{
	if (player != nullptr)
	{
		for (int i = 0; i < EnemyCount; i++)
		{
			if (enemy[i] != nullptr )
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
				else if (Map[enemyBullet[i]->y][enemyBullet[i]->x] > 4)
				{
					switch (enemyBullet[i]->direction)
					{
					case 1:
						posXY(enemyBullet[i]->x - 1, enemyBullet[i]->y);
						printf(enemyBullet[i]->destroy[0]);
						break;
					case 2:
						posXY(enemyBullet[i]->x - 1, enemyBullet[i]->y + 1);
						printf(enemyBullet[i]->destroy[1]);
						break;
					case 3:
						posXY(enemyBullet[i]->x, enemyBullet[i]->y + 1);
						printf(enemyBullet[i]->destroy[2]);
						break;
					case 4:
						posXY(enemyBullet[i]->x + 1, enemyBullet[i]->y + 1);
						printf(enemyBullet[i]->destroy[3]);
						break;
					case 5:
						posXY(enemyBullet[i]->x + 1, enemyBullet[i]->y);
						printf(enemyBullet[i]->destroy[4]);
						break;
					case 6:
						posXY(enemyBullet[i]->x + 1, enemyBullet[i]->y - 1);
						printf(enemyBullet[i]->destroy[5]);
						break;
					case 7:
						posXY(enemyBullet[i]->x, enemyBullet[i]->y - 1);
						printf(enemyBullet[i]->destroy[6]);
						break;
					case 8:
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
					case 1:
						enemyBullet[i]->x++;
						break;
					case 2:
						enemyBullet[i]->x++;
						enemyBullet[i]->y--;
						break;
					case 3:
						enemyBullet[i]->y--;
						break;
					case 4:
						enemyBullet[i]->x--;
						enemyBullet[i]->y--;
						break;
					case 5:
						enemyBullet[i]->x--;
						break;
					case 6:
						enemyBullet[i]->x--;
						enemyBullet[i]->y++;
						break;
					case 7:
						enemyBullet[i]->y++;
						break;
					case 8:
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
		if (enemy[i] != nullptr)
		{
			if (rand() % 1000 < 1 && Map[enemy[i]->y][enemy[i]->x + 1] < 5)
			{
				enemy[i]->x++;
			}
			else if (rand() % 100 < 2 && rand() % 100 >= 1 && Map[enemy[i]->y][enemy[i]->x - 1] < 5)
			{
				enemy[i]->x--;
			}
			else if (rand() % 100 < 3 && rand() % 100 >= 2){
				if (enemy[i]->x < player->x && Map[enemy[i]->y][enemy[i]->x + 1] < 5)
				{
					enemy[i]->x++;
				}
				else if(Map[enemy[i]->y][enemy[i]->x - 1] < 5)
				{
					enemy[i]->x--;
				}
			}
			else
			{
				
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
			
			int x = player->x - enemyBullet[i]->x;
			int y = player->y - enemyBullet[i]->y;
			if (y == 0 && x > 0)
				enemyBullet[i]->direction = 1;
			else if (y == 0 && x < 0)
				enemyBullet[i]->direction = 5;
			else if (x == 0 && y > 0)
				enemyBullet[i]->direction = 7;
			else if (x == 0 && y < 0)
				enemyBullet[i]->direction = 3;
			else if (x > 0 && y > 0)
				enemyBullet[i]->direction = 8;
			else if (x > 0 && y < 0)
				enemyBullet[i]->direction = 2;
			else if (x < 0 && y>0)
				enemyBullet[i]->direction = 6;
			else if (x < 0 && y < 0)
				enemyBullet[i]->direction = 4;
			else
				enemyBullet[i]->direction = 1;
			break;
		}
	}
}
#pragma endregion

void ShowMap()
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			posXY(x, y);
			switch (Map[y][x])
			{
			case 5:
				printf("¡à");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

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
