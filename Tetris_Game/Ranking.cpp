#include "Ranking.h"

void Ranking::Initalize()
{
	InsertRank = false;
	delay = 0;
}

void Ranking::Progress()
{
	if (GetAsyncKeyState(VK_F1))
	{
		ScenesManager::Get()->Initalize(MENU);
	}


}

void Ranking::Render()
{
	int i = 0;
	for (auto v : ScenesManager::Get()->GetDataBase().GetRankingData())
	{
		DoubleBuffer::Get()->WriteBuffer(10, 10+i, v.first.c_str(), WHITE);
		DoubleBuffer::Get()->WriteBuffer(15, 10+i, to_string(v.second).c_str(), WHITE);
		i++;
	}
	DoubleBuffer::Get()->WriteBuffer(5, 5, "메뉴로 돌아가기(F1)", WHITE);
}

void Ranking::Release()
{
}
