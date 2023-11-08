#include "DoubleBuffer.h"
#include "ScenesManager.h"
#include "DataBase.h"

int main()

 {
	int DelayTime = 10;
	ULONGLONG deltatime = GetTickCount64();

	ScenesManager::Get()->Initalize(LOGO);
	DoubleBuffer::Get()->InitBuffer();

	while (true)
	{
		if (deltatime + DelayTime <= GetTickCount64())
		{

			DoubleBuffer::Get()->FlipBuffer();
			DoubleBuffer::Get()->ClearBuffer();

			ScenesManager::Get()->Progress();
			ScenesManager::Get()->Render();

			if(ScenesManager::Get()->GetFinishGame()) {break;}

			deltatime = GetTickCount64();
		}
	}

	DoubleBuffer::Get()->ReleaseBuffer();
	ScenesManager::Get()->Release();
	return 0;
}