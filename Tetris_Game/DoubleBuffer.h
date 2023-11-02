#pragma once
#include "Header.h"
class DoubleBuffer
{
	HANDLE hBuffer[2];
	int screenIndex;
	static DoubleBuffer* buffer;
public:
	static DoubleBuffer* Get()
	{
		if (buffer == nullptr)
		{
			buffer = new DoubleBuffer;
		}
		return buffer;
	}
	void InitBuffer();
	void FlipBuffer();
	void ClearBuffer();
	void WriteBuffer(int x, int y, const char* shape, int color);
	void ReleaseBuffer();
};

