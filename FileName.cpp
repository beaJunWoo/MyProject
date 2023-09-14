#include <stdio.h>
#include <Windows.h>
#include <time.h>
//딜레이
#define LogoDelay 100
#define MenuDelay 100
#define AvoiDelay 10
#define PlayDelay 10
//맵크기
#define AvoidMapX 40
#define AvoidMapY 20
//로고,메뉴크기
#define LogoSize 18
#define MenuSize 18

const char* LogoTitle[100];
const char* MenuTitle[100];
const char* MenuMap[100][LogoSize];


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
int LogoPage = 0;
void LogoInitialize()
{
	LogoTitle[0] =  "                                                                    dddddddd                                                            ";
	LogoTitle[1] =  "DDDDDDDDDDDDD                                                       d::::::d  lllllll    iiii                                           ";
	LogoTitle[2] =  "D::::::::::::DDD                                                    d::::::d  l:::::l   i::::i                                          ";
	LogoTitle[3] =  "D:::::::::::::::DD                                                  d::::::d  l:::::l    iiii                                           ";
	LogoTitle[4] =  "DDD:::::DDDDD:::::D                                                 d:::::d   l:::::l                                                   ";
	LogoTitle[5] =  "  D:::::D    D:::::D     eeeeeeeeeeee    aaaaaaaaaaaaa      ddddddddd:::::d    l::::l  iiiiiii  nnnn  nnnnnnnn          eeeeeeeeeeee    ";
	LogoTitle[6] =  "  D:::::D     D:::::D  ee::::::::::::ee  a::::::::::::a   dd::::::::::::::d    l::::l  i:::::i  n:::nn::::::::nn      ee::::::::::::ee  ";
	LogoTitle[7] =  "  D:::::D     D:::::D e::::::eeeee:::::eeaaaaaaaaa:::::a d::::::::::::::::d    l::::l   i::::i  n::::::::::::::nn    e::::::eeeee:::::ee";
	LogoTitle[8] =  "  D:::::D     D:::::De::::::e     e:::::e         a::::ad:::::::ddddd:::::d    l::::l   i::::i  nn:::::::::::::::n  e::::::e     e:::::e";
	LogoTitle[9] =  "  D:::::D     D:::::De:::::::eeeee::::::e  aaaaaaa:::::ad::::::d    d:::::d    l::::l   i::::i    n:::::nnnn:::::n  e:::::::eeeee::::::e";
	LogoTitle[10] = "  D:::::D     D:::::De:::::::::::::::::e aa::::::::::::ad:::::d     d:::::d    l::::l   i::::i    n::::n    n::::n  e:::::::::::::::::e ";
	LogoTitle[11] = "  D:::::D     D:::::De::::::eeeeeeeeeee a::::aaaa::::::ad:::::d     d:::::d    l::::l   i::::i    n::::n    n::::n  e::::::eeeeeeeeeee  ";
	LogoTitle[12] = "  D:::::D    D:::::D e:::::::e         a::::a    a:::::ad:::::d     d:::::d    l::::l   i::::i    n::::n    n::::n  e:::::::e           ";
	LogoTitle[13] = "DDD:::::DDDDD:::::D  e::::::::e        a::::a    a:::::ad::::::ddddd::::::dd  l::::::l i::::::i   n::::n    n::::n  e::::::::e          ";
	LogoTitle[14] = "D:::::::::::::::DD    e::::::::eeeeeeeea:::::aaaa::::::a d:::::::::::::::::d  l::::::l i::::::i   n::::n    n::::n   e::::::::eeeeeeee  ";
	LogoTitle[15] = "D::::::::::::DDD       ee:::::::::::::e a::::::::::aa:::a d:::::::::ddd::::d  l::::::l i::::::i   n::::n    n::::n    ee:::::::::::::e  ";
	LogoTitle[16] = "DDDDDDDDDDDDD            eeeeeeeeeeeeee  aaaaaaaaaa  aaaa  ddddddddd   ddddd  llllllll iiiiiiii   nnnnnn    nnnnnn      eeeeeeeeeeeeee  ";

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
		if (GetAsyncKeyState(VK_SPACE))
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
	
	if (Filcker %10 >5)
	{
		posXY(40, 30);
		setColor(RED);
		printf("SPACE를 누르세요");
	}
	setColor(WHITE);

	for (int i = 0; i < 17; i++)
	{
		posXY(10, 5 + i);
		printf(LogoTitle[i]);
	}
}
void LogoRelease()
{
	for (int i = 0; i < 12; i++)
	{
		LogoTitle[i] = nullptr;
	}
}
#pragma endregion

#pragma region Menu


