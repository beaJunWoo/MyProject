#include "DataBase.h"
#include <algorithm>

bool DataBase::compare(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second == b.second)
	{
		return a.first > b.first;
	}
	return a.second > b.second;
}
void DataBase::sortData()
{
	sort(RankingData.begin(), RankingData.end(), compare);
}