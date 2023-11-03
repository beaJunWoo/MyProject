#pragma once
#include "Map.h"
#include "DoubleBuffer.h"
class Score
{
	Map* map;
	int totalScore;
	
	bool is_FinishGame;
	//점수 보여주는 시간 
	int showScoreDelay;
	int showScoreNow;
public:
	Score(Map* map) :map(map), totalScore(0) {}
	void Initalize();
	void Progress();
	void Render();
	void Release();

	int GetTotalScore() { return totalScore; }
	bool Get_isFinishGame() { return is_FinishGame; }
};

