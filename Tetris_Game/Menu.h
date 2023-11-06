#pragma once
#include "Scenes.h"
#include "Header.h"
class Menu : public Scenes
{
	vector<string>MenuText[6];
	Color MenuTextColor[6];
	SceneId menuSelect;
	Color StageTextColor;
	Color RankingTextColor;
	Color ExitTextColor;
	int SelectInputDelay;
public:
	virtual void Initalize()override;
	virtual void Progress()override;
	virtual void Render()override;
	virtual void Release()override;
};

