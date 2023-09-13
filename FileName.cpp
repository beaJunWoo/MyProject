#include <stdio.h>
#include <Windows.h>
#define LogoDelay 1000
#define MenuDelay 100
#define AvoiDelay 10
#define AvoidMapX 40
#define AvoidMapY 20

int AvoidMap[AvoidMapY][AvoidMapX] =
{
 //                      10                  20                  30                
 //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9  
	{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},//0
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//1
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//2
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//3
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//4
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//5
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//6
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//7
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//8
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//9
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//0 10
	{6,0,0,0,0,0,0,0,0,0,0,0,7,7,7,0,0,0,0,0,0,0,0,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//1
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//2
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//3
	{6,0,0,0,0,0,0,6,6,6,6,0,0,0,0,0,0,6,6,6,6,6,0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,6},//4
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//5
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//6
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//7
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},//8
	{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},//9

};
int(*pAvoidMap)[40];
int randomTile[100][2];

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
enum MyEnum
{
	EXIT,
	LOGO,
	MENU,
	LOBBY,
	Avoid,
};
MyEnum menu = LOGO;

struct Obj
{
	int x; 
	int y;
	int color;
	const char* shape[100];
};
Obj* player;
bool isJump = false;
int JumpHight = 0;
int AliveTime = 0;

struct Rager
{
	int randomTime[100];
	int randomDangertime[100];
	int randomDealTime[100];
	int randomHight[100];
};
Rager* randRager;

struct Tile
{
	int x;
	int y;
	int randomtime;
};
Tile* randtile;
//Initialize 초기화
//Progress 진행
//Render 출력
//Release 할당해제
const char* LogoMap[28];

#pragma region Base
void posXY(int x, int y);
void DeleteCurosr();
void setColor(int n);
void Move(int(*Map)[40]);
void ShowMap(int(*Map)[40]);
void SetIntStringPosition(int x, int y, int n, const char* shape)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%d %s", n, shape);
}
#pragma endregion

#pragma region Logo
void LogoInitialize();
void LogoProgress();
void LogoRender(int Filcker);
void LogoRelease();
#pragma endregion

#pragma region Menu
void MenuInitialize();
void MenuProgress();
void MenuRender(int Num);
void MenuRelease();
#pragma endregion

#pragma region Avoid
void AvoidInitialize();
void AvoidProgress();
void AvoidRender();
void AvoidRelease();
#pragma endregion

#pragma region physics
void Gravity(int(*Map)[40], Obj* obj, bool jump);
void Jump(int(*Map)[40], Obj* obj);
void laserAttack(int time, int Dangertime, int dealTime, int hight);
void RandomRager();
void RandomTile();
void createTile();
#pragma endregion
///////////////////////////////////////////////////////////////////////////////////
int main()
{
	while (menu)
	{
		switch (menu)
		{
		case EXIT:
			break;
		case LOGO:
			LogoProgress();
			break;
		case MENU:
			MenuProgress();
			break;
		case LOBBY:
			break;
		case Avoid:
			AvoidProgress();
			break;
		default:
			break;
		}
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////
#pragma region Base
void posXY(int x, int y)
{
	COORD pos;
	pos.X = x*2;
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
void setColor(int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}
void Move(int(*Map)[40])
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		player->x--;
		if (Map[player->y][player->x] > 4) { player->x++; }
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		player->x++;
		if (Map[player->y][player->x] > 4) { player->x--; }
	}
	if (GetAsyncKeyState(VK_UP))
	{
		player->y--;
		if (Map[player->y][player->x] > 4) { player->y++; }
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		player->y++;
		if (Map[player->y][player->x] > 4) { player->y--; }
	}
}
void ShowMap(int(*Map)[40])
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
					printf("※");
					break;
				case 4:
					printf("──");
					break;
				case 5:
					printf("!!");
					break;
				case 6:
					printf("□");
					break;
				case 7:
					printf("▥");
					break;
				case 8:
					printf("  ");
				default:
					break;
				}
			}
		}
		printf("\n");
	}
}
#pragma endregion

