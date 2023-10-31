#include "Logo.h"
#include "ScenceManager.h"
#include "Buffer.h"

void Logo::Initialize()
{
}

void Logo::Progress()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		ScenceManager::Get()->Initialize(MENU);
	}
}

void Logo::Render()
{
	Buffer::Get()->WriteBuffer(10, 10, "Logo", WHITE);
}

void Logo::Release()
{
}