void MenuInitialize()
{

	 MenuTitle[0]=  "888888ba                          dP dP oo                  ";
	 MenuTitle[1]=  "88    `8b                         88 88                     ";
	 MenuTitle[2]=  "88     88 .d8888b. .d8888b. .d888b88 88 dP 88d888b. .d8888b. ";
	 MenuTitle[3]=  "88     88 88ooood8 88'  `88 88'  `88 88 88 88'  `88 88ooood8 ";
	 MenuTitle[4]=  "88    .8P 88.  ... 88.  .88 88.  .88 88 88 88    88 88.  ... ";
	 MenuTitle[5]=  "8888888P  `88888P' `88888P8 `88888P8 88 dP dP    dP `88888P' ";

	MenuMap[0][0 ] = "                                                                                                                                   ";
	MenuMap[0][1 ] = "                                                                                                                                   ";
	MenuMap[0][2 ] = "                                                                                                                                   ";
	MenuMap[0][3 ] = "                                                                                                                                   ";
	MenuMap[0][4 ] = "                                                                                                                                   ";
	MenuMap[0][5 ] = "                                                                                                                                   ";
	MenuMap[0][6 ] = "                                                                                                                                   ";
	MenuMap[0][7 ] = "                                                                                                                                   ";
	MenuMap[0][8 ] = "                                                                                                                                   ";
	MenuMap[0][9 ] = "                                                                                                                                   ";
	MenuMap[0][10] = "                                                                                                                                   ";
	MenuMap[0][11] = "                                                                                                                                   ";
	MenuMap[0][12] = "                                                                                                                                   ";
	MenuMap[0][13] = "                                                                                                                                   ";
	MenuMap[0][14] = "                                                                                                                                   ";
	MenuMap[0][15] = "                                                                                                                                   ";
	MenuMap[0][16] = "                                                                                                                                   ";
	MenuMap[0][17] = "                                                                                                                                   ";

	MenuMap[1][0 ] = "                                                                                                                                   ";
	MenuMap[1][1 ] = "                                                                                                                                   ";
	MenuMap[1][2 ] = "                                                                                                                                   ";
	MenuMap[1][3 ] = "                                                                                                                            11111  ";
	MenuMap[1][4 ] = "                                                                                                                           11111111";
	MenuMap[1][5 ] = "                                                                                                                                   ";
	MenuMap[1][6 ] = "                                                                                                                                   ";
	MenuMap[1][7 ] = "                                                                                                                                   ";
	MenuMap[1][8 ] = "                                                                                                                                  1";
	MenuMap[1][9 ] = "                                                                                                                             111111";
	MenuMap[1][10] = "                                                                                                                            1000000";
	MenuMap[1][11] = "                                                                                                                              11100";
	MenuMap[1][12] = "                                                                                                                               1000";
	MenuMap[1][13] = "                                                                                                                                110";
	MenuMap[1][14] = "                                                                                                                                  1";
	MenuMap[1][15] = "                                                                                                                                   ";
	MenuMap[1][16] = "                                                                                                                                   ";
	MenuMap[1][17] = "                                                                                                                                   ";

	MenuMap[2][0 ] = "                                                                                                                                   ";
	MenuMap[2][1 ] = "                                                                                                                                   ";
	MenuMap[2][2 ] = "                                                                                                                                   ";
	MenuMap[2][3 ] = "                                                                                                                    11111          ";
	MenuMap[2][4 ] = "                                                                                                                   1111111111111111";
	MenuMap[2][5 ] = "                                                                                                                                   ";
	MenuMap[2][6 ] = "                                                                                                                                   ";
	MenuMap[2][7 ] = "                                                                                                                                   ";
	MenuMap[2][8 ] = "                                                                                                                          11111  11";
	MenuMap[2][9 ] = "                                                                                                                     11111111111  1";
	MenuMap[2][10] = "                                                                                                                    100000001111111";
	MenuMap[2][11] = "                                                                                                                      1110000111111";
	MenuMap[2][12] = "                                                                                                                       100000011111";
	MenuMap[2][13] = "                                                                                                                        11000000111";
	MenuMap[2][14] = "                                                                                                                          110000011";
	MenuMap[2][15] = "                                                                                                                            1111000";
	MenuMap[2][16] = "                                                                                                                                111";
	MenuMap[2][17] = "                                                                                                                                   ";

	MenuMap[3][0 ] = "                                                                                                                                   ";
	MenuMap[3][1 ] = "                                                                                                                                   ";
	MenuMap[3][2 ] = "                                                                                                                                   ";
	MenuMap[3][3 ] = "                                                                                                            11111                  ";
	MenuMap[3][4 ] = "                                                                                                           111111111111111111111111";
	MenuMap[3][5 ] = "                                                                                                                             111111";
	MenuMap[3][6 ] = "                                                                                                                               1111";
	MenuMap[3][7 ] = "                                                                                                                               1111";
	MenuMap[3][8 ] = "                                                                                                                  11111  111   1111";
	MenuMap[3][9 ] = "                                                                                                             11111111111  1111     ";
	MenuMap[3][10] = "                                                                                                            10000000111111111111111";
	MenuMap[3][11] = "                                                                                                              111000011111111111111";
	MenuMap[3][12] = "                                                                                                               10000001111111111111";
	MenuMap[3][13] = "                                                                                                                1100000011111111111";
	MenuMap[3][14] = "                                                                                                                  11000001100000001";
	MenuMap[3][15] = "                                                                                                                    111100000000000";
	MenuMap[3][16] = "                                                                                                                        11111111111";
	MenuMap[3][17] = "                                                                                                                                   ";

	MenuMap[4][0 ] = "                                                                                                                                 11";
	MenuMap[4][1 ] = "                                                                                                                                   ";
	MenuMap[4][2 ] = "                                                                                                                                   ";
	MenuMap[4][3 ] = "                                                                                                    11111                        11";
	MenuMap[4][4 ] = "                                                                                                   11111111111111111111111111111111";
	MenuMap[4][5 ] = "                                                                                                                     11111111111111";
	MenuMap[4][6 ] = "                                                                                                                       111111111110";
	MenuMap[4][7 ] = "                                                                                                                       111111111111";
	MenuMap[4][8 ] = "                                                                                                          11111  111   111111111111";
	MenuMap[4][9 ] = "                                                                                                     11111111111  1111        11111";
	MenuMap[4][10] = "                                                                                                    1000000011111111111111111111111";
	MenuMap[4][11] = "                                                                                                      11100001111111111111111111111";
	MenuMap[4][12] = "                                                                                                       1000000111111111111111111111";
	MenuMap[4][13] = "                                                                                                        110000001111111111111111111";
	MenuMap[4][14] = "                                                                                                          1100000110000000111111111";
	MenuMap[4][15] = "                                                                                                            11110000000000000000000";
	MenuMap[4][16] = "                                                                                                                1111111111111111111";
	MenuMap[4][17] = "                                                                                                                                   ";

	MenuMap[5][0 ] = "                                                                                                                         1111111111";
	MenuMap[5][1 ] = "                                                                                                                            1000001";
	MenuMap[5][2 ] = "                                                                                                                             11 11 ";
	MenuMap[5][3 ] = "                                                                                            11111                        1111111111";
	MenuMap[5][4 ] = "                                                                                           1111111111111111111111111111111111111111";
	MenuMap[5][5 ] = "                                                                                                             1111111111111111111111";
	MenuMap[5][6 ] = "                                                                                                               11111111111001111111";
	MenuMap[5][7 ] = "                                                                                                               11111111111111111111";
	MenuMap[5][8 ] = "                                                                                                  11111  111   11111111111111111111";
	MenuMap[5][9 ] = "                                                                                             11111111111  1111        1111111111111";
	MenuMap[5][10] = "                                                                                            100000001111111111111111111111110000000";
	MenuMap[5][11] = "                                                                                              1110000111111111111111111111111110000";
	MenuMap[5][12] = "                                                                                               100000011111111111111111111111110000";
	MenuMap[5][13] = "                                                                                                11000000111111111111111111111110000";
	MenuMap[5][14] = "                                                                                                  110000011000000011111111111110000";
	MenuMap[5][15] = "                                                                                                    1111000000000000000000000000000";
	MenuMap[5][16] = "                                                                                                        1111111111111111111111  1  ";
	MenuMap[5][17] = "                                                                                                                                   ";
	
	MenuMap[6][0 ] = "                                                                                                                 1111111111        ";
	MenuMap[6][1 ] = "                                                                                                                    1000001     111";
	MenuMap[6][2 ] = "                                                                                                                     11 11     1101";
	MenuMap[6][3 ] = "                                                                                    11111                        111111111111111111";
	MenuMap[6][4 ] = "                                                                                   11111111111111111111111111111111111111111111111 ";
	MenuMap[6][5 ] = "                                                                                                     11111111111111111111111111111 ";
	MenuMap[6][6 ] = "                                                                                                       111111111110011111111111111 ";
	MenuMap[6][7 ] = "                                                                                                       1111111111111111111111111111";
	MenuMap[6][8 ] = "                                                                                          11111  111   1111111111111111111111111111";
	MenuMap[6][9 ] = "                                                                                     11111111111  1111        11111111111111  11   ";
	MenuMap[6][10] = "                                                                                    100000001111111111111111111111110000000        ";
	MenuMap[6][11] = "                                                                                      11100001111111111111111111111111100001       ";
	MenuMap[6][12] = "                                                                                       10000001111111111111111111111111000011111111";
	MenuMap[6][13] = "                                                                                        1100000011111111111111111111111000011000111";
	MenuMap[6][14] = "                                                                                          11000001100000001111111111111000010001111";
	MenuMap[6][15] = "                                                                                            111100000000000000000000000000000000111";
	MenuMap[6][16] = "                                                                                                1111111111111111111111  1  00000111";
	MenuMap[6][17] = "                                                                                                                           11111111";

	MenuMap[7][0 ] = "                                                                                                         1111111111                ";
	MenuMap[7][1 ] = "                                                                                                            1000001     1111111111 ";
	MenuMap[7][2 ] = "                                                                                                             11 11     110111101111";
	MenuMap[7][3 ] = "                                                                            11111                        11111111111111111111111 11";
	MenuMap[7][4 ] = "                                                                           11111111111111111111111111111111111111111111111 11111111";
	MenuMap[7][5 ] = "                                                                                             11111111111111111111111111111 11111111";
	MenuMap[7][6 ] = "                                                                                               111111111110011111111111111  1111111";
	MenuMap[7][7 ] = "                                                                                               111111111111111111111111111111111111";
	MenuMap[7][8 ] = "                                                                                  11111  111   111111111111111111111111111111111111";
	MenuMap[7][9 ] = "                                                                             11111111111  1111        11111111111111  11       11  ";
	MenuMap[7][10] = "                                                                            100000001111111111111111111111110000000            11  ";
	MenuMap[7][11] = "                                                                              11100001111111111111111111111111100001           11  ";
	MenuMap[7][12] = "                                                                               1000000111111111111111111111111100001111111111111111";
	MenuMap[7][13] = "                                                                                110000001111111111111111111111100001100011100011101";
	MenuMap[7][14] = "                                                                                  1100000110000000111111111111100001000111110111111";
	MenuMap[7][15] = "                                                                                    11110000000000000000000000000000000011110111111";
	MenuMap[7][16] = "                                                                                        1111111111111111111111  1  0000011100011100";
	MenuMap[7][17] = "                                                                                                                   11111111111     ";

	MenuMap[8][0 ] = "                                                                                                 1111111111                        ";
	MenuMap[8][1 ] = "                                                                                                    1000001     1111111111         ";
	MenuMap[8][2 ] = "                                                                                                     11 11     110111101111        ";
	MenuMap[8][3 ] = "                                                                    11111                        11111111111111111111111 111  1    ";
	MenuMap[8][4 ] = "                                                                   11111111111111111111111111111111111111111111111 1111111111111111";
	MenuMap[8][5 ] = "                                                                                     11111111111111111111111111111 1111111111111111";
	MenuMap[8][6 ] = "                                                                                       111111111110011111111111111  111111111111111";
	MenuMap[8][7 ] = "                                                                                       11111111111111111111111111111111111111111111";
	MenuMap[8][8 ] = "                                                                          11111  111   11111111111111111111111111111111111111111111";
	MenuMap[8][9 ] = "                                                                     11111111111  1111        11111111111111  11       11   11 11  ";
	MenuMap[8][10] = "                                                                    100000001111111111111111111111110000000            11    1  1  ";
	MenuMap[8][11] = "                                                                      11100001111111111111111111111111100001           11   11  1  ";
	MenuMap[8][12] = "                                                                       100000011111111111111111111111110000111111111111111111111111";
	MenuMap[8][13] = "                                                                        11000000111111111111111111111110000110001110001110111011111";
	MenuMap[8][14] = "                                                                          110000011000000011111111111110000100011111011111111111111";
	MenuMap[8][15] = "                                                                            1111000000000000000000000000000000001111011111111111111";
	MenuMap[8][16] = "                                                                                1111111111111111111111  1  000001110001110000011111";
	MenuMap[8][17] = "                                                                                                           11111111111             ";
	
	MenuMap[9][0 ] = "                                                                              1111111111                                           ";
	MenuMap[9][1 ] = "                                                                                 1000001     1111111111                            ";
	MenuMap[9][2 ] = "                                                                                  11 11     110111101111                           ";
	MenuMap[9][3 ] = "                                                 11111                        11111111111111111111111 111  1    1                  ";
	MenuMap[9][4 ] = "                                                11111111111111111111111111111111111111111111111 1111111111111111111                ";
	MenuMap[9][5 ] = "                                                                  11111111111111111111111111111 11111111111111111111111            ";
	MenuMap[9][6 ] = "                                                                    111111111110011111111111111  111111111111111111111             ";
	MenuMap[9][7 ] = "                                                                    111111111111111111111111111111111111111111111111111            ";
	MenuMap[9][8 ] = "                                                       11111  111   111111111111111111111111111111111111111111111111111            ";
	MenuMap[9][9 ] = "                                                  11111111111  1111        11111111111111  11       11   11 11  11111  1           ";
	MenuMap[9][10] = "                                                 100000001111111111111111111111110000000            11    1  1  11                 ";
	MenuMap[9][11] = "                                                   11100001111111111111111111111111100001           11   11  1  11                 ";
	MenuMap[9][12] = "                                                    10000001111111111111111111111111000011111111111111111111111111111111           ";
	MenuMap[9][13] = "                                                     1100000011111111111111111111111000011000111000111011101111111111111           ";
	MenuMap[9][14] = "                                                       11000001100000001111111111111000010001111101111111111111111111111           ";
	MenuMap[9][15] = "                                                         111100000000000000000000000000000000111101111111111111111011001           ";
	MenuMap[9][16] = "                                                             1111111111111111111111  1  000001110001110000011111111111             ";
	MenuMap[9][17] = "                                                                                        11111111111                                ";
	
	MenuMap[10][0 ] = "                                                                  1111111111                                                      ";
	MenuMap[10][1 ] = "                                                                     1000001     1111111111                                       ";
	MenuMap[10][2 ] = "                                                                      11 11     110111101111                                      ";
	MenuMap[10][3 ] = "                                     11111                        11111111111111111111111 111  1    1                             ";
	MenuMap[10][4 ] = "                                    11111111111111111111111111111111111111111111111 1111111111111111111                           ";
	MenuMap[10][5 ] = "                                                      11111111111111111111111111111 11111111111111111111111                       ";
	MenuMap[10][6 ] = "                                                        111111111110011111111111111  111111111111111111111                        ";
	MenuMap[10][7 ] = "                                                        111111111111111111111111111111111111111111111111111                       ";
	MenuMap[10][8 ] = "                                           11111  111   111111111111111111111111111111111111111111111111111                       ";
	MenuMap[10][9 ] = "                                      11111111111  1111        11111111111111  11       11   11 11  11111  11                     ";
	MenuMap[10][10] = "                                     100000001111111111111111111111110000000            11    1  1  11                            ";
	MenuMap[10][11] = "                                       11100001111111111111111111111111100001           11   11  1  11        111                 ";
	MenuMap[10][12] = "                                        100000011111111111111111111111110000111111111111111111111111111111111111                  ";
	MenuMap[10][13] = "                                         11000000111111111111111111111110000110001110001110111011111111111110001                  ";
	MenuMap[10][14] = "                                           11000001100000001111111111111000010001111101111111111111111111111101                   ";
	MenuMap[10][15] = "                                             1111000000000000000000000000000000001111011111111111111110110011                     ";
	MenuMap[10][16] = "                                                 1111111111111111111111  1  000001110001110000011111111111                        ";
	MenuMap[10][17] = "                                                                            11111111111                                           ";
	
	MenuMap[11][0 ] = "                                                      1111111111                                                                  ";
	MenuMap[11][1 ] = "                                                         1000001     1111111111                                                   ";
	MenuMap[11][2 ] = "                                                          11 11     110111101111                                                  ";
	MenuMap[11][3 ] = "                         11111                        11111111111111111111111 111  1    1                                         ";
	MenuMap[11][4 ] = "                        11111111111111111111111111111111111111111111111 1111111111111111111                                       ";
	MenuMap[11][5 ] = "                                          11111111111111111111111111111 11111111111111111111111                                   ";
	MenuMap[11][6 ] = "                                            111111111110011111111111111  111111111111111111111                                    ";
	MenuMap[11][7 ] = "                                            111111111111111111111111111111111111111111111111111                                   ";
	MenuMap[11][8 ] = "                               11111  111   111111111111111111111111111111111111111111111111111                                   ";
	MenuMap[11][9 ] = "                          11111111111  1111        11111111111111  11       11   11 11  11111  11                                 ";
	MenuMap[11][10] = "                         100000001111111111111111111111110000000            11    1  1  11                                        ";
	MenuMap[11][11] = "                           11100001111111111111111111111111100001           11   11  1  11        111                             ";
	MenuMap[11][12] = "                            100000011111111111111111111111110000111111111111111111111111111111111111                              ";
	MenuMap[11][13] = "                             11000000111111111111111111111110000110001110001110111011111111111110001                              ";
	MenuMap[11][14] = "                               11000001100000001111111111111000010001111101111111111111111111111101                               ";
	MenuMap[11][15] = "                                 1111000000000000000000000000000000001111011111111111111110110011                                 ";
	MenuMap[11][16] = "                                     1111111111111111111111  1  000001110001110000011111111111                                    ";
	MenuMap[11][17] = "                                                                11111111111                                                       ";
	
	MenuMap[12][0 ] = "                                          1111111111                                                                              ";
	MenuMap[12][1 ] = "                                             1000001     1111111111                                                               ";
	MenuMap[12][2 ] = "                                              11 11     110111101111                                                              ";
	MenuMap[12][3 ] = "             11111                        11111111111111111111111 111  1    1                                                     ";
	MenuMap[12][4 ] = "            11111111111111111111111111111111111111111111111 1111111111111111111                                                   ";
	MenuMap[12][5 ] = "                              11111111111111111111111111111 11111111111111111111111                                               ";
	MenuMap[12][6 ] = "                                111111111110011111111111111  111111111111111111111                                                ";
	MenuMap[12][7 ] = "                                111111111111111111111111111111111111111111111111111                                               ";
	MenuMap[12][8 ] = "                   11111  111   111111111111111111111111111111111111111111111111111                                               ";
	MenuMap[12][9 ] = "              11111111111  1111        11111111111111  11       11   11 11  11111  11                                             ";
	MenuMap[12][10] = "             100000001111111111111111111111110000000            11    1  1  11                                                    ";
	MenuMap[12][11] = "               11100001111111111111111111111111100001           11   11  1  11        111                                         ";
	MenuMap[12][12] = "                100000011111111111111111111111110000111111111111111111111111111111111111                                          ";
	MenuMap[12][13] = "                 11000000111111111111111111111110000110001110001110111011111111111110001                                          ";
	MenuMap[12][14] = "                   11000001100000001111111111111000010001111101111111111111111111111101                                           ";
	MenuMap[12][15] = "                     1111000000000000000000000000000000001111011111111111111110110011                                             ";
	MenuMap[12][16] = "                         1111111111111111111111  1  000001110001110000011111111111                                                ";
	MenuMap[12][17] = "                                                    11111111111                                                                   ";
	
	MenuMap[13][0 ] = "                           1111111111                                                                                             ";
	MenuMap[13][1 ] = "                              1000001     1111111111                                                                              ";
	MenuMap[13][2 ] = "                               11 11     110111101111                                                                             ";
	MenuMap[13][3 ] = "111                        11111111111111111111111 111  1    1                                                                    ";
	MenuMap[13][4 ] = "11111111111111111111111111111111111111111111 1111111111111111111                                                                  ";
	MenuMap[13][5 ] = "               11111111111111111111111111111 11111111111111111111111                                                              ";
	MenuMap[13][6 ] = "                 111111111110011111111111111  111111111111111111111                                                               ";
	MenuMap[13][7 ] = "                 111111111111111111111111111111111111111111111111111                                                              ";
	MenuMap[13][8 ] = "    11111  111   111111111111111111111111111111111111111111111111111                                                              ";
	MenuMap[13][9 ] = "1111111111  1111        11111111111111  11       11   11 11  11111  11                                                            ";
	MenuMap[13][10] = "0000001111111111111111111111110000000            11    1  1  11                                                                   ";
	MenuMap[13][11] = "11100001111111111111111111111111100001           11   11  1  11        111                                                        ";
	MenuMap[13][12] = " 100000011111111111111111111111110000111111111111111111111111111111111111                                                         ";
	MenuMap[13][13] = "  11000000111111111111111111111110000110001110001110111011111111111110001                                                         ";
	MenuMap[13][14] = "    11000001100000001111111111111000010001111101111111111111111111111101                                                          ";
	MenuMap[13][15] = "      1111000000000000000000000000000000001111011111111111111110110011                                                            ";
	MenuMap[13][16] = "          1111111111111111111111  1  000001110001110000011111111111                                                               ";
	MenuMap[13][17] = "                                     11111111111                                                                                  ";
	
	MenuMap[14][0 ] = "                   1111111111                                                                                                     ";
	MenuMap[14][1 ] = "                      1000001     1111111111                                                                                      ";
	MenuMap[14][2 ] = "                       11 11     110111101111                                                                                     ";
	MenuMap[14][3 ] = "                   11111111111111111111111 111  1    1                                                                            ";
	MenuMap[14][4 ] = "111111111111111111111111111111111111 1111111111111111111                                                                          ";
	MenuMap[14][5 ] = "       11111111111111111111111111111 11111111111111111111111                                                                      ";
	MenuMap[14][6 ] = "         111111111110011111111111111  111111111111111111111                                                                       ";
	MenuMap[14][7 ] = "         111111111111111111111111111111111111111111111111111                                                                      ";
	MenuMap[14][8 ] = "1  111   111111111111111111111111111111111111111111111111111                                                                      ";
	MenuMap[14][9 ] = "11  1111        11111111111111  11       11   11 11  11111  11                                                                    ";
	MenuMap[14][10] = "11111111111111111111110000000            11    1  1  11                                                                           ";
	MenuMap[14][11] = "111111111111111111111111100001           11   11  1  11        111                                                                ";
	MenuMap[14][12] = "11111111111111111111111110000111111111111111111111111111111111111                                                                 ";
	MenuMap[14][13] = "00111111111111111111111110000110001110001110111011111111111110001                                                                 ";
	MenuMap[14][14] = "0001100000001111111111111000010001111101111111111111111111111101                                                                  ";
	MenuMap[14][15] = "11000000000000000000000000000000001111011111111111111110110011                                                                    ";
	MenuMap[14][16] = "  1111111111111111111111  1  000001110001110000011111111111                                                                       ";
	MenuMap[14][17] = "                             11111111111                                                                                          ";
	
	MenuMap[15][0 ] = "           1111111111                                                                                                             ";
	MenuMap[15][1 ] = "              1000001     1111111111                                                                                              ";
	MenuMap[15][2 ] = "               11 11     110111101111                                                                                             ";
	MenuMap[15][3 ] = "           11111111111111111111111 111  1    1                                                                                    ";
	MenuMap[15][4 ] = "1111111111111111111111111111 1111111111111111111                                                                                  ";
	MenuMap[15][5 ] = "1111111111111111111111111111 11111111111111111111111                                                                              ";
	MenuMap[15][6 ] = " 111111111110011111111111111  111111111111111111111                                                                               ";
	MenuMap[15][7 ] = " 111111111111111111111111111111111111111111111111111                                                                              ";
	MenuMap[15][8 ] = " 111111111111111111111111111111111111111111111111111                                                                              ";
	MenuMap[15][9 ] = "        11111111111111  11       11   11 11  11111  11                                                                            ";
	MenuMap[15][10] = "111111111111110000000            11    1  1  11                                                                                  1";
	MenuMap[15][11] = "1111111111111111100001           11   11  1  11        111                                                                     111";
	MenuMap[15][12] = "111111111111111110000111111111111111111111111111111111111                                                                   111111";
	MenuMap[15][13] = "111111111111111110000110001110001110111011111111111110001                                                                   111100";
	MenuMap[15][14] = "00001111111111111000010001111101111111111111111111111101                                                                  11110001";
	MenuMap[15][15] = "000000000000000000000000001111011111111111111110110011                                                                     1110010";
	MenuMap[15][16] = "1111111111111111  1  000001110001110000011111111111                                                                          11000";
	MenuMap[15][17] = "                     11111111111                                                                                                10";
	
	MenuMap[16][0 ] = "   1111111111                                                                                                                     ";
	MenuMap[16][1 ] = "      1000001     1111111111                                                                                                      ";
	MenuMap[16][2 ] = "       11 11     110111101111                                                                                                     ";
	MenuMap[16][3 ] = "   11111111111111111111111 111  1    1                                                                                            ";
	MenuMap[16][4 ] = "11111111111111111111 1111111111111111111                                                                                          ";
	MenuMap[16][5 ] = "11111111111111111111 11111111111111111111111                                                                                      ";
	MenuMap[16][6 ] = "11110011111111111111  111111111111111111111                                                                                       ";
	MenuMap[16][7 ] = "11111111111111111111111111111111111111111111                                                                                      ";
	MenuMap[16][8 ] = "11111111111111111111111111111111111111111111                                                                                      ";
	MenuMap[16][9 ] = "11111111111111  11       11   11 11  11111  11                                                                            0       ";
	MenuMap[16][10] = "1111110000000            11    1  1  11                                                                                  1        ";
	MenuMap[16][11] = "11111111100001           11   11  1  11        111                                                                     11111111111";
	MenuMap[16][12] = "1111111110000111111111111111111111111111111111111                                                                   11111111111111";
	MenuMap[16][13] = "1111111110000110001110001110111011111111111110001                                                                   11110000000111";
	MenuMap[16][14] = "111111111000010001111101111111111111111111111101                                                                  1111000111110001";
	MenuMap[16][15] = "0000000000000000001111011111111111111110110011                                                                     111001001001100";
	MenuMap[16][16] = "11111111  1  000001110001110000011111111111                                                                          1100000100110";
	MenuMap[16][17] = "             11111111111                                                                                                101000110 ";
	
	MenuMap[17][0 ] = "11111                                                                                                                             ";
	MenuMap[17][1 ] = "00001     1111111111                                                                                                              ";
	MenuMap[17][2 ] = "1 11     110111101111                                                                                                             ";
	MenuMap[17][3 ] = "111111111111111111 111  1    1                                                                                                    ";
	MenuMap[17][4 ] = "111111111111 1111111111111111111                                                                                                  ";
	MenuMap[17][5 ] = "111111111111 11111111111111111111111                                                                                              ";
	MenuMap[17][6 ] = "111111111111  111111111111111111111                                                                                               ";
	MenuMap[17][7 ] = "111111111111111111111111111111111111                                                                                              ";
	MenuMap[17][8 ] = "111111111111111111111111111111111111                                                                                              ";
	MenuMap[17][9 ] = "111111  11       11   11 11  11111  11                                                                            0            111";
	MenuMap[17][10] = "00000            11    1  1  11                                                                                  1          111174";
	MenuMap[17][11] = "100001           11   11  1  11        111                                                                     1111111111111111111";
	MenuMap[17][12] = "10000111111111111111111111111111111111111                                                                   1111111111111111011111";
	MenuMap[17][13] = "10000110001110001110111011111111111110001                                                                   1111000000011111011111";
	MenuMap[17][14] = "1000010001111101111111111111111111111101                                                                  111100011111000111011111";
	MenuMap[17][15] = "00000000001111011111111111111110110011                                                                     11100100100110011111111";
	MenuMap[17][16] = "  1  000001110001110000011111111111                                                                          110000010011000111111";
	MenuMap[17][17] = "     11111111111                                                                                                101000110         ";
	
	MenuMap[18][0 ] = "                                                                                                                                  ";
	MenuMap[18][1 ] = "  1111111111                                                                                                                      ";
	MenuMap[18][2 ] = " 110111101111                                                                                                                     ";
	MenuMap[18][3 ] = "1111111111 111  1    1                                                                                                            ";
	MenuMap[18][4 ] = "1111 1111111111111111111                                                                                                          ";
	MenuMap[18][5 ] = "1111 11111111111111111111111                                                                                                      ";
	MenuMap[18][6 ] = "1111  111111111111111111111                                                                                                      -";
	MenuMap[18][7 ] = "1111111111111111111111111111                                                                                                      ";
	MenuMap[18][8 ] = "1111111111111111111111111111                                                                                                      ";
	MenuMap[18][9 ] = "11       11   11 11  11111  11                                                                            0            1111111   1";
	MenuMap[18][10] = "         11    1  1  11                                                                                  1          11117411111111";
	MenuMap[18][11] = "         11   11  1  11        111                                                                     111111111111111111111111110";
	MenuMap[18][12] = "111111111111111111111111111111111                                                                   111111111111111101111111111110";
	MenuMap[18][13] = "001110001110111011111111111110001                                                                   111100000001111101111111111110";
	MenuMap[18][14] = "01111101111111111111111111111101                                                                  11110001111100011101111111111110";
	MenuMap[18][15] = "001111011111111111111110110011                                                                     1110010010011001111111111111110";
	MenuMap[18][16] = "001110001110000011111111111                                                                          11000001001100011111111111111";
	MenuMap[18][17] = "11111111                                                                                                101000110                 ";
	
	MenuMap[19][0 ] = "                                                                                                                                  ";
	MenuMap[19][1 ] = "  1111111111                                                                                                                      ";
	MenuMap[19][2 ] = " 110111101111                                                                                                                     ";
	MenuMap[19][3 ] = "1111111111 111  1    1                                                                                                            ";
	MenuMap[19][4 ] = "1111 1111111111111111111                                                                                                          ";
	MenuMap[19][5 ] = "1111 11111111111111111111111                                                                                                      ";
	MenuMap[19][6 ] = "1111  111111111111111111111                                                                                                      -";
	MenuMap[19][7 ] = "1111111111111111111111111111                                                                                                      ";
	MenuMap[19][8 ] = "1111111111111111111111111111                                                                                                      ";
	MenuMap[19][9 ] = "11       11   11 11  11111  11                                                                            0            1111111   1";
	MenuMap[19][10] = "         11    1  1  11                                                                                  1          11117411111111";
	MenuMap[19][11] = "         11   11  1  11        111                                                                     111111111111111111111111110";
	MenuMap[19][12] = "111111111111111111111111111111111                                                                   111111111111111101111111111110";
	MenuMap[19][13] = "001110001110111011111111111110001                                                                   111100000001111101111111111110";
	MenuMap[19][14] = "01111101111111111111111111111101                                                                  11110001111100011101111111111110";
	MenuMap[19][15] = "001111011111111111111110110011                                                                     1110010010011001111111111111110";
	MenuMap[19][16] = "001110001110000011111111111                                                                          11000001001100011111111111111";
	MenuMap[19][17] = "11111111                                                                                                101000110                 ";
	
	MenuMap[20][0 ] = "                                                                                                                                  ";
	MenuMap[20][1 ] = "1111                                                                                                                              ";
	MenuMap[20][2 ] = "01111                                                                                                                             ";
	MenuMap[20][3 ] = "11 111  1    1                                                                                                                    ";
	MenuMap[20][4 ] = "1111111111111111                                                                                                                  ";
	MenuMap[20][5 ] = "11111111111111111111                                                                                                              ";
	MenuMap[20][6 ] = "1111111111111111111                                                                                                      -----1111";
	MenuMap[20][7 ] = "11111111111111111111                                                                                                          1101";
	MenuMap[20][8 ] = "11111111111111111111                                                                                                      11111111";
	MenuMap[20][9 ] = " 11   11 11  11111  11                                                                            0            1111111   1111111  ";
	MenuMap[20][10] = " 11    1  1  11                                                                                  1          1111741111111111111111";
	MenuMap[20][11] = " 11   11  1  11        111                                                                     11111111111111111111111111011111111";
	MenuMap[20][12] = "1111111111111111111111111                                                                   11111111111111110111111111111011111111";
	MenuMap[20][13] = "1110111011111111111110001                                                                   11110000000111110111111111111011111111";
	MenuMap[20][14] = "111111111111111111111101                                                                  1111000111110001110111111111111011111111";
	MenuMap[20][15] = "1111111111111110110011                                                                     111001001001100111111111111111011111111";
	MenuMap[20][16] = "1110000011111111111                                                                          1100000100110001111111111111111111111";
	MenuMap[20][17] = "                                                                                                101000110                         ";
	
	MenuMap[21][0 ] = "                                                                                                                                  ";
	MenuMap[21][1 ] = "                                                                                                                                  ";
	MenuMap[21][2 ] = "                                                                                                                                  ";
	MenuMap[21][3 ] = "1    1                                                                                                                            ";
	MenuMap[21][4 ] = "11111111                                                                                                                          ";
	MenuMap[21][5 ] = "111111111111                                                                                                                      ";
	MenuMap[21][6 ] = "11111111111                                                                                                      -----111111111111";
	MenuMap[21][7 ] = "111111111111                                                                                                          110111111111";
	MenuMap[21][8 ] = "111111111111                                                                                                      1111111111111111";
	MenuMap[21][9 ] = " 11  11111  11                                                                            0            1111111   1111111  11111111";
	MenuMap[21][10] = "  1  11                                                                                  1          1111741111111111111111111111  ";
	MenuMap[21][11] = "  1  11        111                                                                     11111111111111111111111111011111111111111 1";
	MenuMap[21][12] = "11111111111111111                                                                   1111111111111111011111111111101111111111111111";
	MenuMap[21][13] = "11111111111110001                                                                   1111000000011111011111111111101111111111111111";
	MenuMap[21][14] = "1111111111111101                                                                  111100011111000111011111111111101111111111111001";
	MenuMap[21][15] = "11111110110011                                                                     11100100100110011111111111111101111111111100011";
	MenuMap[21][16] = "11111111111                                                                          110000010011000111111111111111111111111100011";
	MenuMap[21][17] = "                                                                                        101000110                             0011";
	
	MenuMap[22][0 ] = "                                                                                                                                  ";
	MenuMap[22][1 ] = "                                                                                                                                  ";
	MenuMap[22][2 ] = "                                                                                                                                  ";
	MenuMap[22][3 ] = "                                                                                                                                  ";
	MenuMap[22][4 ] = "                                                                                                                                  ";
	MenuMap[22][5 ] = "1111                                                                                                                              ";
	MenuMap[22][6 ] = "111                                                                                                      -----11111111111111      ";
	MenuMap[22][7 ] = "1111                                                                                                          1101111111111       ";
	MenuMap[22][8 ] = "1111                                                                                                      111111111111111111111111";
	MenuMap[22][9 ] = "11  11                                                                            0            1111111   1111111  111111111       ";
	MenuMap[22][10] = "                                                                                 1          1111741111111111111111111111  11111101";
	MenuMap[22][11] = "       111                                                                     11111111111111111111111111011111111111111 11    111";
	MenuMap[22][12] = "111111111                                                                   111111111111111101111111111110111111111111111111111111";
	MenuMap[22][13] = "111110001                                                                   111100000001111101111111111110111111111111111111100011";
	MenuMap[22][14] = "11111101                                                                  11110001111100011101111111111110111111111111100111111000";
	MenuMap[22][15] = "110011                                                                     1110010010011001111111111111110111111111110001110100110";
	MenuMap[22][16] = "111                                                                          11000001001100011111111111111111111111110001100000011";
	MenuMap[22][17] = "                                                                                101000110                             00110110001 ";
	
	MenuMap[23][0 ] = "                                                                                                                                  ";
	MenuMap[23][1 ] = "                                                                                                                                  ";
	MenuMap[23][2 ] = "                                                                                                                                  ";
	MenuMap[23][3 ] = "                                                                                                                                  ";
	MenuMap[23][4 ] = "                                                                                                                                  ";
	MenuMap[23][5 ] = "                                                                                                                             1    ";
	MenuMap[23][6 ] = "                                                                                                 -----11111111111111         1    ";
	MenuMap[23][7 ] = "                                                                                                      1101111111111          1    ";
	MenuMap[23][8 ] = "                                                                                                  1111111111111111111111111  1    ";
	MenuMap[23][9 ] = "                                                                          0            1111111   1111111  111111111      1   1    ";
	MenuMap[23][10] = "                                                                         1          1111741111111111111111111111  1111110111111111";
	MenuMap[23][11] = "11                                                                     11111111111111111111111111011111111111111 11    11111111111";
	MenuMap[23][12] = "1                                                                   11111111111111110111111111111011111111111111111111111111111000";
	MenuMap[23][13] = "1                                                                   11110000000111110111111111111011111111111111111110001111111000";
	MenuMap[23][14] = "                                                                  1111000111110001110111111111111011111111111110011111100011111111";
	MenuMap[23][15] = "                                                                   111001001001100111111111111111011111111111000111010011011111   ";
	MenuMap[23][16] = "                                                                     110000010011000111111111111111111111111100011000000111       ";
	MenuMap[23][17] = "                                                                        101000110                             00110110001         ";
	
	MenuMap[24][0 ] = "                                                                                                                                  ";
	MenuMap[24][1 ] = "                                                                                                                                  ";
	MenuMap[24][2 ] = "                                                                                                                                  ";
	MenuMap[24][3 ] = "                                                                                                                                  ";
	MenuMap[24][4 ] = "                                                                                                                                  ";
	MenuMap[24][5 ] = "                                                                                                           1                      ";
	MenuMap[24][6 ] = "                                                                               -----11111111111111         1                      ";
	MenuMap[24][7 ] = "                                                                                    1101111111111          1                      ";
	MenuMap[24][8 ] = "                                                                                1111111111111111111111111  1                      ";
	MenuMap[24][9 ] = "                                                        0            1111111   1111111  111111111      1   1                      ";
	MenuMap[24][10] = "                                                       1          1111741111111111111111111111  11111101111111111                 ";
	MenuMap[24][11] = "                                                     11111111111111111111111111011111111111111 11    111111111111                 ";
	MenuMap[24][12] = "                                                  111111111111111101111111111110111111111111111111111111111110000                 ";
	MenuMap[24][13] = "                                                  111100000001111101111111111110111111111111111111100011111110001                 ";
	MenuMap[24][14] = "                                                11110001111100011101111111111110111111111111100111111000111111111                 ";
	MenuMap[24][15] = "                                                 111001001001100111111111111111011111111111000111010011011111                     ";
	MenuMap[24][16] = "                                                   110000010011000111111111111111111111111100011000000111                         ";
	MenuMap[24][17] = "                                                      101000110                             00110110001                           ";

	MenuMap[25][0 ] = "                                                                                                                                  ";
	MenuMap[25][1 ] = "                                                                                                                                  ";
	MenuMap[25][2 ] = "                                                                                                                                  ";
	MenuMap[25][3 ] = "                                                                                                                                  ";
	MenuMap[25][4 ] = "                                                                                                                                  ";
	MenuMap[25][5 ] = "                                                                                        1                                         ";
	MenuMap[25][6 ] = "                                                            -----11111111111111         1                                         ";
	MenuMap[25][7 ] = "                                                                 1101111111111          1                                         ";
	MenuMap[25][8 ] = "                                                             1111111111111111111111111  1                                         ";
	MenuMap[25][9 ] = "                                     0            1111111   1111111  111111111      1   1                                         ";
	MenuMap[25][10] = "                                    1          1111741111111111111111111111  11111101111111111                                    ";
	MenuMap[25][11] = "                                  11111111111111111111111111011111111111111 11    111111111111                                    ";
	MenuMap[25][12] = "                               1111111111111111011111111111101111111111111111111111111111100001                                   ";
	MenuMap[25][13] = "                               111100000001111101111111111110111111111111111111100011111110001                                    ";
	MenuMap[25][14] = "                             11110001111100011101111111111110111111111111100111111000111111111                                    ";
	MenuMap[25][15] = "                              111001001001100111111111111111011111111111000111010011011111                                        ";
	MenuMap[25][16] = "                                110000010011000111111111111111111111111100011000000111                                            ";
	MenuMap[25][17] = "                                   101000110                             00110110001                                              ";

	MenuMap[26][0 ] = "                                                                                                                                  ";
	MenuMap[26][1 ] = "                                                                                                                                  ";
	MenuMap[26][2 ] = "                                                                                                                                  ";
	MenuMap[26][3 ] = "                                                                                                                                  ";
	MenuMap[26][4 ] = "                                                                                                                                  ";
	MenuMap[26][5 ] = "                                                                             1                                                    ";
	MenuMap[26][6 ] = "                                                 -----11111111111111         1                                                    ";
	MenuMap[26][7 ] = "                                                      1101111111111          1                                                    ";
	MenuMap[26][8 ] = "                                                  1111111111111111111111111  1                                                    ";
	MenuMap[26][9 ] = "                          0            1111111   1111111  111111111      1   1                                                    ";
	MenuMap[26][10] = "                         1          1111741111111111111111111111  11111101111111111                                               ";
	MenuMap[26][11] = "                       11111111111111111111111111011111111111111 11    111111111111                                               ";
	MenuMap[26][12] = "                    1111111111111111011111111111101111111111111111111111111111100001                                              ";
	MenuMap[26][13] = "                    111100000001111101111111111110111111111111111111100011111110001                                               ";
	MenuMap[26][14] = "                  11110001111100011101111111111110111111111111100111111000111111111                                               ";
	MenuMap[26][15] = "                   111001001001100111111111111111011111111111000111010011011111                                                   ";
	MenuMap[26][16] = "                     110000010011000111111111111111111111111100011000000111                                                       ";
	MenuMap[26][17] = "                        101000110                             00110110001                                                         ";

	MenuMap[27][0 ] = "                                                                                                                                  ";
	MenuMap[27][1 ] = "                                                                                                                                  ";
	MenuMap[27][2 ] = "                                                                                                                                  ";
	MenuMap[27][3 ] = "                                                                                                                                  ";
	MenuMap[27][4 ] = "                                                                                                                                  ";
	MenuMap[27][5 ] = "                                                     1                                                                            ";
	MenuMap[27][6 ] = "                         -----11111111111111         1                                                                            ";
	MenuMap[27][7 ] = "                              1101111111111          1                                                                            ";
	MenuMap[27][8 ] = "                          1111111111111111111111111  1                                                                            ";
	MenuMap[27][9 ] = "  0            1111111   1111111  111111111      1   1                                                                            ";
	MenuMap[27][10] = " 1          1111741111111111111111111111  11111101111111111                                                                       ";
	MenuMap[27][11] = "1111111111111111111111111011111111111111 11    111111111111                                                                       ";
	MenuMap[27][12] = "111111111111011111111111101111111111111111111111111111100001                                                                      ";
	MenuMap[27][13] = "00000001111101111111111110111111111111111111100011111110001                                                                       ";
	MenuMap[27][14] = "01111100011101111111111110111111111111100111111000111111111                                                                       ";
	MenuMap[27][15] = "1001001100111111111111111011111111111000111010011011111                                                                           ";
	MenuMap[27][16] = "000010011000111111111111111111111111100011000000111                                                                               ";
	MenuMap[27][17] = "101000110                             00110110001                                                                                 ";

	MenuMap[28][0 ] = "                                                                                                                                  ";
	MenuMap[28][1 ] = "                                                                                                                                  ";
	MenuMap[28][2 ] = "                                                                                                                                  ";
	MenuMap[28][3 ] = "                                                                                                                                  ";
	MenuMap[28][4 ] = "                                                                                                                                  ";
	MenuMap[28][5 ] = "                                             1                                                                                    ";
	MenuMap[28][6 ] = "                 -----11111111111111         1                                                                                    ";
	MenuMap[28][7 ] = "                      1101111111111          1                                                                                    ";
	MenuMap[28][8 ] = "                  1111111111111111111111111  1                                                                                    ";
	MenuMap[28][9 ] = "       1111111   1111111  111111111      1   1                                                                                    ";
	MenuMap[28][10] = "    1111741111111111111111111111  11111101111111111                                                                               ";
	MenuMap[28][11] = "11111111111111111011111111111111 11    111111111111                                                                               ";
	MenuMap[28][12] = "1111011111111111101111111111111111111111111111100001                                                                              ";
	MenuMap[28][13] = "111101111111111110111111111111111111100011111110001                                                                               ";
	MenuMap[28][14] = "011101111111111110111111111111100111111000111111111                                                                               ";
	MenuMap[28][15] = "00111111111111111011111111111000111010011011111                                                                                   ";
	MenuMap[28][16] = "1000111111111111111111111111100011000000111                                                                                       ";
	MenuMap[28][17] = "0                             00110110001                                                                                         ";

	MenuMap[29][0 ] = "                                                                                                                                  ";
	MenuMap[29][1 ] = "                                                                                                                                  ";
	MenuMap[29][2 ] = "                                                                                                                                  ";
	MenuMap[29][3 ] = "                                                                                                                                  ";
	MenuMap[29][4 ] = "                                                                                                                                  ";
	MenuMap[29][5 ] = "                                     1                                                                                            ";
	MenuMap[29][6 ] = "         -----11111111111111         1                                                                                            ";
	MenuMap[29][7 ] = "              1101111111111          1                                                                                            ";
	MenuMap[29][8 ] = "          1111111111111111111111111  1                                                                                            ";
	MenuMap[29][9 ] = "111111   1111111  111111111      1   1                                                                                            ";
	MenuMap[29][10] = "741111111111111111111111  11111101111111111                                                                                       ";
	MenuMap[29][11] = "111111111011111111111111 11    111111111111                                                                                       ";
	MenuMap[29][12] = "11111111101111111111111111111111111111100001                                                                                      ";
	MenuMap[29][13] = "1111111110111111111111111111100011111110001                                                                                       ";
	MenuMap[29][14] = "1111111110111111111111100111111000111111111                                                                                       ";
	MenuMap[29][15] = "111111111011111111111000111010011011111                                                                                           ";
	MenuMap[29][16] = "11111111111111111111100011000000111                                                                                               ";
	MenuMap[29][17] = "                      00110110001                                                                                                 ";

	MenuMap[30][0 ] = "                                                                                                                                  ";
	MenuMap[30][1 ] = "                                                                                                                                  ";
	MenuMap[30][2 ] = "                                                                                                                                  ";
	MenuMap[30][3 ] = "                                                                                                                                  ";
	MenuMap[30][4 ] = "                                                                                                                                  ";
	MenuMap[30][5 ] = "                             1                                                                                                    ";
	MenuMap[30][6 ] = " -----11111111111111         1                                                                                                    ";
	MenuMap[30][7 ] = "      1101111111111          1                                                                                                    ";
	MenuMap[30][8 ] = "  1111111111111111111111111  1                                                                                                    ";
	MenuMap[30][9 ] = " 1111111  111111111      1   1                                                                                                    ";
	MenuMap[30][10] = "1111111111111111  11111101111111111                                                                                               ";
	MenuMap[30][11] = "1011111111111111 11    111111111111                                                                                               ";
	MenuMap[30][12] = "101111111111111111111111111111100001                                                                                              ";
	MenuMap[30][13] = "10111111111111111111100011111110001                                                                                               ";
	MenuMap[30][14] = "10111111111111100111111000111111111                                                                                               ";
	MenuMap[30][15] = "1011111111111000111010011011111                                                                                                   ";
	MenuMap[30][16] = "111111111111100011000000111                                                                                                       ";
	MenuMap[30][17] = "              00110110001                                                                                                         ";

	MenuMap[31][0 ] = "                                                                                                                                  ";
	MenuMap[31][1 ] = "                                                                                                                                  ";
	MenuMap[31][2 ] = "                                                                                                                                  ";
	MenuMap[31][3 ] = "                                                                                                                                  ";
	MenuMap[31][4 ] = "                                                                                                                                  ";
	MenuMap[31][5 ] = "                     1                                                                                                            ";
	MenuMap[31][6 ] = "111111111111         1                                                                                                            ";
	MenuMap[31][7 ] = "01111111111          1                                                                                                            ";
	MenuMap[31][8 ] = "1111111111111111111  1                                                                                                            ";
	MenuMap[31][9 ] = "  111111111      1   1                                                                                                            ";
	MenuMap[31][10] = "11111111  11111101111111111                                                                                                       ";
	MenuMap[31][11] = "11111111 11    111111111111                                                                                                       ";
	MenuMap[31][12] = "1111111111111111111111100001                                                                                                      ";
	MenuMap[31][13] = "111111111111100011111110001                                                                                                       ";
	MenuMap[31][14] = "111111100111111000111111111                                                                                                       ";
	MenuMap[31][15] = "11111000111010011011111                                                                                                           ";
	MenuMap[31][16] = "1111100011000000111                                                                                                               ";
	MenuMap[31][17] = "      00110110001                                                                                                                 ";

	MenuMap[32][0 ] = "                                                                                                                                  ";
	MenuMap[32][1 ] = "                                                                                                                                  ";
	MenuMap[32][2 ] = "                                                                                                                                  ";
	MenuMap[32][3 ] = "                                                                                                                                  ";
	MenuMap[32][4 ] = "                                                                                                                                  ";
	MenuMap[32][5 ] = "             1                                                                                                                    ";
	MenuMap[32][6 ] = "1111         1                                                                                                                    ";
	MenuMap[32][7 ] = "111          1                                                                                                                    ";
	MenuMap[32][8 ] = "11111111111  1                                                                                                                    ";
	MenuMap[32][9 ] = "111      1   1                                                                                                                    ";
	MenuMap[32][10] = "  11111101111111111                                                                                                               ";
	MenuMap[32][11] = " 11    111111111111                                                                                                               ";
	MenuMap[32][12] = "11111111111111100001                                                                                                              ";
	MenuMap[32][13] = "1111100011111110001                                                                                                               ";
	MenuMap[32][14] = "0111111000111111111                                                                                                               ";
	MenuMap[32][15] = "111010011011111                                                                                                                   ";
	MenuMap[32][16] = "11000000111                                                                                                                       ";
	MenuMap[32][17] = "110110001                                                                                                                         ";

	MenuMap[33][0 ] = "                                                                                                                                  ";
	MenuMap[33][1 ] = "                                                                                                                                  ";
	MenuMap[33][2 ] = "                                                                                                                                  ";
	MenuMap[33][3 ] = "                                                                                                                                  ";
	MenuMap[33][4 ] = "                                                                                                                                  ";
	MenuMap[33][5 ] = "     1                                                                                                                            ";
	MenuMap[33][6 ] = "     1                                                                                                                            ";
	MenuMap[33][7 ] = "     1                                                                                                                            ";
	MenuMap[33][8 ] = "111  1                                                                                                                            ";
	MenuMap[33][9 ] = " 1   1                                                                                                                            ";
	MenuMap[33][10] = "01111111111                                                                                                                       ";
	MenuMap[33][11] = "11111111111                                                                                                                       ";
	MenuMap[33][12] = "111111100001                                                                                                                      ";
	MenuMap[33][13] = "11111110001                                                                                                                       ";
	MenuMap[33][14] = "00111111111                                                                                                                       ";
	MenuMap[33][15] = "1011111                                                                                                                           ";
	MenuMap[33][16] = "111                                                                                                                               ";
	MenuMap[33][17] = "1                                                                                                                                 ";

	MenuMap[34][0 ] = "                                                                                                                                  ";
	MenuMap[34][1 ] = "                                                                                                                                  ";
	MenuMap[34][2 ] = "                                                                                                                                  ";
	MenuMap[34][3 ] = "                                                                                                                                  ";
	MenuMap[34][4 ] = "                                                                                                                                  ";
	MenuMap[34][5 ] = "                                                                                                                                  ";
	MenuMap[34][6 ] = "                                                                                                                                  ";
	MenuMap[34][7 ] = "                                                                                                                                  ";
	MenuMap[34][8 ] = "                                                                                                                                  ";
	MenuMap[34][9 ] = "                                                                                                                                  ";
	MenuMap[34][10] = "111                                                                                                                               ";
	MenuMap[34][11] = "111                                                                                                                               ";
	MenuMap[34][12] = "0001                                                                                                                              ";
	MenuMap[34][13] = "001                                                                                                                               ";
	MenuMap[34][14] = "111                                                                                                                               ";
	MenuMap[34][15] = "                                                                                                                                  ";
	MenuMap[34][16] = "                                                                                                                                  ";
	MenuMap[34][17] = "                                                                                                                                  ";



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
		posXY(20, 40);
		printf("→[시작]");
		setColor(WHITE);
		posXY(40,40);
		printf("[종료]");
		setColor(WHITE);
	}
	if (Num == 2)
	{
		setColor(WHITE);
		posXY(20, 40);
		printf("[시작]");
		setColor(RED);
		posXY(40, 40);
		printf("→[종료]");
		setColor(WHITE);
	}
	for (int i = 0; i < 6; i++)
	{
		posXY(1, 5+i);
		printf(MenuTitle[i]);
	}
	for (int i = 0; i < LogoSize; i++)
	{
		if (LogoPage > 34) { LogoPage = 0; }
		posXY(0, 15+ i);
		printf(MenuMap[LogoPage][i]);
		printf("\n");
	}
	LogoPage++;
	
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
