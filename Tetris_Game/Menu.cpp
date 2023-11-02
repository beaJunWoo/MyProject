#include "Menu.h"
#include "DoubleBuffer.h"
#include "ScenesManager.h"

void Menu::Initalize()
{
}

void Menu::Progress()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		ScenesManager::Get()->Initalize(STAGE);
	}
	
}

void Menu::Render()
{
	DoubleBuffer::Get()->WriteBuffer(1, 1, "Menu", WHITE);
}

void Menu::Release()
{
}
