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

	NickNameSelectX = 0;
	NickNameSelectY = 0;

	Alphabet[0].push_back("A");
	Alphabet[0].push_back("B");
	Alphabet[0].push_back("C");
	Alphabet[0].push_back("D");
	Alphabet[0].push_back("E");
	Alphabet[0].push_back("F");
	Alphabet[0].push_back("G");
	Alphabet[0].push_back("Save");
	Alphabet[0].push_back("AllClear");

	Alphabet[1].push_back("H");
	Alphabet[1].push_back("I");
	Alphabet[1].push_back("J");
	Alphabet[1].push_back("K");
	Alphabet[1].push_back("L");
	Alphabet[1].push_back("M");
	Alphabet[1].push_back("N");
	Alphabet[1].push_back("O");
	Alphabet[1].push_back("P");
	Alphabet[1].push_back("←");

	Alphabet[2].push_back("Q");
	Alphabet[2].push_back("R");
	Alphabet[2].push_back("S");
	Alphabet[2].push_back("T");
	Alphabet[2].push_back("U");
	Alphabet[2].push_back("V");
	Alphabet[2].push_back("W");
	Alphabet[2].push_back("X");
	Alphabet[2].push_back("Y");
	Alphabet[2].push_back("Z");
}
using std::numeric_limits;
void Stage::Progress()
{
	//게임 진행중일때
	if (!score->Get_isFinishGame())
	{
		map->Progress();
		blockManager->Progress();
		score->Progress();
	}

	//게임 끝났을때
	if (score->Get_isFinishGame())
	{
		if (DataInsertDelay > 100)
		{
			string NickName = "";
			while (true)
			{
				DataInsertDelay++;
				DoubleBuffer::Get()->FlipBuffer();
				DoubleBuffer::Get()->ClearBuffer();
				DoubleBuffer::Get()->WriteBuffer(2, 2, NickName.c_str(), WHITE);
				DoubleBuffer::Get()->WriteBuffer(1, 1, "랭킹에 저장할 이름을입력해주세요.", WHITE);


				DoubleBuffer::Get()->WriteBuffer(20, 16, "[조작방법]", WHITE);
				DoubleBuffer::Get()->WriteBuffer(20, 17, "← → 좌우 이동", WHITE);
				DoubleBuffer::Get()->WriteBuffer(20, 18, "↑↓ 위아래 이동", WHITE);
				DoubleBuffer::Get()->WriteBuffer(20, 19, "Save 이름 저장하기", WHITE);

				if (DataInsertDelay > 40)
				{
					if (GetAsyncKeyState(VK_RIGHT))
					{
						NickNameSelectX++;
						DataInsertDelay = 0;
					}
					if (GetAsyncKeyState(VK_LEFT))
					{
						NickNameSelectX--;
						DataInsertDelay = 0;
					}
					if (GetAsyncKeyState(VK_UP))
					{
						NickNameSelectY--;
						DataInsertDelay = 0;
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						NickNameSelectY++;
						DataInsertDelay = 0;
					}
					if (NickNameSelectX < 0) { NickNameSelectX = 0; }
					if (NickNameSelectX > 9) { NickNameSelectX = 9; }
					if (NickNameSelectY < 0) { NickNameSelectY = 0; }
					if (NickNameSelectY > 2) { NickNameSelectY = 2; }
				}

				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < Alphabet[i].size(); j++)
					{
						if (i == NickNameSelectY && j == NickNameSelectX)
							DoubleBuffer::Get()->WriteBuffer(10 + j * 3, 5 + i, Alphabet[i][j], RED);
						else
							DoubleBuffer::Get()->WriteBuffer(10 + j * 3, 5 + i, Alphabet[i][j], WHITE);
					}
				}
				if (GetAsyncKeyState(VK_RETURN) && DataInsertDelay > 60)
				{
					if (!(Alphabet[NickNameSelectY][NickNameSelectX] == "←"
						|| Alphabet[NickNameSelectY][NickNameSelectX] == "AllClear"
						|| Alphabet[NickNameSelectY][NickNameSelectX] == "Save"))
					{
						NickName += Alphabet[NickNameSelectY][NickNameSelectX];
					}

					if (Alphabet[NickNameSelectY][NickNameSelectX] == "←")
					{
						if (NickName.size() > 0)
						{
							NickName.erase(NickName.end() - 1);
						}
					}
					if (Alphabet[NickNameSelectY][NickNameSelectX] == "AllClear")
					{
						NickName.clear();
					}
					if (Alphabet[NickNameSelectY][NickNameSelectX] == "Save")
					{
						break;
					}
					DataInsertDelay = 0;
				}
			}

			ScenesManager::Get()->GetDataBase().GetRankingData().push_back(make_pair(NickName, score->GetTotalScore()));

			ScenesManager::Get()->Initalize(RANKING);
		}
	}
}

void Stage::Render()
{	

	DoubleBuffer::Get()->WriteBuffer(20, 16, "[조작방법]", WHITE);
	DoubleBuffer::Get()->WriteBuffer(20, 17, "← → 좌우 이동", WHITE);
	DoubleBuffer::Get()->WriteBuffer(20, 18, "SPACE 회전", WHITE);
	DoubleBuffer::Get()->WriteBuffer(20, 19, "↓길게(천천히 떨어트리기)", WHITE);
	DoubleBuffer::Get()->WriteBuffer(20, 20, "↓짧게(빨리 떨어트리기)", WHITE);

	score->Render();
	blockManager->Render();
	map->Render();

	if (score->Get_isFinishGame())
	{
		DataInsertDelay++;
		if (DataInsertDelay < 100)
		{
			DoubleBuffer::Get()->WriteBuffer(4, 10, "-GameOver-", LIGHTRED);
		}
	}
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
