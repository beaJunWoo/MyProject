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
		map.push_back("���� �����ϴ�");
	}
	Map(vector<string>map_)
	{
		map = map_;
	}

	void Show();
	vector<string> GetMap();
};