#pragma once
#include "Header.h"
class Obj
{
protected:
	int x;
	int y;
	Dir dir;
	const char* shape;
public:
	virtual void Initialize(int x, int y, Dir dir) = 0;
	virtual void Initialize() = 0;
	virtual void Progress() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
};

