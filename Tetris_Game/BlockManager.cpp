#include "BlockManager.h"

void BlockManager::Initalize(Map*map)
{
	this->map = map;
	block = new Block;
	NextBlock = rand() % 7;
	Time = 0;
	LV = 0;
	Defalt_Fall_DelayTime = 20;
}

void BlockManager::Progress()
{
	//일정시간이후 스피드 증가
	Time++;
	DoubleBuffer::Get()->WriteBuffer(3, 3, to_string(Defalt_Fall_DelayTime).c_str(), WHITE);
	if (Time%1000==0&& Defalt_Fall_DelayTime>0)
	{
		Defalt_Fall_DelayTime -= LV*(LV*0.5); //스피드 기본값 감소
		LV++;

		//LV오를때마다 랜덤 블록 생성
		
		//래벨 만큼 블록 추가
		for (int n = 0; n < LV; n++)
		{
			string randomLine = "122222222221";
			int Eempty_BlockCount = rand() % 5 + 1; //블록이 없는 빈공간 개수
			for (int i = 0; i < Eempty_BlockCount; i++)
			{
				int r = rand() % 10 + 1;
				randomLine[r] = '0';
			}//개수 만큼 빈공간으로 채우기(중복있더라도 무조건 1개이상은 빈블록임)

			map->GetMapReference().erase(map->GetMapReference().begin() + 1); //1번째 공간 제거
			map->GetMapReference()[21] = randomLine;//랜덤 블록 추가
			map->GetMapReference().push_back("111111111111");
		}
		
	}                                  


	//블록 제거
	if (block != nullptr)
	{
		if (!block->GetIs_Act())
		{
			DoubleBuffer::Get()->WriteBuffer(2, 2, "삭제 되었습니다.", WHITE);
			delete block;
			block = nullptr;
		}
	}
	
	//블록 생성
	if(block ==nullptr)
	{
		block = new Block;
		block->Initalize(map, NextBlock);
		block->Set_FallDelayTime(Defalt_Fall_DelayTime);
		DoubleBuffer::Get()->WriteBuffer(5, 5, to_string(NextBlock).c_str(), WHITE);
		NextBlock = rand() % 7;
	}
	block->Progress();

	//다음 블록 보여주기
	if (block != nullptr)
	{
		DoubleBuffer::Get()->WriteBuffer(13,1, "다음 블록▼", WHITE);
		for (int y = 0; y < block->GetShape(NextBlock*4).size(); y++)
		{
			for (int x = 0; x < block->GetShape(NextBlock*4)[y].size(); x++)
			{
				switch (block->GetShape(NextBlock*4)[y][x])
				{
				case '1':
					DoubleBuffer::Get()->WriteBuffer(x + 15, y + 2,"■",WHITE);
					break;
				default:
					break;
				}
			}
		}
	}
}

void BlockManager::Render()
{
	if (block != nullptr)
	{
		block->Render();
	}
	DoubleBuffer::Get()->WriteBuffer(20, 20, "LV:", WHITE);
	DoubleBuffer::Get()->WriteBuffer(22, 20, to_string(LV).c_str(), WHITE);
}

void BlockManager::Release()
{
	if (block != nullptr)
	{
		block->Release();
	}
}
