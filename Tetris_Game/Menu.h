#pragma once
#include "Scenes.h"
class Menu : public Scenes
{
	virtual void Initalize()override;
	virtual void Progress()override;
	virtual void Render()override;
	virtual void Release()override;
};

