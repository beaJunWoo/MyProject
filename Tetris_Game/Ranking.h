#pragma once
#include "Scenes.h"
#include "ScenesManager.h"
#include "DoubleBuffer.h"
class Ranking :public Scenes
{
	vector<string>RankingText;
	bool InsertRank;
	int delay;
public:
	bool comp(pair<string, int> a, pair<string, int>b);

	virtual void Initalize()override;
	virtual void Progress()override;
	virtual void Render()override;
	virtual void Release()override;
};

