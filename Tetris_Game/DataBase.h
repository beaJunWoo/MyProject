#pragma once
#include "Header.h"
#include <algorithm>
#include <map>

class DataBase
{
	vector<pair<string, int>> RankingData;
public:
	DataBase()
	{}
	static bool compare(const pair<string, int> &a,const pair<string, int>&b);
	vector<pair<string,int>> & GetRankingData()
	{ 
		return RankingData;
	}
	void sortData();
};

