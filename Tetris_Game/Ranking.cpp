#include "Ranking.h"
#include <algorithm>



void Ranking::Initalize()
{
	RankingText.push_back("`7MM'''Mq.                       `7MM        db                      ");
	RankingText.push_back("  MM   `MM.                        MM                                ");
	RankingText.push_back("  MM   ,M9   ,6'Yb.  `7MMpMMMb.    MM  ,MP'`7MM  `7MMpMMMb..P'Ybmmm' ");
	RankingText.push_back("  MMmmdM9   8)   MM    MM    MM    MM ;Y     MM    MM    MM :MI  I8  ");
	RankingText.push_back("  MM  YM.    ,pm9MM    MM    MM    MM;Mm     MM    MM    MM  WmmmP'  ");
	RankingText.push_back("  MM   `Mb. 8M   MM    MM    MM    MM `Mb.   MM    MM    MM 8M       ");
	RankingText.push_back(".JMML. .JMM.`Moo9^Yo..JMML  JMML..JMML. YA..JMML..JMML  JMML.YMMMMMb ");
	RankingText.push_back("                                                            6'     dP");
	RankingText.push_back("                                                            Ybmmmd'  ");
	InsertRank = false;
	delay = 0;
	
}

void Ranking::Progress()
{
	if (GetAsyncKeyState(VK_F1))
	{
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {}
		ScenesManager::Get()->Initalize(MENU);
	}
}

void Ranking::Render()
{
	for (int i = 0; i < RankingText.size(); i++)
	{
		DoubleBuffer::Get()->WriteBuffer(5, 5 + i, RankingText[i].c_str(), YELLOW);
	}

	ScenesManager::Get()->GetDataBase().sortData();

	int i= 0;
	for (auto v : ScenesManager::Get()->GetDataBase().GetRankingData())
	{
		DoubleBuffer::Get()->WriteBuffer(7, 20 + i * 2, to_string(i+1).c_str(), WHITE);
		DoubleBuffer::Get()->WriteBuffer(8, 20 + i * 2, "등", WHITE);
		DoubleBuffer::Get()->WriteBuffer(15, 20+i*2, to_string(v.second).c_str(), WHITE);
		DoubleBuffer::Get()->WriteBuffer(10, 20+i*2, v.first.c_str(), WHITE);
		i++;
	}
	DoubleBuffer::Get()->WriteBuffer(2, 2, "메뉴로 돌아가기(F1)", WHITE);
}

void Ranking::Release()
{
}
