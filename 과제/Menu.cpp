#include "Menu.h"
#include "ScenceManager.h"
#include "Buffer.h"

void Menu::Initialize()
{
}

void Menu::Progress()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		ScenceManager::Get()->Initialize(STAGE);
	}
}

void Menu::Render()
{
	Buffer::Get()->WriteBuffer(10, 10, "Menu", WHITE);
}

void Menu::Release()
{
}
