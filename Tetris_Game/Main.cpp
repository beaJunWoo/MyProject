#include "DoubleBuffer.h"
#include "ScenesManager.h"

int main()
{
	ScenesManager::Get()->Initalize(LOGO);
	DoubleBuffer::Get()->InitBuffer();
	while (true)
	{
		DoubleBuffer::Get()->FlipBuffer();
		DoubleBuffer::Get()->ClearBuffer();
		ScenesManager::Get()->Progress();
		ScenesManager::Get()->Render();
		Sleep(50);
	}
	DoubleBuffer::Get()->ReleaseBuffer();
	ScenesManager::Get()->Release();
	return 0;
}