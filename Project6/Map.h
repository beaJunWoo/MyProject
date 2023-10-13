#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;


class Map
{
	vector<string>map;
public:
	Map()
	{
		map.push_back("맵이 없습니다");
	}
	Map(vector<string>map_)
	{
		map = map_;
	}

	void Show();
	vector<string> GetMap();
};