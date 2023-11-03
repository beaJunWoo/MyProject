#include "Logo.h"
#include "DoubleBuffer.h"
#include "ScenesManager.h"
void Logo::Initalize()
{
}

void Logo::Progress()
{
	if (GetAsyncKeyState(0X41))
	{
		ScenesManager::Get()->Initalize(MENU);
	}
}

void Logo::Render()
{
	DoubleBuffer::Get()->WriteBuffer(1, 1, "Logo", WHITE);
}

void Logo::Release()
{
}
