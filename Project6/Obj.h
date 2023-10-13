#pragma once
#include <vector>
#include <string>
#include "Engine.h"
using namespace std;

enum Dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEFT_UP,
	RIGHT_UP,
	LEFT_DOWN,
	RIGHT_DOWN
	
};

class Obj
{
	int x;
	int y;
	Dir dir;
	vector<string> shape;
	class Engine* engine;
public:
	Obj(int x_, int y_)
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
	void SetX(int x);
	void SetY(int y);
	void SetDir(Dir dir);
	class Engine* GetEngine();
	vector<string> GetShape();
	Dir GetDir();

	int GetX();
	int GetY();
	
	void SetImage(vector<string> shape_);
	void Show();
	void Pysicics();
};