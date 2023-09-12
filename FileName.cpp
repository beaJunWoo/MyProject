#include <stdio.h>
#include <Windows.h>

int totalMoney = 100000;

enum  Color
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

#pragma region BasicMap
int Map[20][40] =
{//0~4통과 가능 , 5~9통과 불가능
 //0="  ", 1=☎, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
	{6,0,0,5,5,5,5,5,0,0,0,0,0,0,5,5,5,5,5,0,0,0,0,0,0,6,0,0,0,6,0,0,6,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
};
int(*pMap)[40] = Map;
#pragma endregion
#pragma region BlackJackMap
int BlackJackMap[20][40] =
{//0~4통과 가능 , 5~9통과 불가능
 //0="  ", 1=☎, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},

};
int(*pBlackJackMap)[40] = BlackJackMap;
#pragma endregion
#pragma region AvoidMap
int AvoidMap[20][40] =
{//0~4통과 가능 , 5~9통과 불가능
 //0="  ", 1=☎, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,6,6,6,6,6,0,0,0,0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6},
	{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},

};
int(*pAvoidMap)[40] = AvoidMap;
#pragma endregion
struct Obj
{
	double x, y;
	double speed;
	const char* shape;
};
Obj* player = (Obj*)malloc(sizeof(Obj));
Obj* BlackJack = (Obj*)malloc(sizeof(Obj));

#pragma region BasicSettings
void DeleteCursor(); //커서 지우는 함수
void SetColor(int n);
void SetPosition(int x, int y, const char* shape); //위치값으로 출력해주는함수
void SetIntStringPosition(int x, int y, int n, const char* shape); //위치값으로 출력해주는함수
void playerSetting(int x, int y); //플레이어 세팅값
void Move(int(*Map)[40]); //캐릭터 움직임
void ShowMap(int(*Map)[40]); //맵그리기
void ShowTotalMoney(); // 총금액 표시
void startGame();
#pragma endregion
#pragma region CardGameSettings
void BlackJackObjSetting();
void startBlackJack();
void BlackJackShowInMap();
void ShowBlackJackTotal();
#pragma endregion
#pragma region AvoidGameSettings
int money = 0;
int countDeath = 0;
bool playerDeath = false;
bool jump = false;
bool spaceJump = false;
int gravity = 0;
int JumpHight = 0;
void MoveGravity()
{
	//낙하
	if ((!spaceJump) && AvoidMap[(int)player->y + 1][(int)player->x] < 5)
	{
		player->y +=1;
		jump = true;
	}
	else { jump = false; }
	
	//좌우
	if (GetAsyncKeyState(VK_LEFT) && AvoidMap[(int)player->y][(int)player->x - 1] < 5)
	{
		player->x--;
	}
	if (GetAsyncKeyState(VK_RIGHT) && AvoidMap[(int)player->y][(int)player->x + 1]<5)
	{
		player->x++;
	}

	//점프
	if (GetAsyncKeyState(VK_SPACE)&&AvoidMap[(int)player->y + 1][(int)player->x]>4)
	{
		spaceJump = true;
	}
	if (spaceJump && JumpHight<5 && !(AvoidMap[(int)player->y-1][(int)player->x]>4))
	{
		player->y--;
		JumpHight++;
	}
	else
	{
		spaceJump = false;
		JumpHight = 0;
	}



	
}
void laserAttack(int time,int Dangertime, int dealTime, int hight) //실행시킬 시간, 위험표시 시간, 터지는 시간, 높이
{
	if (money > time)
	{
		for (int x = 1; x < 30; x++)
		{
			if (10 - (time - money) / 3 * -1 > -1)
			{
				SetIntStringPosition(27, hight, 10 - (time - money) / 3 * -1, "");
			}
			AvoidMap[hight+1][x] = 4;
			AvoidMap[hight+3][x] = 4;

		}
		AvoidMap[hight+2][hight] = 5;
	}
	if (money > time + Dangertime)
	{
		for (int x = 1; x < 30; x++)
		{
			AvoidMap[hight+1][x] = 8;
			AvoidMap[hight+2][x] = 8;
			AvoidMap[hight+3][x] = 8;

		}
	}
	if (money > time+ Dangertime+ dealTime)
	{
		for (int x = 1; x < 30; x++)
		{
			AvoidMap[hight+1][x] = 0;
			AvoidMap[hight+2][x] = 0;
			AvoidMap[hight+3][x] = 0;

		}
	}
}

void startAvoidGame()
{
	player->x = 10;
	player->y = 4;
	player->shape = "옷";
	
	while (true)
	{
		
		system("cls");
		DeleteCursor();
		ShowMap(pAvoidMap);
		ShowTotalMoney();
		SetIntStringPosition(0, 1, money, "원");
		SetPosition(player->x, player->y, player->shape);
		MoveGravity();

		
		laserAttack(50, 30, 10, 15);
		laserAttack(100, 30, 10, 13);
		laserAttack(150, 30, 10, 15);
		
		
		if (AvoidMap[(int)player->y][(int)player->x] == 8)
		{
			playerDeath = true;
			SetColor(RED);
		}
		if (playerDeath)
		{
			countDeath++;
			if (countDeath > 20)
			{
				totalMoney += money;
				while (true)
				{
					SetColor(WHITE);
					system("cls");
					printf("사망하였습니다.\n");
					printf("획득한 돈 :%d\n", money);
					printf("총 소지금액 :%d\n\n", totalMoney);
					if (countDeath % 2 == 1)
					{
						printf("Enter키를 누르면 넘어갑니다.");
					}
					Sleep(1000);
					countDeath++;
					if (GetAsyncKeyState(VK_RETURN))
					{
						break;
					}
				}
				break;
			}
		}

		money++;
		Sleep(10);
	}
	

}

#pragma endregion

int main()
{
	int Menu = 1;
	while (true)
	{
		switch (Menu)
		{
		case 0:
			break;
		case 1:
			startAvoidGame();
			startBlackJack();
			startGame();
			break;
		case 2:
			break;
		default:
			break;
		}
	}


	return 0;
}

#pragma region BasicSettings
void DeleteCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
void SetColor(int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}
void SetPosition(int x, int y, const char* shape)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf(shape);
}
void SetIntStringPosition(int x, int y, int n, const char* shape)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%d %s", n, shape);
}
void playerSetting(int x, int y)
{
	player->x = x;
	player->y = y;
	player->shape = "옷";
}
void Move(int(*Map)[40])
{
	
	if (GetAsyncKeyState(VK_LEFT) && Map[(int)player->y][(int)player->x-1]<5 )
	{
		player->x -= 1 * player->speed;
	}
	if (GetAsyncKeyState(VK_RIGHT) && Map[(int)player->y][(int)player->x + 1] < 5)
	{
		player->x += 1 * player->speed;
	}
	if (GetAsyncKeyState(VK_UP) && Map[(int)player->y-1][(int)player->x] < 5)
	{
		player->y -= 1 * player->speed;
	}
	if (GetAsyncKeyState(VK_DOWN) && Map[(int)player->y+1][(int)player->x] < 5)
	{
		player->y += 1 * player->speed;
	}
	if (GetAsyncKeyState(VK_CONTROL))
	{
		player->speed = 0.3;
	}
	else { player->speed = 1; }

	SetPosition(player->x, player->y, player->shape);
}
void ShowMap(int (*Map)[40])
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			if (0 <= x && x <= 39)
			{
				switch (Map[y][x])
				{
				case 0:
					printf("  ");
					break;
				case 1:
					printf("☎");
					break;
				case 2:
					printf("★");
					break;
				case 3:
					printf("＃");
					break;
				case 4:
					printf("──");
					break;
				case 5:
					printf("!!");
					break;
				case 6:
					printf("▥");
					break;
				case 7:
					printf("□");
					break;
				case 8:
					printf("※");
				default:
					break;
				}
			}
		}
		printf("\n");
	}
}
void ShowTotalMoney()
{
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	if (totalMoney >= 10000)
	{
		printf("소지 금액: %d만 %d원", totalMoney / 10000, totalMoney % 10000);
	}

}
void startGame()
{
	DeleteCursor();
	playerSetting(10, 10);
	BlackJackObjSetting();

	while (true)
	{
		system("cls");

		DeleteCursor();
		ShowMap(pMap);
		ShowTotalMoney();
		Move(pMap);
		BlackJackShowInMap();

		Sleep(20);
	}
}
#pragma endregion
#pragma region CardGameSettings
int battingMoney;
void BlackJackObjSetting()
{
	BlackJack->x = 15;
	BlackJack->y = 15;
	BlackJack->shape = "★";
}
void EndBtnAnimation()
{
	if (29 <= player->x && player->x <= 34 && 14 <= player->y && player->y <= 17)
	{

		for (int y = 14; y < 17; y++)
		{
			for (int x = 29; x < 35; x++)
			{
				BlackJackMap[y][x] = 3;
			}
		}
	}
	else
	{

		for (int y = 14; y < 17; y++)
		{
			for (int x = 29; x < 35; x++)
			{
				BlackJackMap[y][x] = 0;
			}
		}
	}
}
void StartBtnAnimation()
{
	if (29 <= player->x && player->x <= 34 && 7 <= player->y && player->y <= 10)
	{

		for (int y = 7; y < 10; y++)
		{
			for (int x = 29; x < 35; x++)
			{
				BlackJackMap[y][x] = 3;
			}
		}
	}
	else
	{

		for (int y = 7; y < 10; y++)
		{
			for (int x = 29; x < 35; x++)
			{
				BlackJackMap[y][x] = 0;
			}
		}
	}
}
void Betting()
{
	SetPosition(0, 22, "배팅할 금액을 입력하세요!(1000원 이상)");
	scanf_s("%d", &battingMoney);
	while (battingMoney < 1000 || totalMoney < battingMoney)
	{
		system("cls");
		ShowBlackJackTotal();
		SetPosition(0, 22, "배팅할 금액을 입력하세요!(1000원 이상)");
		printf("\n잘못된 값을 입력하였습니다. 다시 입력해주세요!\n");
		scanf_s("%d", &battingMoney);
	}
}
void ShowBlackJackTotal()
{
	DeleteCursor();
	ShowTotalMoney();
	ShowMap(pBlackJackMap);
	Move(pBlackJackMap);
	SetPosition(30, 3, "선택: Enter");
	SetPosition(30, 15, "그만하기");
	SetPosition(30, 8, "계속하기");
	StartBtnAnimation();
	EndBtnAnimation();
}
void startBlackJack()
{
	playerSetting(33, 5);

	while (true)
	{
		system("cls");
		ShowBlackJackTotal();
		if (GetAsyncKeyState(VK_RETURN)&& 29 <= player->x && player->x <= 34 && 14 <= player->y && player->y <= 17) { break; }
		if (GetAsyncKeyState(VK_RETURN) && 29 <= player->x && player->x <= 34 && 7 <= player->y && player->y <= 10) { Betting(); }
		Sleep(10);
	}
	playerSetting(10, 10);
}
void BlackJackShowInMap()
{
	SetPosition(BlackJack->x, BlackJack->y, BlackJack->shape);
	if (BlackJack->x == player->x && BlackJack->y == player->y)
	{
		SetPosition(BlackJack->x, BlackJack->y - 1, "블랙잭(Enter)");
	}
	if (GetAsyncKeyState(VK_RETURN) && (BlackJack->x == player->x && BlackJack->y == player->y))
	{
		startBlackJack();
	}
}
#pragma endregion
