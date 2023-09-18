#include <stdio.h>
#include <Windows.h>

#define MapX 100
#define MapY 50

#define EnemyCount 30
#define playerBulletCount 10
#define enemyBulletCount 10
#define ItemCount 10

#define PlayerGunY -2
#define PlayerGunX 1
#define PlyaerSizeY 4

#define Weaphone1_Speed 4
#define EnemyHight -3
#define EnmeyWidth 3
#pragma endregion

#define BufferWidth 150
#define BufferHeight 70

HANDLE hBuffer[2];
int screenIndex;

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
	ADD_02,    //2번 총알 추가
};
#pragma endregion
int Map[MapY][MapX] =
   //                    10                  20                  30                  40                  50                  60 
{  //0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,
	{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,},//1
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,7,},//2
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,7,},//3
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,7,},//4
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,7,},//5
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,7,},//6
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,7,},//7
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,7,},//8
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,7,},//9
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,},//0	10
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//1
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//2
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//3
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//4
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//5
	{7,5,0,0,0,0,0,0,0,0,5,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//6
	{7,5,0,0,0,0,0,0,0,0,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//7
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//8
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//9
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//0	20
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//1
	{7,5,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//2
	{7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,5,7,},//3
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//4
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//5
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//6
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//7
	{7,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,},//8
	{7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,},//9
	{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,},//0	30
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//1
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//2
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//3
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//4
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//5
	
};
int KeyInfoMap[10][50] = {
	{3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4},
	{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6},
};

const char* WeaphoneMap[10][10];
const char* Weaphone[8][2];
const float G = 9.81;
float V = 12.0f;
float time = 0.f;
bool isKeyInfo;
int keyInfoDelay[2] = { 3,0 };

struct Player
{
	int x;
	int y;
	Color color;
	int direction = 1;
	int speed[2];
	int bulletNum[3];//[0]=1번무기 탄수
	int bulletDelay[2][3];
	int downHpDelay[2];
	int hp;
	int h;
	int weaponNum;
	bool isfloat;
	bool isJump;
	bool isDownHp;
	const char* shape[8][5];
	const char* die;
};
Player* player = nullptr;

struct Enemy
{
	int x;
	int y;
	Color color;
	int Lv;
	int hp;
	int rerodingTime[2];
	int responTime;
	bool isLeft;
	bool isDownHp;
	int downHpDelay[2];
	int moveDir[2] = { 0,0 };
	const char* shape[2][5];
	const char* die[2][5];
};
Enemy* enemy[EnemyCount] = {};

struct Item
{
	int x;
	int y;
	Color color;
	ItemEffect itemEffect;
	const char* shape[3];
};
Item* item[ItemCount] = {};

struct Trap
{
	int x;
	int y;
	int width;
	int damage;
	int attackDelay[2];
	const char* shape;
};
Trap* trap[10] = {};
struct Bullet
{
	int x;
	int y;
	int Xcount[2];
	int Ycount[2];
	int damage;
	int direction;
	int speed;
	const char* shape[8];
	const char* destroy[8];
};
struct Gun
{
	Bullet* bullet[4] = {};
};
Gun* playerBullet[playerBulletCount] = {};

Bullet* playerBullet2[playerBulletCount] = {};
Bullet* enemyBullet[enemyBulletCount] = {};
const char* bulletShape[3][8];

#pragma region DoubleBuffer
void InitBuffer();
void WriteBuffer(int x, int y, const char* shape, int color);
void FlipBuffer();
void ClearBuffer();
void DestroyBuffer();
#pragma endregion

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
void PlayerHpDownEffect();
#pragma endregion

#pragma region Enemy
void ShowEnemy();
void CreateEnemy(int x, int y, int lv);
void SettingEnemy(int x, int y, int lv);
void AttackEnemy();
void EnemyMove();
void EnemyHpDownEffect();
void EnemyRespawn();
#pragma endregion

#pragma region Bullet
void SettingBulletShape();
void CreateEnemyBullet(Enemy* enemy);
void CreatePlayerBullet(double speed, int damage, int weaponNumber);
#pragma endregion

#pragma region Physics
void PlayerGravity();
void EnemyGravity();
#pragma endregion

#pragma region GameFunction
void ShowMap();
void ShowGunUI();
void Weaphone_MapInitialize();
void CreateItem(int x, int y, int ItemNumber);
void UseItem();
void CreateTrap(int x, int y, int width, int damage, int delay, const char* shape);
void ShowTrap();
void ShowKeyInfo();
void ShowNumber(int x, int y, int number, int color);
#pragma endregion

const char* NumberShow(int number);

//↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
//↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
int main()
{

	InitBuffer();

	SettingPlayer(5,27);
	CreateTrap(1, 21, 2, 1,10, "M");
	CreateEnemy(10, 20, 1);
	CreateEnemy(12, 20, 1);
	CreateEnemy(14, 7, 2);
	CreateEnemy(60, 7, 2);
	CreateEnemy(60, 7, 2);
	Weaphone_MapInitialize();
	CreateItem(4,21,HEAL);
	
	CreateItem(7, 27, ADD_02);
	CreateItem(9, 27, ADD_02);
	CreateItem(11, 27, ADD_02);
	while (true)
	{
		
		//움직임
		PlayerMove();
		EnemyMove();

		UseItem();

		//출력
		ShowGunUI();
		ShowMap();
		ShowEnemy();
		ShowPlayer();
		ShowTrap();
		PlayerHpDownEffect();
		EnemyHpDownEffect();
		EnemyRespawn();
		//공격
		AttackPlayer();
		AttackEnemy();

		ShowKeyInfo();
		FlipBuffer();
		ClearBuffer();
		Sleep(20);
	}
	return 0;
}
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

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
	int showGunX = 0;
	int showGunY = 0;

	for (int i = 0; i < player->hp; i++)
	{
		if (player->color == WHITE)
		{
			WriteBuffer(1 + i, 1, "♥", RED);
		}
		else
		{
			WriteBuffer(1 + i, 1, "♥", WHITE);
		}
		
	}

	for (int i = 0; i < PlyaerSizeY; i++)
	{
		WriteBuffer(player->x, player->y - i, player->shape[player->direction][PlyaerSizeY - i], player->color);
	}
	switch (player->direction)
	{
	case 0:
		showGunX = 2;
		showGunY = -2;
		break;
	case 1:
		showGunX = 2;
		showGunY = -3;
		break;
	case 2:
		showGunX = 1;
		showGunY = -4;
		break;
	case 3:
		showGunY = -3;
		break;
	case 4:
		if (player->weaponNum == 2)
		{
			showGunX = -1;
		}
		showGunY = -2;
		break;
	case 5:
		showGunY = -1;
		break;
	case 6:
		showGunX = 1;
		break;
	case 7:
		showGunX = 2;
		showGunY = -1;
		break;
	default:
		break;
	}
	WriteBuffer(player->x + showGunX, player->y + showGunY, Weaphone[player->direction][player->weaponNum-1], CYAN);

}
void SettingPlayer(int x, int y)
{
	SettingBulletShape();
	Weaphone[0][0] = "┌─";
	Weaphone[1][0] = "/";
	Weaphone[2][0] = "|";
	Weaphone[3][0] = "\\";
	Weaphone[4][0] = "┐";
	Weaphone[5][0] = "/";
	Weaphone[6][0] = "|";
	Weaphone[7][0] = "\\";

	Weaphone[0][1] = "┌┬─";
	Weaphone[1][1] = "/";
	Weaphone[2][1] = "┃";
	Weaphone[3][1] = "\\";
	Weaphone[4][1] = "─┬┐";
	Weaphone[5][1] = "/";
	Weaphone[6][1] = "┃";
	Weaphone[7][1] = "\\";

	player = (Player*)malloc(sizeof(Player));
	player->x = x;
	player->y = y;
	player->hp = 10;
	player->color = WHITE;

	player->shape[0][0] = " ";
	player->shape[0][1] = "  O";
	player->shape[0][2] = " (|o";
	player->shape[0][3] = "  ^";
	player->shape[0][4] = " - -";

	player->shape[1][0] = " ";
	player->shape[1][1] = "  Oo";
	player->shape[1][2] = " (|┘";
	player->shape[1][3] = "  ^ ";
	player->shape[1][4] = " - -";

	player->shape[2][0] = " ";
	player->shape[2][1] = " oOo";
	player->shape[2][2] = " (|)";
	player->shape[2][3] = "  ^ ";
	player->shape[2][4] = " - -";

	player->shape[3][0] = " ";
	player->shape[3][1] = " oO";
	player->shape[3][2] = "  |)";
	player->shape[3][3] = "  ^";
	player->shape[3][4] = " - -";

	player->shape[4][0] = " ";
	player->shape[4][1] = "  O ";
	player->shape[4][2] = " o|)";
	player->shape[4][3] = "  ^ ";
	player->shape[4][4] = " - -";

	player->shape[5][0] = " ";
	player->shape[5][1] = "  O";
	player->shape[5][2] = " o|)";
	player->shape[5][3] = "  ^ ";
	player->shape[5][4] = " - - ";

	player->shape[6][0] = " ";
	player->shape[6][1] = "  O ";
	player->shape[6][2] = " o|o";
	player->shape[6][3] = "  ^ ";
	player->shape[6][4] = " - -";

	player->shape[7][0] = " ";
	player->shape[7][1] = "  O";
	player->shape[7][2] = " (|o";
	player->shape[7][3] = "  ^ ";
	player->shape[7][4] = " - -";


	player->die = "어<";
	player->weaponNum = 1;
	player->bulletNum[0] = 100;
	player->bulletNum[1] = 100;
	player->bulletNum[2] = 100;
	player->isJump = false;
	player->isfloat = false;
	player->direction = 1;
	player->bulletDelay[0][0] = 10;
	player->bulletDelay[0][1] = 5;
	player->bulletDelay[0][2] = 20;
	player->bulletDelay[1][0] = 0;
	player->bulletDelay[1][1] = 0;
	player->bulletDelay[1][2] = 0;
	player->downHpDelay[0] = 5;
	player->downHpDelay[1] = 0;
	player->h = player->y;
	player->isDownHp = false;
}
void PlayerMove()
{
	player->bulletDelay[1][0]++;
	player->bulletDelay[1][1]++;
	//player->bulletDelay[1][2]++;
	if (GetAsyncKeyState(0x31))
	{
		player->weaponNum = 1;
	}
	if (GetAsyncKeyState(0x32) && player->bulletNum[0] > 0)
	{
		player->weaponNum = 2;
	}
	if (GetAsyncKeyState(0x41))
	{
		switch (player->weaponNum)
		{
		case 1:
			if (player->bulletDelay[0][0] <= player->bulletDelay[1][0])
			{
				CreatePlayerBullet(Weaphone1_Speed, 1,0);
				player->bulletDelay[1][0] = 0;
			}

			break;
		case 2:
			if (player->bulletDelay[0][1] <= player->bulletDelay[1][1])
			{
				CreatePlayerBullet(Weaphone1_Speed, 3, 1);
				player->bulletDelay[2][0] = 0;
				player->bulletNum[0]--;
			}
			if (player->bulletNum[0] == 0) { player->weaponNum = 1; }
			break;
		default:
			break;
		}

	}

	if (GetAsyncKeyState(VK_LEFT) && Map[player->y][player->x - 1] < 4)
	{
		player->x--;
		player->direction = 4;
	}
	if (GetAsyncKeyState(VK_RIGHT) && Map[player->y][player->x + 1] < 4 && Map[player->y][player->x + 2] < 4)
	{
		player->x++;
		player->direction = 0;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		player->direction = 2;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
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
	if (GetAsyncKeyState(VK_SPACE) && !player->isJump)
	{
		player->isJump = true; time = 0.f; player->h = player->y;
	}
	PlayerGravity();
}
void BasicGunAttack()
{

	for (int i = 0; i < playerBulletCount; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (playerBullet[i] != nullptr)
			{
				WriteBuffer(playerBullet[i]->bullet[j]->x, playerBullet[i]->bullet[j]->y, playerBullet[i]->bullet[j]->shape[playerBullet[i]->bullet[j]->direction], YELLOW);
				switch (playerBullet[i]->bullet[j]->direction)
				{
				case 0:
					playerBullet[i]->bullet[j]->x += playerBullet[i]->bullet[j]->speed;
					break;
				case 1:
					playerBullet[i]->bullet[j]->x += playerBullet[i]->bullet[j]->speed;
					playerBullet[i]->bullet[j]->y -= playerBullet[i]->bullet[j]->speed;
					break;
				case 2:
					playerBullet[i]->bullet[j]->y -= playerBullet[i]->bullet[j]->speed;
					break;
				case 3:
					playerBullet[i]->bullet[j]->x -= playerBullet[i]->bullet[j]->speed;
					playerBullet[i]->bullet[j]->y -= playerBullet[i]->bullet[j]->speed;
					break;
				case 4:
					playerBullet[i]->bullet[j]->x -= playerBullet[i]->bullet[j]->speed;
					break;
				case 5:
					playerBullet[i]->bullet[j]->x -= playerBullet[i]->bullet[j]->speed;
					playerBullet[i]->bullet[j]->y += playerBullet[i]->bullet[j]->speed;
					break;
				case 6:
					playerBullet[i]->bullet[j]->y += playerBullet[i]->bullet[j]->speed;
					break;
				case 7:
					playerBullet[i]->bullet[j]->x += playerBullet[i]->bullet[j]->speed;
					playerBullet[i]->bullet[j]->y += playerBullet[i]->bullet[j]->speed;
					break;
				default:
					playerBullet[i]->bullet[j]->x += playerBullet[i]->bullet[j]->speed;
					break;
				}
				if (playerBullet[i]->bullet[j]->x < 0 || playerBullet[i]->bullet[j]->x>MapX || playerBullet[i]->bullet[j]->y < 0 || playerBullet[i]->bullet[j]->y>MapY)
				{
					for (int k = 0; k < 4; k++)
					{
						free(playerBullet[i]->bullet[k]);
						playerBullet[i]->bullet[j] = nullptr;
					}
					free(playerBullet[i]);
					playerBullet[i] = nullptr;
				}
				else if (Map[(int)playerBullet[i]->bullet[j]->y][(int)playerBullet[i]->bullet[j]->x] > 4)
				{
					switch (playerBullet[i]->bullet[j]->direction)
					{
					case 0:
						WriteBuffer(playerBullet[i]->bullet[j]->x - 1, playerBullet[i]->bullet[j]->y, playerBullet[i]->bullet[j]->destroy[0], RED);
						break;
					case 1:
						WriteBuffer(playerBullet[i]->bullet[j]->x - 1, playerBullet[i]->bullet[j]->y + 1, playerBullet[i]->bullet[j]->destroy[1], RED);
						break;
					case 2:
						WriteBuffer(playerBullet[i]->bullet[j]->x, playerBullet[i]->bullet[j]->y + 1, playerBullet[i]->bullet[j]->destroy[2], RED);
						break;
					case 3:
						WriteBuffer(playerBullet[i]->bullet[j]->x + 1, playerBullet[i]->bullet[j]->y + 1, playerBullet[i]->bullet[j]->destroy[3], RED);
						break;
					case 4:
						WriteBuffer(playerBullet[i]->bullet[j]->x + 1, playerBullet[i]->bullet[j]->y, playerBullet[i]->bullet[j]->destroy[4], RED);
						break;
					case 5:
						WriteBuffer(playerBullet[i]->bullet[j]->x + 1, playerBullet[i]->bullet[j]->y - 1, playerBullet[i]->bullet[j]->destroy[5], RED);
						break;
					case 6:
						WriteBuffer(playerBullet[i]->bullet[j]->x, playerBullet[i]->bullet[j]->y - 1, playerBullet[i]->bullet[j]->destroy[6], RED);
						break;
					case 7:
						WriteBuffer(playerBullet[i]->bullet[j]->x - 1, playerBullet[i]->bullet[j]->y - 1, playerBullet[i]->bullet[j]->destroy[7], RED);
						break;
					}
					for (int k = 0; k < 4; k++)
					{
						free(playerBullet[i]->bullet[k]);
						playerBullet[i]->bullet[j] = nullptr;
					}
					free(playerBullet[i]);
					playerBullet[i] = nullptr;
					continue;
				}
				for (int s = 0; s < 4; s++)
				{
					for (int k = 0; k < EnemyCount; k++)
					{
						if (enemy[k] != nullptr && playerBullet[i] != nullptr)
						{
							if (playerBullet[i]->bullet[j]->x == enemy[k]->x && playerBullet[i]->bullet[j]->y == enemy[k]->y - s &&enemy[k]->hp>0)
							{
								enemy[k]->isDownHp = true;
								enemy[k]->hp--;
								for (int k = 0; k < 4; k++)
								{
									free(playerBullet[i]->bullet[k]);
									playerBullet[i]->bullet[j] = nullptr;
								}
								free(playerBullet[i]);
								playerBullet[i] = nullptr;
							}
						}
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
		if (playerBullet2[i] != 0)
		{
			WriteBuffer(playerBullet2[i]->x, playerBullet2[i]->y, playerBullet2[i]->shape[0], WHITE);
			switch (playerBullet2[i]->direction)
			{
			case 0:
				playerBullet2[i]->x += 1 / playerBullet2[i]->speed;
				break;
			case 1:
				playerBullet2[i]->x += 1 / playerBullet2[i]->speed;
				playerBullet2[i]->y -= 1 / playerBullet2[i]->speed;
				break;
			case 2:
				playerBullet2[i]->y -= 1 / playerBullet2[i]->speed;
				break;
			case 3:
				playerBullet2[i]->x -= 1 / playerBullet2[i]->speed;
				playerBullet2[i]->y -= 1 / playerBullet2[i]->speed;
				break;
			case 4:
				playerBullet2[i]->x -= 1 / playerBullet2[i]->speed;
				break;
			case 5:
				playerBullet2[i]->x -= 1 / playerBullet2[i]->speed;
				playerBullet2[i]->y += 1 / playerBullet2[i]->speed;
				break;
			case 6:
				playerBullet2[i]->y += playerBullet2[i]->speed;
				break;
			case 7:
				playerBullet2[i]->x += playerBullet2[i]->speed;
				playerBullet2[i]->y += playerBullet2[i]->speed;
				break;
			default:
				playerBullet2[i]->x += playerBullet2[i]->speed;
				break;
			}
			if (playerBullet2[i]->x < 0 || playerBullet2[i]->x>MapX || playerBullet2[i]->y < 0 || playerBullet2[i]->y>MapY)
			{
				free(playerBullet2[i]);
				playerBullet2[i] = 0;
			}
			else if (Map[(int)playerBullet2[i]->y][(int)playerBullet2[i]->x] > 4)
			{
				switch (playerBullet2[i]->direction)
				{
				case 0:
					WriteBuffer(playerBullet2[i]->x - 1, playerBullet2[i]->y, playerBullet2[i]->destroy[0], YELLOW);
					break;
				case 1:
					WriteBuffer(playerBullet2[i]->x - 1, playerBullet2[i]->y + 1, playerBullet2[i]->destroy[1], YELLOW);
					break;
				case 2:
					WriteBuffer(playerBullet2[i]->x, playerBullet2[i]->y + 1, playerBullet2[i]->destroy[2], YELLOW);
					break;
				case 3:
					WriteBuffer(playerBullet2[i]->x + 1, playerBullet2[i]->y + 1, playerBullet2[i]->destroy[3], YELLOW);
					break;
				case 4:
					WriteBuffer(playerBullet2[i]->x + 1, playerBullet2[i]->y, playerBullet2[i]->destroy[4], YELLOW);
					break;
				case 5:
					WriteBuffer(playerBullet2[i]->x + 1, playerBullet2[i]->y - 1, playerBullet2[i]->destroy[5], YELLOW);
					break;
				case 6:
					WriteBuffer(playerBullet2[i]->x, playerBullet2[i]->y - 1, playerBullet2[i]->destroy[6], YELLOW);
					break;
				case 7:
					WriteBuffer(playerBullet2[i]->x - 1, playerBullet2[i]->y - 1, playerBullet2[i]->destroy[7], YELLOW);
					break;
				}
				free(playerBullet2[i]);
				playerBullet2[i] = 0;
				continue;
			}
			for (int j = 0; j < EnemyCount; j++)
			{
				if (enemy[j] != 0 && playerBullet2[i] != 0)
				{
					if (playerBullet2[i]->x == enemy[j]->x && playerBullet2[i]->y == enemy[j]->y)
					{
						enemy[j]->color = WHITE;
						free(playerBullet2[i]);
						playerBullet2[i] = 0;
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
	//	StringGunAttack();

}
void PlayerHpDownEffect()
{
	if (player->isDownHp)
	{
		player->color = RED;
		player->downHpDelay[1]++;
		if (player->downHpDelay[1] > player->downHpDelay[0])
		{
			player->isDownHp = false;
			player->downHpDelay[1] = 0;
			player->color = WHITE;
		}
	}
}
#pragma endregion


#pragma region Enemy
void ShowEnemy()
{
	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemy[i] != nullptr && enemy[i]->hp > 0)
		{
			if (enemy[i]->isLeft)
			{
				for (int j = 0; j < 4; j++)
				{
					WriteBuffer(enemy[i]->x, enemy[i]->y - j, enemy[i]->shape[0][3 - j], enemy[i]->color);
				}

			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					WriteBuffer(enemy[i]->x, enemy[i]->y - j, enemy[i]->shape[1][3 - j], enemy[i]->color);
				}
			}

		}
		if (enemy[i] != nullptr && enemy[i]->hp <= 0)
		{

			for (int j = 0; j < 4; j++)
			{
				switch (player->direction)
				{
				case 0:
				case 1:
				case 2:
				case 7:
					WriteBuffer(enemy[i]->x, enemy[i]->y - j + 1, enemy[i]->die[0][j], enemy[i]->color);
					break;
				case 3:
				case 4:
				case 5:
				case 6:
				default:
					WriteBuffer(enemy[i]->x, enemy[i]->y - j + 1, enemy[i]->die[1][j], enemy[i]->color);
					break;
				}
			}
			
			enemy[i]->responTime--;
			if (enemy[i]->responTime <= 0)
			{
				free(enemy[i]);
				enemy[i] = nullptr;
			}
		}
	}
}
void CreateEnemy(int x, int y, int lv) // [적생성] 입력값: x좌표, y좌표, 적레벨(1~3)
{
	if (lv == 1)
	{   //         좌표x,y,HP,lv,shape,die
		SettingEnemy(x, y, 1);
	}
	if (lv == 2)
	{
		SettingEnemy(x, y, 2 );
	}
	if (lv == 3)
	{
		SettingEnemy(x, y, 3);
	}
}
void SettingEnemy(int x, int y, int lv) //CreateEnemy용
{
	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemy[i] == nullptr)
		{
			enemy[i] = (Enemy*)malloc(sizeof(Enemy));
			enemy[i]->x = x;
			enemy[i]->y = y;
			
			enemy[i]->Lv = lv;
			enemy[i]->rerodingTime[1] = 0;
			enemy[i]->responTime = 30;
			if (lv == 1)
			{
				enemy[i]->shape[0][0] = "↑@ ";
				enemy[i]->shape[0][1] = " o|)";
				enemy[i]->shape[0][2] = "  ^ ";
				enemy[i]->shape[0][3] = " - -";

				enemy[i]->shape[1][0] = " @↑";
				enemy[i]->shape[1][1] = "(|o";
				enemy[i]->shape[1][2] = " ^ ";
				enemy[i]->shape[1][3] = "- -";

				enemy[i]->die[0][0] = "";
				enemy[i]->die[0][1] = "-   o →";
				enemy[i]->die[0][2] = "  > ㅡ @";
				enemy[i]->die[0][3] = "-";

				enemy[i]->die[1][0] = "";
				enemy[i]->die[1][1] = "← o    -";
				enemy[i]->die[1][2] = "@ ㅡ < ";
				enemy[i]->die[1][3] = "       -";

				enemy[i]->hp = 10;
				enemy[i]->rerodingTime[0] = 50;
				enemy[i]->color = LIGHTMAGENTA;
			}
			if (lv == 2)
			{
				enemy[i]->shape[0][0] = "*@ ";
				enemy[i]->shape[0][1] = "│o|)";
				enemy[i]->shape[0][2] = "  ^ ";
				enemy[i]->shape[0][3] = " - -";

				enemy[i]->shape[1][0] = " @ *";
				enemy[i]->shape[1][1] = "(|o│";
				enemy[i]->shape[1][2] = " ^ ";
				enemy[i]->shape[1][3] = "- -";

				enemy[i]->die[0][0] = "";
				enemy[i]->die[0][1] = "-   o ㅡ*";
				enemy[i]->die[0][2] = "  > ㅡ @";
				enemy[i]->die[0][3] = "-";

				enemy[i]->die[1][0] = "";
				enemy[i]->die[1][1] = "*ㅡ o  -";
				enemy[i]->die[1][2] = "@ ㅡ < ";
				enemy[i]->die[1][3] = "       -";

				enemy[i]->rerodingTime[0] = 35;
				enemy[i]->color = RED;
				enemy[i]->hp = 30;
			}
			if (lv == 3)
			{
				enemy[i]->shape[0][0] = "*@ ";
				enemy[i]->shape[0][1] = "│o|)";
				enemy[i]->shape[0][2] = "  ^ ";
				enemy[i]->shape[0][3] = " - -";

				enemy[i]->shape[1][0] = " @ *";
				enemy[i]->shape[1][1] = "(|o│";
				enemy[i]->shape[1][2] = " ^ ";
				enemy[i]->shape[1][3] = "- -";

				enemy[i]->die[0][0] = "";
				enemy[i]->die[0][1] = "-   o ㅡ*";
				enemy[i]->die[0][2] = "  > ㅡ @";
				enemy[i]->die[0][3] = "-";

				enemy[i]->die[1][0] = "";
				enemy[i]->die[1][1] = "*ㅡ o  -";
				enemy[i]->die[1][2] = "@ ㅡ < ";
				enemy[i]->die[1][3] = "       -";

				enemy[i]->rerodingTime[0] = 20;
				enemy[i]->color = RED;
				enemy[i]->hp = 30;
			}
			enemy[i]->isLeft = false;
			enemy[i]->isDownHp = false;
			enemy[i]->downHpDelay[0] = 3;
			enemy[i]->downHpDelay[1] = 0;
			
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
			if (enemy[i] != nullptr && enemy[i]->hp > 0)
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
				for (int j = 0; j < 3; j++)
				{

				}
				if (enemyBullet[i]->x < 0 || enemyBullet[i]->x>100 || enemyBullet[i]->y < 0 || enemyBullet[i]->y>30)
				{
					free(enemyBullet[i]);
					enemyBullet[i] = nullptr;
				}
				else if (Map[(int)enemyBullet[i]->y][(int)enemyBullet[i]->x] > 4 || (enemyBullet[i]->x == player->x && enemyBullet[i]->y == player->y) || (enemyBullet[i]->x == player->x && enemyBullet[i]->y == player->y - 1) || (enemyBullet[i]->x == player->x && enemyBullet[i]->y == player->y - 2) || (enemyBullet[i]->x == player->x && enemyBullet[i]->y == player->y - 3))
				{
					if ((enemyBullet[i]->x == player->x && enemyBullet[i]->y ==player->y)|| (enemyBullet[i]->x == player->x && enemyBullet[i]->y == player->y-1)||(enemyBullet[i]->x == player->x && enemyBullet[i]->y == player->y-2)|| (enemyBullet[i]->x == player->x && enemyBullet[i]->y == player->y-3))
					{
						player->isDownHp = true;
						player->hp--;
						WriteBuffer(player->x + 1, player->y - 6, "아야!", WHITE);
					}
					switch (enemyBullet[i]->direction)
					{
					case 0:
						WriteBuffer(enemyBullet[i]->x - 1, enemyBullet[i]->y, enemyBullet[i]->destroy[0], WHITE);
						break;
					case 1:
						WriteBuffer(enemyBullet[i]->x - 1, enemyBullet[i]->y + 1, enemyBullet[i]->destroy[1], WHITE);
						break;
					case 2:
						WriteBuffer(enemyBullet[i]->x, enemyBullet[i]->y + 1, enemyBullet[i]->destroy[2], WHITE);
						break;
					case 3:
						WriteBuffer(enemyBullet[i]->x + 1, enemyBullet[i]->y + 1, enemyBullet[i]->destroy[3], WHITE);
						break;
					case 4:
						WriteBuffer(enemyBullet[i]->x + 1, enemyBullet[i]->y, enemyBullet[i]->destroy[4], WHITE);
						break;
					case 5:
						WriteBuffer(enemyBullet[i]->x + 1, enemyBullet[i]->y - 1, enemyBullet[i]->destroy[5], WHITE);
						break;
					case 6:
						WriteBuffer(enemyBullet[i]->x, enemyBullet[i]->y - 1, enemyBullet[i]->destroy[6], WHITE);
						break;
					case 7:
						WriteBuffer(enemyBullet[i]->x - 1, enemyBullet[i]->y - 1, enemyBullet[i]->destroy[7], WHITE);
						break;
					}
					free(enemyBullet[i]);
					enemyBullet[i] = nullptr;
				}
				else
				{
					WriteBuffer(enemyBullet[i]->x, enemyBullet[i]->y, enemyBullet[i]->shape[0], WHITE);
					switch (enemyBullet[i]->direction)
					{
					case 0:
						enemyBullet[i]->x++;
						break;
					case 1:
						enemyBullet[i]->Xcount[1]++;
						enemyBullet[i]->Ycount[1]++;
						if (enemyBullet[i]->Xcount[0] <= enemyBullet[i]->Xcount[1])
						{
							enemyBullet[i]->Xcount[1] = 0;
							enemyBullet[i]->x++;
						}
						if (enemyBullet[i]->Ycount[0] <= enemyBullet[i]->Ycount[1])
						{
							enemyBullet[i]->Ycount[1] = 0;
							enemyBullet[i]->y--;
						}
						break;
					case 2:
						enemyBullet[i]->y--;
						break;
					case 3:
						enemyBullet[i]->Xcount[1]++;
						enemyBullet[i]->Ycount[1]++;
						if (enemyBullet[i]->Xcount[0] <= enemyBullet[i]->Xcount[1])
						{
							enemyBullet[i]->Xcount[1] = 0;
							enemyBullet[i]->x--;
						}
						if (enemyBullet[i]->Ycount[0] <= enemyBullet[i]->Ycount[1])
						{
							enemyBullet[i]->Ycount[1] = 0;
							enemyBullet[i]->y--;
						}
						break;
					case 4:
						enemyBullet[i]->x--;
						break;
					case 5:
						enemyBullet[i]->Xcount[1]++;
						enemyBullet[i]->Ycount[1]++;
						if (enemyBullet[i]->Xcount[0] <= enemyBullet[i]->Xcount[1])
						{
							enemyBullet[i]->Xcount[1] = 0;
							enemyBullet[i]->x--;
						}
						if (enemyBullet[i]->Ycount[0] <= enemyBullet[i]->Ycount[1])
						{
							enemyBullet[i]->Ycount[1] = 0;
							enemyBullet[i]->y++;
						}
						break;
					case 6:
						enemyBullet[i]->y++;
						break;
					case 7:
						enemyBullet[i]->Xcount[1]++;
						enemyBullet[i]->Ycount[1]++;
						if (enemyBullet[i]->Xcount[0] <= enemyBullet[i]->Xcount[1])
						{
							enemyBullet[i]->Xcount[1] = 0;
							enemyBullet[i]->x++;
						}
						if (enemyBullet[i]->Ycount[0] <= enemyBullet[i]->Ycount[1])
						{
							enemyBullet[i]->Ycount[1] = 0;
							enemyBullet[i]->y++;
						}
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
		if (enemy[i] != nullptr && enemy[i]->hp > 0)
		{
			if (rand() % 1000 < 1 && Map[enemy[i]->y][enemy[i]->x + 1] < 5)
			{
				enemy[i]->moveDir[0] = rand() % 4;
			}
			else if (rand() % 100 < 2 && rand() % 100 >= 1)
			{
				enemy[i]->moveDir[0] = -(rand() % 4);
			}
			else if (rand() % 100 < 3 && rand() % 100 >= 2)
			{
				if (enemy[i]->x < player->x)
				{
					enemy[i]->moveDir[0] = rand() % 4;
				}
				else if (Map[enemy[i]->y][enemy[i]->x - 1] < 5)
				{
					enemy[i]->moveDir[0] = -(rand() % 4);
				}
			}
			if (enemy[i]->moveDir[0] != enemy[i]->moveDir[1])
			{
				if (enemy[i]->moveDir[0] > enemy[i]->moveDir[1] && Map[enemy[i]->y][enemy[i]->x + 1] < 5)
				{
					enemy[i]->moveDir[1]++;
					enemy[i]->x++;
					enemy[i]->isLeft = false;
				}
				if (enemy[i]->moveDir[0] < enemy[i]->moveDir[1] && Map[enemy[i]->y][enemy[i]->x - 1] < 5)
				{
					enemy[i]->moveDir[1]--;
					enemy[i]->x--;
					enemy[i]->isLeft = true;
				}
			}
			else
			{
				enemy[i]->moveDir[0] = 0;
				enemy[i]->moveDir[1] = 0;
			}
			for (int j = 0; j < EnemyCount; j++)
			{
				if (enemy[j] != nullptr && j != i && enemy[i]->x == enemy[j]->x && (enemy[i]->y == enemy[j]->y || enemy[i]->x+1 == enemy[j]->x-1 && enemy[i]->y == enemy[j]->y))
				{
					enemy[j]->x++;
					enemy[i]->x--;
				}
			}
			for (int j = 0; j <7; j++)
			{
				if (Map[enemy[i]->y-j][enemy[i]->x] > 4)
				{
					WriteBuffer(enemy[i]->x, enemy[i]->y-7, "올라갈수있음", WHITE);
				}
			}
		}
	}
	EnemyGravity();
}
void EnemyHpDownEffect()
{
	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemy[i] != nullptr)
		{
			if (enemy[i]->isDownHp)
			{
				switch (enemy[i]->Lv)
				{
				case 1:
					enemy[i]->color = WHITE;
					enemy[i]->downHpDelay[1]++;
					if (enemy[i]->downHpDelay[1] > enemy[i]->downHpDelay[0])
					{
						enemy[i]->isDownHp = false;
						enemy[i]->downHpDelay[1] = 0;
						enemy[i]->color = LIGHTMAGENTA;
					}
					break;
				case 2:
					enemy[i]->color = WHITE;
					enemy[i]->downHpDelay[1]++;
					if (enemy[i]->downHpDelay[1] > enemy[i]->downHpDelay[0])
					{
						enemy[i]->isDownHp = false;
						enemy[i]->downHpDelay[1] = 0;
						enemy[i]->color = RED;
					}
					break;
				default:
					break;
				}
				
			}
		}
	}
}
void EnemyRespawn()
{
	int i = 0;
	int j = 0;
	if (Map[player->y][player->x] == 3)
	{
		while (Map[player->y + j][player->x] == 3)
		{
			Map[player->y+j][player->x] = 2;
			j++;
		}
		while (Map[player->y -1- i][player->x] == 3)
		{
			Map[player->y-1-i][player->x] = 2;
			i++;
		}
		
		CreateEnemy(rand() % 55+5, rand() % 28, 1);
	}
}
#pragma endregion


#pragma region Bullet
void SettingBulletShape()
{
	bulletShape[0][0] = "--";
	bulletShape[0][1] = "/";
	bulletShape[0][2] = "|";
	bulletShape[0][3] = "\\";
	bulletShape[0][4] = "--";
	bulletShape[0][5] = "/";
	bulletShape[0][6] = "|";
	bulletShape[0][7] = "\\";

	bulletShape[1][0] = ">";
	bulletShape[1][1] = "ㄱ";
	bulletShape[1][2] = "^";
	bulletShape[1][3] = "┌";
	bulletShape[1][4] = "<";
	bulletShape[1][5] = "ㄴ";
	bulletShape[1][6] = "\\/";
	bulletShape[1][7] = "┘";
}
void CreateEnemyBullet(Enemy* enemy)
{
	for (int i = 0; i < enemyBulletCount; i++)
	{
		if (enemyBullet[i] == nullptr)
		{
			enemyBullet[i] = (Bullet*)malloc(sizeof(Bullet));
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
				enemyBullet[i]->Xcount[0] = 2;
				enemyBullet[i]->Xcount[1] = 0;
				enemyBullet[i]->Ycount[0] = 2;
				enemyBullet[i]->Ycount[1] = 0;
			}
			else if (enemy->Lv == 2)
			{
				enemyBullet[i]->shape[0] = "⇔";
				enemyBullet[i]->damage = 2;
				enemyBullet[i]->destroy[0] = " :";
				enemyBullet[i]->destroy[1] = "'.";
				enemyBullet[i]->destroy[2] = "''";
				enemyBullet[i]->destroy[3] = ".'";
				enemyBullet[i]->destroy[4] = ": ";
				enemyBullet[i]->destroy[5] = "'.";
				enemyBullet[i]->destroy[6] = "..";
				enemyBullet[i]->destroy[7] = ".'";
				enemyBullet[i]->Xcount[0] = 2;
				enemyBullet[i]->Xcount[1] = 0;
				enemyBullet[i]->Ycount[0] = 2;
				enemyBullet[i]->Ycount[1] = 0;
			}
			else if (enemy->Lv == 3)
			{
				enemyBullet[i]->shape[0] = "+";
				enemyBullet[i]->damage = 3;
			}

			int x = player->x - enemy->x;
			int y = player->y - enemy->y;
			if (y == 0 && x > 0)
			{
				enemyBullet[i]->direction = 0;
				enemyBullet[i]->x = enemy->x + 1 - 3 + EnmeyWidth;
				enemyBullet[i]->y = enemy->y + EnemyHight;
			}
			else if (x > 0 && y < 0)
			{
				enemyBullet[i]->direction = 1;
				enemyBullet[i]->x = enemy->x + 1 + EnmeyWidth;
				enemyBullet[i]->y = enemy->y - 1 + EnemyHight;
			}
			else if (x == 0 && y < 0)
			{
				enemyBullet[i]->direction = 2;
				enemyBullet[i]->x = enemy->x + EnmeyWidth;
				enemyBullet[i]->y = enemy->y - 1 + EnemyHight;
			}
			else if (x < 0 && y < 0)
			{
				enemyBullet[i]->direction = 3;
				enemyBullet[i]->x = enemy->x - 1 + EnmeyWidth;
				enemyBullet[i]->y = enemy->y - 1 + EnemyHight;
			}
			else if (y == 0 && x < 0)
			{
				enemyBullet[i]->direction = 4;
				enemyBullet[i]->x = enemy->x - 1 + EnmeyWidth;
				enemyBullet[i]->y = enemy->y + EnemyHight;
			}
			else if (x < 0 && y>0)
			{
				enemyBullet[i]->direction = 5;
				enemyBullet[i]->x = enemy->x - 1 + EnmeyWidth;
				enemyBullet[i]->y = enemy->y + 1 + EnemyHight;
			}
			else if (x == 0 && y > 0)
			{
				enemyBullet[i]->direction = 6;
				enemyBullet[i]->x = enemy->x + EnmeyWidth;
				enemyBullet[i]->y = enemy->y + 1 + EnemyHight;
			}
			else if (x > 0 && y > 0)
			{
				enemyBullet[i]->direction = 7;
				enemyBullet[i]->x = enemy->x + 1 + EnmeyWidth;
				enemyBullet[i]->y = enemy->y + 1 + EnemyHight;
			}
			else
			{
				enemyBullet[i]->direction = 0;
				enemyBullet[i]->x = enemy->x + 1 + EnmeyWidth;
				enemyBullet[i]->y = enemy->y + EnemyHight;
			}
			break;
		}
	}
}
void CreatePlayerBullet(double speed, int damage,int weaponNumber)
{
	for (int i = 0; i < playerBulletCount; i++)
	{
		if (playerBullet[i] == nullptr)
		{
			playerBullet[i] = (Gun*)malloc(sizeof(Gun));
			for (int j = 0; j < 4; j++)
			{
				playerBullet[i]->bullet[j] = (Bullet*)malloc(sizeof(Bullet));
				switch (player->direction)
				{
				case 0:
					playerBullet[i]->bullet[j]->x = player->x + 1 + PlayerGunX + j;
					playerBullet[i]->bullet[j]->y = player->y + PlayerGunY;
					break;
				case 1:
					playerBullet[i]->bullet[j]->x = player->x + 1 + PlayerGunX + j;
					playerBullet[i]->bullet[j]->y = player->y - 1 + PlayerGunY - j;
					break;
				case 2:
					playerBullet[i]->bullet[j]->x = player->x + PlayerGunX;
					playerBullet[i]->bullet[j]->y = player->y - 1 + PlayerGunY - j;
					break;
				case 3:
					playerBullet[i]->bullet[j]->x = player->x - 1 + PlayerGunX - j;
					playerBullet[i]->bullet[j]->y = player->y - 1 + PlayerGunY - j;
					break;
				case 4:
					playerBullet[i]->bullet[j]->x = player->x - 1 + PlayerGunX - j;
					playerBullet[i]->bullet[j]->y = player->y + PlayerGunY;
					break;
				case 5:
					playerBullet[i]->bullet[j]->x = player->x - 1 + PlayerGunX - j;
					playerBullet[i]->bullet[j]->y = player->y + 1 + PlayerGunY + j;
					break;
				case 6:
					playerBullet[i]->bullet[j]->x = player->x + PlayerGunX;
					playerBullet[i]->bullet[j]->y = player->y + 1 + PlayerGunY + j;
					break;
				case 7:
					playerBullet[i]->bullet[j]->x = player->x + 1 + PlayerGunX + j;
					playerBullet[i]->bullet[j]->y = player->y + 1 + PlayerGunY + j;
					break;
				default:
					playerBullet[i]->bullet[j]->x = player->x + 1 + PlayerGunX + j;
					playerBullet[i]->bullet[j]->y = player->y + PlayerGunY;
					break;
				}
				
				for (int k = 0; k < 8; k++)
				{
					playerBullet[i]->bullet[j]->shape[k] = bulletShape[weaponNumber][k];
				}
				playerBullet[i]->bullet[j]->damage = damage;
				playerBullet[i]->bullet[j]->destroy[0] = " :";
				playerBullet[i]->bullet[j]->destroy[1] = "'.";
				playerBullet[i]->bullet[j]->destroy[2] = "''";
				playerBullet[i]->bullet[j]->destroy[3] = ".'";
				playerBullet[i]->bullet[j]->destroy[4] = ": ";
				playerBullet[i]->bullet[j]->destroy[5] = "'.";
				playerBullet[i]->bullet[j]->destroy[6] = "..";
				playerBullet[i]->bullet[j]->destroy[7] = ".'";
				playerBullet[i]->bullet[j]->direction = player->direction;
				playerBullet[i]->bullet[j]->speed = speed;
				for (int k = 0; k < EnemyCount; k++)
				{
					if (enemy[k] != nullptr)
					{
						if (playerBullet[i]->bullet[j]->x == enemy[k]->x && playerBullet[i]->bullet[j]->y == enemy[k]->y)
						{
							enemy[k]->isDownHp = true;
							enemy[k]->hp--;
						}
					}
				}

				if (Map[(int)playerBullet[i]->bullet[j]->y][(int)playerBullet[i]->bullet[j]->x] > 4)
				{
					free(playerBullet[i]); playerBullet[i] = nullptr;
					break;
				}

			}
			break;
		}
	}
}
#pragma endregion


#pragma region Physics
void PlayerGravity()
{
	if (player->isJump)
	{
		int pos1 = player->y;
		time += 0.2f;
		player->y = player->h - V * time + 0.5f * G * time * time;
		int pos2 = player->y;

		int gab = pos2 - pos1;
		if (gab > 0)
		{
			for (int i = 0; i < gab; i++)
			{
				if (Map[pos1 + i][player->x] > 4 || Map[pos1 + i][player->x + 1] > 4)
				{
					player->y = pos1 + i - 1;
					player->isJump = false;
					break;
				}
			}
		}
		if (gab < 0)
		{
			for (int i = 0; i < gab * -1; i++)
			{
				if (Map[pos1 - i-3][player->x] > 4 && Map[pos1 - i-3][player->x + 1] > 4)
				{
					player->y = pos1 - i-1;
					player->isJump = false;
					break;
				}
			}
		}
	}
	if (!player->isJump && Map[player->y + 1][player->x] < 4 && Map[player->y + 1][player->x + 1] < 4)
	{
		player->isfloat = true;
		time = 0.f;
		player->h = player->y;

	}
	if (player->isfloat)
	{
		int p1 = player->y;
		time += 0.2f;
		player->y = player->h + V * time + 0.5f * G * time * time;
		int p2 = player->y;
		int gab = p2 - p1;
		for (int i = 0; i < gab; i++)
		{
			if (Map[p1 + i][player->x] > 4 && Map[p1 + i][player->x + 1] > 4)
			{
				player->y = p1 + i - 1;
				player->isfloat = false;
				break;
			}
		}

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
	for (int y = 0; y < MapY; y++)
	{
		for (int x = 0; x < MapX; x++)
		{
			switch (Map[y][x])
			{
			case 2:
				WriteBuffer(x, y, "|", GREEN);
				break;
			case 3:
				WriteBuffer(x, y, "|", YELLOW);
				break;
			case 5:
				WriteBuffer(x, y, "■", LIGHTGRAY);
				break;
			case 6:
				WriteBuffer(x, y, "▩", LIGHTGRAY);
				break;
			default:
				break;
			}
		}
	}
}
void ShowGunUI()
{
	if (player->weaponNum == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			WriteBuffer(1, 30 + i, WeaphoneMap[0][i], CYAN);
		}

		for (int i = 0; i < 3; i++)
		{
			WriteBuffer(7, 30 + i, WeaphoneMap[1][i], WHITE);

		}
		WriteBuffer(2, 33, "[1]", CYAN);
		WriteBuffer(8, 33, "[2]", WHITE);
		WriteBuffer(2, 34, "∞", CYAN);
		ShowNumber(8, 34, player->bulletNum[0], WHITE);
		WriteBuffer(11, 34, "발", WHITE);

	}
	if (player->weaponNum == 2)
	{

		for (int i = 0; i < 3; i++)
		{
			WriteBuffer(1, 30 + i, WeaphoneMap[0][i], WHITE);
		}
		for (int i = 0; i < 3; i++)
		{
			WriteBuffer(7, 30 + i, WeaphoneMap[1][i], CYAN);
		}
		WriteBuffer(2, 33, "[1]", WHITE);
		WriteBuffer(8, 33, "[2]", CYAN);
		WriteBuffer(2, 34, "∞", WHITE);	
		ShowNumber(8, 34, player->bulletNum[0], CYAN);
		WriteBuffer(11, 34, "발", CYAN);
	}
}
void Weaphone_MapInitialize()
{
	WeaphoneMap[0][0] = "┌──────┐ ";
	WeaphoneMap[0][1] = "└────┐ │ ";
	WeaphoneMap[0][2] = "     └─┘";

	WeaphoneMap[1][0] = "┌────────────────┐ ";
	WeaphoneMap[1][1] = "└───────┐  │───┐ │ ";
	WeaphoneMap[1][2] = "        └──┘   └─┘ ";



}
void CreateItem(int x, int y, int ItemNumber)  // 좌표,원하는 아이템번호
{
	for (int i = 0; i < ItemCount; i++)
	{
		if (item[i] == nullptr)
		{
			item[i] = (Item*)malloc(sizeof(Item));

			item[i]->x = x;
			item[i]->y = y;

			switch (ItemNumber)
			{
			case HEAL:
				
				item[i]->color = RED;
				item[i]->shape[0] = " ___";
				item[i]->shape[1] = "│♡│";
				item[i]->shape[2] = "└──┘";
				item[i]->itemEffect = HEAL;
				break;
			case ADD_02:
				item[i]->color = YELLOW;
				item[i]->shape[0] = " ___";
				item[i]->shape[1] = "│↑│";
				item[i]->shape[2] = "└──┘";
				item[i]->itemEffect = ADD_02;
				break;
			default:
				break;
			}
			break;
		}
	}
}
void UseItem()
{
	for (int i = 0; i < ItemCount; i++)
	{
		if (item[i] != nullptr)
		{
			for (int j = 0; j < 3; j++)
			{
				WriteBuffer(item[i]->x, item[i]->y-j, item[i]->shape[2-j], item[i]->color);
			}
			if (item[i]->x == player->x && item[i]->y == player->y)
			{
				switch (item[i]->itemEffect)
				{
				case HEAL:
					WriteBuffer(21, 21, "+ ♥", item[i]->color);
					player->hp++;
					break;
				case ADD_02:
					if (player->bulletNum[0] >= 200)
					{
						WriteBuffer(8, 20, "+ 50",WHITE);
						player->bulletNum[0] = 200;
					}
					else
					{
						WriteBuffer(8, 20, "+ 50", player->bulletNum[0] += 50);
					}
					
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
void CreateTrap(int x, int y, int width, int damage,int delay, const char* shape)
{
	for (int i = 0; i < 10; i++)
	{
		if (trap[i] == nullptr)
		{
			trap[i] = (Trap*)malloc(sizeof(Trap));
			trap[i]->x = x;
			trap[i]->y = y;
			trap[i]->width = width;
			trap[i]->damage = damage;
			trap[i]->attackDelay[0] = delay;
			trap[i]->attackDelay[1] = 0;
			trap[i]->shape = shape;
			break;
		}
	}
}
void ShowTrap()
{
	for (int i = 0; i < 10; i++)
	{
		if (trap[i] != nullptr)
		{
			WriteBuffer(trap[i]->x, trap[i]->y, trap[i]->shape, WHITE);
			if ((trap[i]->x == player->x && trap[i]->y == player->y) || (trap[i]->x == player->x + 1 && trap[i]->y == player->y))
			{
				trap[i]->attackDelay[1]++;
				if (trap[i]->attackDelay[1] >= trap[i]->attackDelay[0])
				{
					trap[i]->attackDelay[1] = 0;
					player->isDownHp = true;
					player->hp--;
				}
			}
		}
	}
}
void ShowKeyInfo()
{

	if (GetAsyncKeyState(VK_F1))
	{
		isKeyInfo = true;
	}
	if (isKeyInfo)
	{
		keyInfoDelay[1]++;
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 50; x++)
			{
				switch (KeyInfoMap[y][x])
				{
				case 0:
					WriteBuffer(x + 8, y + 3, "  ", WHITE);
					break;
				case 1:
					WriteBuffer(x + 8, y + 3, "──", WHITE);
					break;
				case 2:
					WriteBuffer(x + 8, y + 3, " │", WHITE);
					break;
				case 3:
					WriteBuffer(x + 8, y + 3, "┌─", WHITE);
					break;
				case 4:
					WriteBuffer(x + 8, y + 3, "─┐", WHITE);
					break;
				case 5:
					WriteBuffer(x + 8, y + 3, "└─", WHITE);
					break;
				case 6:
					WriteBuffer(x + 8, y + 3, "─┘", WHITE);
					break;
				case 7:
					WriteBuffer(x + 8, y + 3, "│ ", WHITE);
					break;
				default:
					break;
				}
				WriteBuffer(0, 3, "     ↑", LIGHTMAGENTA);
				WriteBuffer(0, 5, "남은 플레이어HP", LIGHTMAGENTA);
				WriteBuffer(0, 34, "     ↑", LIGHTMAGENTA);
				WriteBuffer(0, 36, "현재 착용중인 무기", LIGHTMAGENTA);
				WriteBuffer(12, 5, "- 이동 -", BROWN);
				WriteBuffer(10, 7, "      [↑]         ", BROWN);
				WriteBuffer(10, 9, "  [←][↓][→]    점프[SPACE]   ", BROWN);
				WriteBuffer(30, 5, "- 공격 -", BROWN);
				WriteBuffer(31, 8, "[A]", BROWN);
				WriteBuffer(40, 5, "- 무기 변경 -", BROWN);
				WriteBuffer(41, 8, "[1][2][3]", BROWN);
				WriteBuffer(51, 10, "창 닫기[F2]", BROWN);
			}
		}
		while (isKeyInfo && keyInfoDelay[1] >= keyInfoDelay[0])
		{
			if (GetAsyncKeyState(VK_F2))
			{
				isKeyInfo = false;
				keyInfoDelay[1] = 0;
				break;
			}
		}

	}
	else
	{
		WriteBuffer(30, 1, "도움말[F1]", BROWN);
	}

}
void ShowNumber(int x, int y, int number, int color)
{
	switch (number / 100)
	{
	case 0:
		WriteBuffer(x, y, "0", color);
		break;
	case 1:
		WriteBuffer(x, y, "1", color);
		break;
	case 2:
		WriteBuffer(x, y, "2", color);
		break;
	case 3:
		WriteBuffer(x, y, "3", color);
		break;
	case 4:
		WriteBuffer(x, y, "4", color);
		break;
	case 5:
		WriteBuffer(x, y, "5", color);
		break;
	case 6:
		WriteBuffer(x, y, "6", color);
		break;
	case 7:
		WriteBuffer(x, y, "7", color);
		break;
	case 8:
		WriteBuffer(x, y, "8", color);
		break;
	case 9:
		WriteBuffer(x, y, "9", color);
		break;
	default:
		break;
	}
	switch ((number - (number / 100) * 100) / 10)
	{
	case 0:
		WriteBuffer(x + 1, y, "0", color);
		break;
	case 1:
		WriteBuffer(x + 1, y, "1", color);
		break;
	case 2:
		WriteBuffer(x + 1, y, "2", color);
		break;
	case 3:
		WriteBuffer(x + 1, y, "3", color);
		break;
	case 4:
		WriteBuffer(x + 1, y, "4", color);
		break;
	case 5:
		WriteBuffer(x + 1, y, "5", color);
		break;
	case 6:
		WriteBuffer(x + 1, y, "6", color);
		break;
	case 7:
		WriteBuffer(x + 1, y, "7", color);
		break;
	case 8:
		WriteBuffer(x + 1, y, "8", color);
		break;
	case 9:
		WriteBuffer(x + 1, y, "9", color);
		break;
	default:
		break;
	}
	switch (number % 10)
	{
	case 0:
		WriteBuffer(x + 2, y, "0", color);
		break;
	case 1:
		WriteBuffer(x + 2, y, "1", color);
		break;
	case 2:
		WriteBuffer(x + 2, y, "2", color);
		break;
	case 3:
		WriteBuffer(x + 2, y, "3", color);
		break;
	case 4:
		WriteBuffer(x + 2, y, "4", color);
		break;
	case 5:
		WriteBuffer(x + 2, y, "5", color);
		break;
	case 6:
		WriteBuffer(x + 2, y, "6", color);
		break;
	case 7:
		WriteBuffer(x + 2, y, "7", color);
		break;
	case 8:
		WriteBuffer(x + 2, y, "8", color);
		break;
	case 9:
		WriteBuffer(x + 2, y, "9", color);
		break;
	default:
		break;
	}
}
#pragma endregion

