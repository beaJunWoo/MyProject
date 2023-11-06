#include "Score.h"

void Score::Initalize()
{
	int showScoreDelay = 999999999;
	int showScoreNow = 0;
	is_FinishGame = false;
}

void Score::Progress()
{
	int ClearBlockCount = 0;

	//�ı� ���� �� ��� ã��
	for (int y=1; y<22; y++)
	{
		bool AllClear = true;
		for (int x = 1; x < 11; x++)
		{
			if (map->GetMap()[y][x] == '0') { AllClear = false; }
		}
		if (AllClear)	//������ ���� ������� ä��������
		{
			ClearBlockCount++;
			for (int i = y; i >1; i--)
			{
				map->GetMapReference()[i] = map->GetMapReference()[i - 1];
			}
		}
	}
	//�ı��� ��ϼ��� ���� ��ŭ ���� �߰�
	int score = ClearBlockCount * ClearBlockCount * 10;
	if (score != 0)
	{
		totalScore += score;
	}
	for (int i = 1; i < 10; i++)
	{
		if (map->GetMap()[3][i] >= '2') { is_FinishGame = true; }
	}
	
}

void Score::Render()
{
	DoubleBuffer::Get()->WriteBuffer(15, 7, "����:", WHITE);
	DoubleBuffer::Get()->WriteBuffer(18, 7, to_string(totalScore).c_str(), WHITE);
	DoubleBuffer::Get()->WriteBuffer(1,3,"��������������������������������������", WHITE);
}

void Score::Release()
{
}
