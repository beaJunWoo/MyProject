#pragma once
#include "Scenes.h"
#include "ScenesManager.h"
#include "DoubleBuffer.h"
class Ranking :public Scenes
{
	bool InsertRank;
	int delay;
public:
	virtual void Initalize()override;
	virtual void Progress()override;
	virtual void Render()override;
	virtual void Release()override;
};

