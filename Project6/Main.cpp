#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

enum Dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

using namespace std;
struct Engine;
struct Obj;
struct Map;
void SetPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


struct Map
{
	vector<string>map;
	Map()
	{
		map.push_back("맵이 없습니다");
	}
	Map(vector<string>map_)
	{
		map = map_;
	}

	void Show()
	{
		for (int y = 0; y < map.size(); y++)
		{
			for (int x = 0; x < map[y].size(); x++)
			{
				SetPosition(x, y);
				switch (map[y][x])
				{
				case '1':
					cout << "■";
					break;
				default:
					break;
				}
			}
		}
	}
};

struct Engine
{
	Obj* obj;
	Map* maps;
	float speed;

	Engine(Obj* obj_)
	{
		obj = obj_;
	}
	void Move(int left_KeyPad, int right_KeyPad, float speed);
	void Move(int left_KeyPad, int right_KeyPad, int up_KeyPad, int down_KeyPad, float speed);
	void SetMap(Map* map_) { maps = map_; };
	void Crash_active();
	void Show_Infomation();
};

struct Obj
{
	float x;
	float y;
	Dir dir;
	vector<string> shape;
	Engine* engine;
	Obj(float x_, float y_)
	{
		x = x_;
		y = y_;
		dir = RIGHT;
		shape.push_back("이미지가 없습니다.");
		shape.push_back("SetImage()함수로 이미지를 설정해주세요.");
		engine = nullptr;
	}
	~Obj()
	{
		if (engine != nullptr)
		{
			delete engine;
			engine = nullptr;
		}
	}
	void SetImage(vector<string> shape_);
	void Show();
	void Pysicics();
};


void Engine::Move(int left_KeyPad, int right_KeyPad, float speed)
{
	this->speed = speed;
	if (obj != nullptr)
	{
		if (GetAsyncKeyState(left_KeyPad))
		{
			obj->x -= speed;
			obj->dir = LEFT;
		}

		if (GetAsyncKeyState(right_KeyPad))
		{
			obj->x += speed;
			obj->dir = RIGHT;
		}
	}
}
void Engine::Move(int left_KeyPad, int right_KeyPad, int up_KeyPad, int down_KeyPad, float speed)
{
	if (obj != nullptr)
	{
		if (GetAsyncKeyState(left_KeyPad))
		{
			obj->x -= speed; 
			obj->dir = LEFT;
		}
		if (GetAsyncKeyState(right_KeyPad))
		{
			obj->x += speed; 
			obj->dir = RIGHT;
		}
		if (GetAsyncKeyState(up_KeyPad))
		{
			obj->y -= speed; 
			obj->dir = UP;
		}	
		if (GetAsyncKeyState(down_KeyPad))
		{
			obj->y += speed; 
			obj->dir = DOWN;
		}
			
	}

}
void Engine::Crash_active()
{
	int x = obj->x;
	int y = obj->y;

	if (maps->map[y][x] == '1')
	{
		
		switch (obj->dir)
		{
		case LEFT:
			obj->x += 1;
			break;
		case RIGHT:
			obj->x -= 1;
			break;
		case UP:
			obj->y += 1;
			break;
		case DOWN:
			obj->y -= 1;
			break;
		default:
			break;
		}
	}
}
void Engine::Show_Infomation()
{

	int x = obj->x;
	int y = obj->y;

	SetPosition(3, 3);
	cout << "x좌표:" << x;
	SetPosition(3, 4);
	cout << "y좌표:" << obj->y;
	SetPosition(3, 5);
	cout << "Dir:" << obj->dir;

	
}
void Obj::SetImage(vector<string> shape_)
{
	shape = shape_;
}
void Obj::Show()
{
	for (int i = 0; i < shape.size(); i++)
	{
		SetPosition(x, y + i);
		cout << shape[i] << endl;
	}
}
void Obj::Pysicics()
{
	if (engine == nullptr)
	{
		engine = new Engine(this);
		this->engine = engine;
	}
	else
	{
		delete engine;
		engine = nullptr;
		engine = new Engine(this);
		this->engine = engine;
	}
}

Map* map;
int main()
{
	vector<string> map1;
	map1.push_back("1111111111111111111111111111111");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1111111111111111111111111111111");

	map = new Map(map1);

	Obj player(10,10);
	Obj player2(10, 20);

	vector<string> playerImage;
	playerImage.push_back("┌────┐");
	playerImage.push_back("│    │");
	playerImage.push_back("└────┘");
	player.SetImage(playerImage);

	player.Pysicics();
	player.engine->SetMap(map);

	vector<string> playerImage2;
	playerImage2.push_back("┌─┐");
	playerImage2.push_back("│ │");
	playerImage2.push_back("└─┘");
	player2.SetImage(playerImage2);
	player2.Pysicics();

	while (true)
	{
	  system("cls");

	  map->Show();

	  player.Show();
	
	  player.engine->Move(VK_LEFT, VK_RIGHT, 1);
	  player.engine->Crash_active();
	  player.engine->Show_Infomation();
	
	  player2.Show();
	  player2.engine->Move(0x41, 0x44, 0.5);

	  Sleep(20);
	}
	
	return 0;
}