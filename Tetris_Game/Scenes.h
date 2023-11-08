#pragma once
class Scenes
{
public:
	virtual void Initalize()abstract;
	virtual void Progress()abstract;
	virtual void Render()abstract;
	virtual void Release()abstract;
};