#pragma region Logo
void LogoInitialize()
{
	LogoMap[0] = "    /$$                                    ";
	LogoMap[1] = "   | $$                                    ";
	LogoMap[2] = "   | $$        /$$$$$$   /$$$$$$   /$$$$$$ ";
	LogoMap[3] = "   | $$       /$$__  $$ /$$__  $$ /$$__  $$";
	LogoMap[4] = "   | $$      | $$  \ $$| $$  \ $$| $$  \ $$";
	LogoMap[5] = "   | $$      | $$  | $$| $$  | $$| $$  | $$";
	LogoMap[6] = "   | $$$$$$$$|  $$$$$$/|  $$$$$$$|  $$$$$$/";
	LogoMap[7] = "   |________/ \______/  \____  $$ \______/ ";
	LogoMap[8] = "                        /$$  \ $$          ";
	LogoMap[9] = "                       |  $$$$$$/          ";
	LogoMap[10]= "                        \______/ ";
}
void LogoProgress()
{
	int Flicker=0;
	LogoInitialize();
	DeleteCurosr();
	while (true)
	{
		system("cls");
		LogoRender(Flicker); 
		Flicker++;
		Sleep(LogoDelay);
		if (GetAsyncKeyState(VK_RETURN))
		{
			menu = MENU;
			break;
		}
	}
	LogoRelease();
	
}
void LogoRender(int Filcker)
{
	setColor(WHITE);
	for (int i = 0; i < 11; i++)
	{
		posXY(10, 5+i);
		printf(LogoMap[i]);
		printf("\n");
	}

	if (Filcker % 2 == 0)
	{
		posXY(20, 20);
		setColor(RED);
		printf("Enter 누르세요");
	}
	setColor(WHITE);
}
void LogoRelease()
{
	for (int i = 0; i < 12; i++)
	{
		LogoMap[i] = nullptr;
	}
}
#pragma endregion

#pragma region Menu
void MenuInitialize()
{
}
void MenuProgress()
{
	int menuNum = 1;
	MenuInitialize();
	DeleteCurosr();
	while (true)
	{
		system("cls");
		
		if (menuNum == 1 &&GetAsyncKeyState(VK_RIGHT)){ menuNum = 2; }
		if (menuNum == 2 && GetAsyncKeyState(VK_LEFT)){ menuNum = 1; }
		if (menuNum == 1 && GetAsyncKeyState(VK_RETURN)) { menu = Avoid; break; }
		if (menuNum == 2 && GetAsyncKeyState(VK_RETURN)) { menu = EXIT; break; }
		MenuRender(menuNum);
		
		Sleep(100);
	}
}
int next = 0;
void MenuRender(int Num)
{
	if (Num == 1)
	{
		setColor(RED);
		posXY(20, 20);
		printf("시작");
		setColor(WHITE);
		posXY(30, 20);
		printf("종료");
		setColor(WHITE);
	}
	if (Num == 2)
	{
		setColor(WHITE);
		posXY(20, 20);
		printf("시작");
		setColor(RED);
		posXY(30, 20);
		printf("종료");
		setColor(WHITE);
	}
}
void MenuRelease()
{

}
#pragma endregion

