#pragma once
#include "Scene.h"
#include "Player.h"
class Stage: public Scene
{
	Player* player;
public:
	virtual void Initialize() override;
	virtual void Progress()override;
	virtual void Render()override;
	virtual void Release()override;

};

