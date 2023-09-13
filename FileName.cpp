#include <stdio.h>
#include <Windows.h>
#include <time.h>
#define LogoDelay 1000
#define MenuDelay 100
#define AvoiDelay 10
#define AvoidMapX 40
#define AvoidMapY 20
#define PlayDelay 10


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
	PLAY,
	Avoid,
};
MyEnum menu = LOGO;

struct Obj
{
	int x; 
	int y;
	int color;
	int look=1;
	int HP;
	const char* shape[100];
	const char* Die;
};
Obj* player;
Obj* enemy[10];
bool isJump = false;
int JumpHight = 0;
int AliveTime = 0;

struct Grenade
{
	int x;
	int y;
	int look = 1;
	const char* shape;
	const char* explode[4];
	int Hight;
	bool blacked;
	int count;
};
Grenade* grenade[3] = {};

struct Rager
{
	int randomTime[100];
	int randomDangertime[100];
	int randomDealTime[100];
	int randomHight[100];
};
Rager* randRager;

struct Bullet
{
	int x;
	int y;
	double speed;
	int look;
	const char* shape;
	int damage;
	int delay;
};
Bullet* bullet[10] = {};
int gunDelay = 4;
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

#pragma region Play
void PlayInitialize();
void PlayProgress();
void PlayRender();
void PlayRelease();
void MoveGrenadeAndDelete();
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
void CreateBullte(int i);
void Creategrenade();
#pragma endregion
///////////////////////////////////////////////////////////////////////////////////
int main()
{
	srand(time(NULL));
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
		case PLAY:
			PlayProgress();
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
		player->look = 5;
		if (Map[player->y][player->x] > 4) { player->x++; }
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		player->x++;
		player->look = 1;
		if (Map[player->y][player->x] > 4) { player->x--; }
	}
	if (GetAsyncKeyState(VK_UP))
	{
		player->look = 3;
		if (Map[player->y][player->x] > 4) { player->y++; }
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		player->y++;
		player->look = 7;
		if (Map[player->y][player->x] > 4) { player->y--; }
	}
	if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_UP)) { player->look = 2; }
	if (GetAsyncKeyState(VK_LEFT)  && GetAsyncKeyState(VK_UP)) { player->look = 4; }
	if (GetAsyncKeyState(VK_LEFT)  && GetAsyncKeyState(VK_DOWN)) { player->look = 6; }
	if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_DOWN)) { player->look = 8; }
	if (!(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_UP)|| GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_DOWN))) { player->look = player->look; }
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
		if (menuNum == 1 && GetAsyncKeyState(VK_RETURN)) { menu = PLAY; break; }
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
void clearMap()
{
	for (int y = 1; y < 19; y++)
	{
		for (int x = 1; x < 39; x++)
		{
			AvoidMap[y][x] = 0;
		}
	}
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
		if (menu == LOGO) { clearMap(); AliveTime = 0;  break;  }
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
	for (int i = 0; i < 100; i++)
	{
		laserAttack(randRager->randomTime[i], randRager->randomDangertime[i], randRager->randomDealTime[i], randRager->randomHight[i]);
	}
	
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

#pragma region Play
void PlayInitialize()
{
	pAvoidMap = AvoidMap;
	player = (Obj*)malloc(sizeof(Obj));
	player->x = 10;
	player->y = 10;
	player->shape[0] = "옷";
	player->HP = 10; 
	player->Die = "어<";

	
	enemy[0] = (Obj*)malloc(sizeof(Obj));
	enemy[0]->x = 20;
	enemy[0]->y = 10;
	enemy[0]->HP = 5;
	enemy[0]->shape[0] = "봇";
	enemy[0]->Die = "퍼<";

	enemy[1] = (Obj*)malloc(sizeof(Obj));
	enemy[1]->x = 25;
	enemy[1]->y = 10;
	enemy[1]->HP = 5;
	enemy[1]->shape[0] = "봇";
	enemy[1]->Die = "퍼<";

	enemy[2] = (Obj*)malloc(sizeof(Obj));
	enemy[2]->x = 4;
	enemy[2]->y = 10;
	enemy[2]->HP = 5;
	enemy[2]->shape[0] = "봇";
	enemy[2]->Die = "퍼<";
}
void PlayProgress()
{
	bool Finish = false;
	int Faild = 0;
	int delay = 3;
	PlayInitialize();
	while (true)
	{
		system("cls");
		Move(AvoidMap);
		Gravity(AvoidMap, player, isJump);
		Gravity(AvoidMap, enemy[0], isJump);
		Jump(AvoidMap, player);
		PlayRender();
		if (GetAsyncKeyState(0x5A) && delay>3)
		{
			delay = 0;
			
			for (int i = 0; i < 10; i++)
			{
				if (bullet[i] == nullptr)
				{
					CreateBullte(i);
					break;
				}
			}
		}
		if (GetAsyncKeyState(0x58))
		{
			Creategrenade();
		}
		if (player->HP < 1)
		{
			Faild++;
		}
		
		if (Faild > 20){
			while (true)
			{
				system("cls");
				printf("사망했슴\n");
				printf("나가기 Enter");
				if (GetAsyncKeyState(VK_RETURN))
				{
					menu = LOGO;
					Finish = true;
					break;
				}
				Sleep(100);
			}
			
		}
		if (Finish) { break; }
		Sleep(PlayDelay);
		delay++;
	}
}
void MoveBulletAndDelete()
{
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			posXY(bullet[i]->x, bullet[i]->y);
			printf(bullet[i]->shape);
			switch (bullet[i]->look)
			{
			case 1:
				bullet[i]->x += bullet[i]->speed;
				break;
			case 2:
				bullet[i]->x += bullet[i]->speed;
				bullet[i]->y -= bullet[i]->speed;
				break;
			case 3:
				bullet[i]->y -= bullet[i]->speed;
				break;
			case 4:
				bullet[i]->x -= bullet[i]->speed;
				bullet[i]->y -= bullet[i]->speed;
				break;
			case 5:
				bullet[i]->x -= bullet[i]->speed;
				break;
			case 6:
				bullet[i]->x -= bullet[i]->speed;
				bullet[i]->y += bullet[i]->speed;
				break;
			case 7:
				bullet[i]->y += bullet[i]->speed;
				break;
			case 8:
				bullet[i]->x += bullet[i]->speed;
				bullet[i]->y += bullet[i]->speed;
				break;
			default:
				bullet[i]->x += bullet[i]->speed;
				break;
			}
			if (bullet[i]->x < 0 || 45 < bullet[i]->x || bullet[i]->y < 0 || 25 < bullet[i]->y)
			{
				free(bullet[i]);
				bullet[i] = nullptr;
			}
			else if (AvoidMap[bullet[i]->y][bullet[i]->x] > 5)
			{
				switch (bullet[i]->look)
				{
				case(1):
					posXY(bullet[i]->x - 1, bullet[i]->y);
					printf(" :");
					break;
				case(2):
					posXY(bullet[i]->x - 1, bullet[i]->y + 1);
					printf("'.");
					break;
				case(3):
					posXY(bullet[i]->x, bullet[i]->y + 1);
					printf("''");
					break;
				case(4):
					posXY(bullet[i]->x + 1, bullet[i]->y + 1);
					printf(".'");
					break;
				case(5):
					posXY(bullet[i]->x + 1, bullet[i]->y);
					printf(": ");
					break;
				case(6):
					posXY(bullet[i]->x + 1, bullet[i]->y - 1);
					printf("'.");
					break;
				case(7):
					posXY(bullet[i]->x, bullet[i]->y - 1);
					printf("..");
					break;
				case(8):
					posXY(bullet[i]->x - 1, bullet[i]->y - 1);
					printf(".'");
					break;
				default:
					break;
				}
				free(bullet[i]);
				bullet[i] = nullptr;
			}
		}
		if (enemy != nullptr && bullet[i] != nullptr)
		{
			if ((int)enemy[0]->x == bullet[i]->x && (int)enemy[0]->y == bullet[i]->y)
			{
				enemy[0]->HP--;
				free(bullet[i]);
				bullet[i] = nullptr;
			}
		}
	}
}
void MoveGrenadeAndDelete()
{
	for (int i = 0; i < 4; i++)
	{
		if (grenade[i] != nullptr)
		{
			posXY(grenade[i]->x, grenade[i]->y);
			printf(grenade[i]->shape);

			if (AvoidMap[grenade[i]->y+1][grenade[i]->x] > 5)
			{
				if (grenade[i]->count > 10)
				{
					
					for (int j = 0; j < 4; j++)
					{
						for (int k = 0; k < 4; k++)
						{
							if (player->x == grenade[i]->x + j && player->y == grenade[i]->y+k)
							{
								player->HP = 0;
							}
						}
						posXY(grenade[i]->x, grenade[i]->y+j-2);
						printf(grenade[i]->explode[j]);
					}
				}
				if (grenade[i]->count > 15)
				{
					free(grenade[i]);
					grenade[i] = nullptr;
					break;
				}
			}
			else
			{
				if (AvoidMap[grenade[i]->y][grenade[i]->x] > 5)
				{
					grenade[i]->blacked = true;
				}
				if(!grenade[i]->blacked){
					switch (grenade[i]->look)
					{
					case 1:
					case 2:
					case 8:
						grenade[i]->x++;
						break;
					case 4:
					case 5:
					case 6:
						grenade[i]->x--;
						break;
					default:
						break;
					}
				}
				if (grenade[i]->count < 2)
				{
					grenade[i]->y--;
				}
				else
				{
					grenade[i]->y++;
				}
			}
			(grenade[i]->count)++;
		}
	}
}
void PlayRender()
{
	ShowMap(pAvoidMap);
	if (player->HP > 0)
	{
		posXY(player->x, player->y);
		printf(player->shape[0]);
	}
	else
	{
		posXY(player->x, player->y);
		printf(player->Die);
	}
	MoveBulletAndDelete();

	if (enemy[0]->HP > 0)
	{
		posXY(enemy[0]->x, enemy[0]->y);
		printf(enemy[0]->shape[0]);
		printf("%d", enemy[0]->HP);
	}
	else
	{
		posXY(enemy[0]->x, enemy[0]->y);
		printf(enemy[0]->Die);
		printf("%d", enemy[0]->HP);
	}
	MoveGrenadeAndDelete();
}
void PlayRelease()
{

}
#pragma endregion

