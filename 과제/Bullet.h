#pragma once
#include "Obj.h"
#include "Buffer.h"
class Bullet : public Obj
{
public:
	Bullet()
	{
		this->x = 0;
		this->y = 0;
	}
	virtual void Initialize() {}
	virtual void Initialize(int x, int y, Dir dir);
	virtual void Progress()override;
	virtual void Render()override;
	virtual void Release()override;
	int GetX() { return x; }
	int GetY() { return y; }
};

