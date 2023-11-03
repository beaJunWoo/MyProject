#pragma once
#include "Header.h"
#include <map>
class DataBase
{
	map<string, int> RankingData;
public:
	DataBase()
	{}
	map<string, int>& GetRankingData()
	{ 
		return RankingData;
	}
};

