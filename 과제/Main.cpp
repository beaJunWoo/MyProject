#include "ScenceManager.h"
#include "Buffer.h"

int main()
{


	Buffer::Get()->InitBuffer();
	ScenceManager::Get()->Initialize(LOGO);

	while (true)
	{
		ScenceManager::Get()->Progress();
		ScenceManager::Get()->Render();

		Buffer::Get()->FlipBuffer();
		Buffer::Get()->ClearBuffer();
		Sleep(10);
	}
	Buffer::Get()->ReleaseBuffer();
	ScenceManager::Get()->Release();
}