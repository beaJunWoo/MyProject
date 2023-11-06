#pragma once
#include "Scenes.h"
#include "Header.h"
class Logo:public Scenes
{
	int AddIndexDelay;
	int NowAnimationSceneIndex;
	int BlinkTextDelay;
	vector<string> LogoAnimation[78];
public:
	virtual void Initalize()override;
	virtual void Progress()override;
	virtual void Render()override;
	virtual void Release()override;
};

