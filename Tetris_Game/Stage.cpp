#include "Stage.h"
#include "DoubleBuffer.h"
void Stage::Initalize()
{
	map = new Map;
	map->Initalize();

	blockManager = new BlockManager;
	blockManager->Initalize(map);

	score = new Score(map);
	score->Initalize();

	DataInsertDelay = 0;
}

void Stage::Progress()
{
	map->Progress();
	blockManager->Progress();
	score->Progress();

	if (score->Get_isFinishGame())
	{
		while (DataInsertDelay<10)
		{
			DoubleBuffer::Get()->FlipBuffer();
			DoubleBuffer::Get()->ClearBuffer();
			DoubleBuffer::Get()->WriteBuffer(1, 1, "닉네임 입력:", WHITE);
			DataInsertDelay++;
		}
		DataInsertDelay = 0;
		string nickname;
		while(nickname == "")
		{
			cin >> nickname;
		}
	
		ScenesManager::Get()->GetDataBase().GetRankingData().insert(make_pair(nickname, score->GetTotalScore()));
		ScenesManager::Get()->Initalize(RANKING);
	}
}

void Stage::Render()
{
	DoubleBuffer::Get()->WriteBuffer(1, 1, "Stage", WHITE);
	
	score->Render();
	blockManager->Render();
	map->Render();
}

void Stage::Release()
{
	map->Release();
	delete map;
	map = nullptr;

	blockManager->Release();
	delete blockManager;
	blockManager = nullptr;

	score->Release();
	delete score;
	score = nullptr;
}
