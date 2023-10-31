#pragma once
#include "Obj.h"
#include "Buffer.h"
#include "BulletManager.h"
class Player:public Obj
{
	BulletManager* bulletManager;
public:

	virtual void Initialize()
	{
		bulletManager = new BulletManager;
		x = 10;
		y = 10;
		shape = "¿Ê";
		
	}
	virtual void Initialize(int x, int y, Dir dir) {}
	virtual void Progress()
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			bulletManager->Initialize(x, y, dir);
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			x--;
			dir = LEFT;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			x++;
			dir = RIGHT;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			y--;
			dir = UP;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			y++;
			dir = DOWN;
		}
		bulletManager->Progress();
	}
	virtual void Render()
	{
		bulletManager->Render();
		Buffer::Get()->WriteBuffer(x, y, shape, WHITE);	
	}
	virtual void Release()
	{
		bulletManager->Release();
		delete bulletManager;
		bulletManager = nullptr;
	}
};

