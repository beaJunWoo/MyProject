#pragma once
#include "Bullet.h"
class BulletManager
{
	Bullet* bullet[PlayerBulletCount];
public:
	BulletManager()
	{
		for (int i = 0; i < PlayerBulletCount; i++)
		{
			bullet[i] = nullptr;
		}
	}
	void Initialize(int x, int y, Dir dir);
	void Progress();
	void Render();
	void Release();
};

