#include "BulletManager.h"



void BulletManager::Initialize(int x, int y,Dir dir)
{
	for (int i = 0; i < PlayerBulletCount; i++)
	{
		if (bullet[i] == nullptr)
		{
			bullet[i] = new Bullet;
			bullet[i]->Initialize(x, y, dir);
			break;
		}
	}
}

void BulletManager::Progress()
{
	for (int i = 0; i < PlayerBulletCount; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Progress();
			if (bullet[i]->GetX() < 0 || bullet[i]->GetX() > 40 || bullet[i]->GetY() < 0 || bullet[i]->GetY() > 40)
			{
				bullet[i]->Release();
				delete bullet[i];
				bullet[i] = nullptr;
			}
		}
	}

}

void BulletManager::Render()
{

	for (int i = 0; i < PlayerBulletCount; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Render();
		}
	}
}

void BulletManager::Release()
{
	for (int i = 0; i < PlayerBulletCount; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Release();
			delete bullet[i];
			bullet[i] = nullptr;
		}
	}

}
