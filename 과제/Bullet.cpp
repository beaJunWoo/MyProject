#include "Bullet.h"



void Bullet::Initialize(int x, int y, Dir dir)
{
	this->x = x;
	this->y = y;
	this->dir = dir;
	this->shape = "¡Ú";
}

void Bullet::Progress()
{
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
}

void Bullet::Render()
{
	Buffer::Get()->WriteBuffer(x, y, shape, RED);
}

void Bullet::Release()
{
}