#pragma region physics
void Gravity(int(*Map)[40], Obj * obj, bool jump)
{
	if (Map[obj->y+1][obj->x] < 5 && !jump)
	{
		obj->y++;
	}
}
void Jump(int(*Map)[40], Obj* obj)
{
	if (GetAsyncKeyState(VK_SPACE)&& Map[obj->y+1][obj->x]>5)
	{
		isJump = true;
	}
	if (isJump && JumpHight<5)
	{
		obj->y--;
		JumpHight++;
	}
	else { isJump = false; JumpHight = 0; }
	if (isJump && Map[obj->y - 1][obj->x] > 5) { isJump = false; }
}
void laserAttack(int time, int Dangertime, int dealTime, int hight) //실행시킬 시간, 위험표시 시간, 터지는 시간, 높이
{
	if (AliveTime == time)
	{
		for (int x = 1; x < 39; x++)
		{
			if (!(AvoidMap[hight + 1][x] == 6) && !(AvoidMap[hight + 1][x] == 7))
			{
				AvoidMap[hight + 1][x] = 4;
			}
			if (!(AvoidMap[hight + 3][x] == 6) && !(AvoidMap[hight + 1][x] == 7))
			{
				AvoidMap[hight + 3][x] = 4;
			}
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
			for (int i = 1; i < 4; i++)
			{
				if (!(AvoidMap[hight + i][x] == 6))
				{
					AvoidMap[hight + i][x] = 3;
				}
			}
		}
	}
	if (AliveTime == time + Dangertime) { posXY(1, 1); }
	if (AliveTime == time + Dangertime+10) { posXY(-1, 1); }
	if (AliveTime == time + Dangertime+20) { posXY(1, -1); }
	if (AliveTime == time + Dangertime+30) { posXY(-1, -2); }
	if (AliveTime == time + Dangertime + dealTime)
	{
		for (int x = 1; x < 39; x++)
		{
			if (AvoidMap[hight + 1][x] ==3 )
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
		if (i < 20)
		{
			randRager->randomTime[i] = rand() % 500;
		}
		else if (i < 40)
		{
			randRager->randomTime[i] = rand() % 2500 +5000;
		}
		else
		{
			randRager->randomTime[i] = rand() % 8000+7500;
		}
		
		randRager->randomDangertime[i] = (rand() % 30 + 20) - i / 10;
		randRager->randomDealTime[i] = (rand() % 20 + 10) - i / 10;
		randRager->randomHight[i] = rand() % 6 + 10; //15가 멕스
	}
}
void RandomTile()
{
	randtile = (Tile*)malloc(sizeof(Tile)*100);
	for (int i = 0; i < 100; i++)
	{
		randtile[i].x = rand() % 35 + 1;
		randtile[i].y = rand() % 6 + 10;
		randtile[i].randomtime = rand() % 50000;
	}

}
void createTile()
{
	for (int i = 0; i < 100; i++)
	{
		if (AliveTime == randtile[i].randomtime)
		{
			for (int j = 0; j < 4; j++)
			{
				AvoidMap[randtile[i].y][randtile[i].x + j] = 7;
			}
		}
	}
}
void CreateBullte(int i)
{
	
	bullet[i] = (Bullet*)malloc(sizeof(Bullet));

	if (bullet[i] != nullptr)
	{
		switch (player->look)
		{
		case 1:
			bullet[i]->x = player->x + 1;
			bullet[i]->y = player->y;
			bullet[i]->shape = "──";
			break;
		case 2:
			bullet[i]->x = player->x + 1;
			bullet[i]->y = player->y - 1;
			bullet[i]->shape = "／";
			break;
		case 3:
			bullet[i]->x = player->x;
			bullet[i]->y = player->y - 1;
			bullet[i]->shape = " │";
			break;
		case 4:
			bullet[i]->x = player->x - 1;
			bullet[i]->y = player->y - 1;
			bullet[i]->shape = "＼";
			break;
		case 5:
			bullet[i]->x = player->x - 1;
			bullet[i]->y = player->y;
			bullet[i]->shape = "──";
			break;
		case 6:
			bullet[i]->x = player->x - 1;
			bullet[i]->y = player->y + 1;
			bullet[i]->shape = "／";
			break;
		case 7:
			bullet[i]->x = player->x;
			bullet[i]->y = player->y + 1;
			bullet[i]->shape = "│ ";
			break;
		case 8:
			bullet[i]->x = player->x + 1;
			bullet[i]->y = player->y + 1;
			bullet[i]->shape = "＼";
			break;
		default:
			bullet[i]->x = player->x + 1;
			bullet[i]->y = player->y;
			bullet[i]->shape = "──";
			break;
		}
		bullet[i]->speed = 1;
		bullet[i]->look = player->look;
		bullet[i]->damage = 1;
		bullet[i]->delay =3;
	}
}
void Creategrenade()
{
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (grenade[i] == nullptr){ 

			grenade[i] = (Grenade*)malloc(sizeof(Grenade));
			grenade[i]->shape = "◎";
			grenade[i]->x = player->x;
			grenade[i]->y = player->y-1;
			grenade[i]->look = player->look;
			grenade[i]->Hight = 0;
			grenade[i]->blacked = false;
			grenade[i]->count = 0;
			grenade[i]->explode[0] = "※※※※";
			grenade[i]->explode[1] = "※※※※";
			grenade[i]->explode[2] = "※※※※";
			grenade[i]->explode[3] = "※※※※";
			break; 
		}
	}
	

}
#pragma endregion
