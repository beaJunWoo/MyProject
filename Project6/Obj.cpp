#include "Obj.h"
#include "SetPos.h"
#include <iostream>
using namespace std;

void Obj::SetImage(vector<string> shape_){ shape = shape_; }	

void Obj::SetX(int x) { this->x = x; }
void Obj::SetY(int y) { this->y = y; }
void Obj::SetDir(Dir dir) { this->dir = dir; }

Engine* Obj::GetEngine() { return engine; }
Dir Obj::GetDir() { return dir; }
int Obj::GetX() { return x; }
int Obj::GetY() { return y; }
vector<string> Obj::GetShape(){return shape;}

void Obj::Show()
{
	SetPos s;
	for (int i = 0; i < shape.size(); i++)
	{
		s.SetPosition(x, y + i);
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