#pragma once
#include "Header.h"
class Buffer
{
public:
	 HANDLE hBuffer[2];
	 int screenIndex;

	static Buffer* buffer;
	static Buffer* Get()
	{
		if (buffer == nullptr)
		{
			buffer = new Buffer;
		}
		return buffer;
	}
	void InitBuffer();
	void FlipBuffer();
	void ClearBuffer();
	void WriteBuffer(int x, int y, const char* shape, int color);
	void ReleaseBuffer();
};