#pragma region Avoid
void AvoidInitialize()
{
	RandomRager();
	RandomTile();
	pAvoidMap = AvoidMap;
	player = (Obj*)malloc(sizeof(player));
	player->x = 10;
	player->y = 10;
	player->shape[0] = "옷";
}
void AvoidProgress()
{
	AvoidInitialize();
	DeleteCurosr();
	while (true)
	{
		system("cls");
		DeleteCurosr();
		AvoidRender();
		createTile();
		Move(AvoidMap);
		Gravity(AvoidMap, player,isJump);
		Jump(AvoidMap, player);
		if (AvoidMap[player->y][player->x] == 3)
		{
			while (true)
			{
				system("cls");
				printf("사망");
				printf("계속하려면 Enter를 누르세요");
				if (AvoidMap[player->y][player->x] == 3 && GetAsyncKeyState(VK_RETURN))
				{
					menu = LOGO;
					break;
				}
			}
		}
		if (menu == LOGO) { break; }
		AliveTime++;
		Sleep(AvoiDelay);
	}
	AvoidRelease();
}
void AvoidRender()
{
	ShowMap(pAvoidMap);
	posXY(player->x, player->y);
	printf(player->shape[0]);
	//for (int i = 0; i < 100; i++)
	//{
	//	laserAttack(randRager->randomTime[i], randRager->randomDangertime[i], randRager->randomDealTime[i], randRager->randomHight[i]);
	//}
}
void AvoidRelease()
{
	free(player);
	player = nullptr;

	pAvoidMap = nullptr;

	free(randRager);
	randRager = nullptr;
}
#pragma endregion

#pragma region physics
void Gravity(int(*Map)[40], Obj * obj, bool jump)
{
	if (Map[obj->y+1][obj->x] < 4 && !jump)
	{
		obj->y++;
	}
}
void Jump(int(*Map)[40], Obj* obj)
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		isJump = true;
	}
	if (isJump && JumpHight<5)
	{
		obj->y--;
		JumpHight++;
	}
	else { isJump = false; JumpHight = 0; }
}
void laserAttack(int time, int Dangertime, int dealTime, int hight) //실행시킬 시간, 위험표시 시간, 터지는 시간, 높이
{
	if (AliveTime == time)
	{
		
		
		for (int x = 1; x < 39; x++)
		{
			
			AvoidMap[hight + 1][x] = 4;
			AvoidMap[hight + 3][x] = 4;

		}
		AvoidMap[hight + 2][20] = 5; 
	}
	if ( AliveTime>time &&  11>(time + Dangertime - AliveTime)/2 && (time + Dangertime - AliveTime)/2>-1)
	{
		SetIntStringPosition(1, hight, (time + Dangertime -AliveTime)/2, "");
	}
	if (AliveTime == time + Dangertime)
	{
		for (int x = 1; x < 39; x++)
		{
			AvoidMap[hight + 1][x] = 3;
			AvoidMap[hight + 2][x] = 3;
			AvoidMap[hight + 3][x] = 3;

		}
	}
	if (AliveTime == time + Dangertime + dealTime)
	{
		for (int x = 1; x < 39; x++)
		{
			if (AvoidMap[hight + 1][x] ==3)
			{
				AvoidMap[hight + 1][x] = 0;
			}
			if (AvoidMap[hight + 2][x] == 3)
			{
				AvoidMap[hight + 2][x] = 0;
			}
			if (AvoidMap[hight + 3][x] == 3)
			{
				AvoidMap[hight + 3][x] = 0;
			}
		}
	}
}
void RandomRager()
{
	randRager = (Rager*)malloc(sizeof(Rager));
	
	for (int i = 0; i < 100; i++)
	{
		randRager->randomTime[i] = rand() % 5000;
		randRager->randomDangertime[i] = (rand() % 30 + 20) - i / 10;
		randRager->randomDealTime[i] = (rand() % 20 + 10) - i / 10;
		randRager->randomHight[i] = rand() % 5 + 10; //15가 멕스
	}
}
void RandomTile()
{
	randtile = (Tile*)malloc(sizeof(Tile)*100);
	for (int i = 0; i < 100; i++)
	{
		randtile[i].x = rand() % 35 + 1;
		randtile[i].y = rand() % 6 + 10;
		randtile[i].randomtime % 100;
	}

}
void createTile()
{
	
	for (int i = 0; i < 100; i++)
	{
		if (AliveTime > randtile[i].randomtime)
		{
			for (int j = 0; j < 4; j++)
			{
				AvoidMap[randtile[i].y][randtile[i].x + j] == 7;
			}
		}
	}
}
#pragma endregion
