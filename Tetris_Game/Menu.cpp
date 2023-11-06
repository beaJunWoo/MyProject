#include "Menu.h"
#include "DoubleBuffer.h"
#include "ScenesManager.h"

void Menu::Initalize()
{
	MenuTextColor[0] = LIGHTBLUE;
	MenuTextColor[1] = LIGHTMAGENTA;
	MenuTextColor[2] = LIGHTGRAY;
	MenuTextColor[3] = LIGHTCYAN;
	MenuTextColor[4] = YELLOW;
	MenuTextColor[5] = LIGHTRED;

	StageTextColor=WHITE;
	RankingTextColor = WHITE;

	MenuText[0].push_back("MMP''MM''YMM");
	MenuText[0].push_back("P'   MM   `7");
	MenuText[0].push_back("     MM     ");
	MenuText[0].push_back("     MM     ");
	MenuText[0].push_back("     MM     ");
	MenuText[0].push_back("     MM     ");
	MenuText[0].push_back("   .JMML.   ");
	
	MenuText[1].push_back("`7MM'''YMM ");
	MenuText[1].push_back("  MM    `7  ");
	MenuText[1].push_back("  MM   d    ");
	MenuText[1].push_back("  MMmmMM    ");
	MenuText[1].push_back("  MM   Y  , ");
	MenuText[1].push_back("  MM     ,M ");
	MenuText[1].push_back(".JMMmmmmMMM ");


	MenuText[2].push_back(" MMP''MM''YMM ");
	MenuText[2].push_back(" P'   MM   `7 ");
	MenuText[2].push_back("      MM      ");
	MenuText[2].push_back("      MM      ");
	MenuText[2].push_back("      MM      ");
	MenuText[2].push_back("      MM      ");
	MenuText[2].push_back("    .JMML.    ");


	MenuText[3].push_back(" `7MM'''Mq.  ");
	MenuText[3].push_back("   MM   `MM. ");
	MenuText[3].push_back("   MM   ,M9  ");
	MenuText[3].push_back("   MMmmdM9   ");
	MenuText[3].push_back("   MM  YM.   ");
	MenuText[3].push_back("   MM   `Mb. ");
	MenuText[3].push_back(" .JMML. .JMM.");


	MenuText[4].push_back("`7MMF'");
	MenuText[4].push_back("  MM  ");
	MenuText[4].push_back("  MM  ");
	MenuText[4].push_back("  MM  ");
	MenuText[4].push_back("  MM  ");
	MenuText[4].push_back("  MM  ");
	MenuText[4].push_back(".JMML.");


	MenuText[5].push_back(".M'''bgd ");
	MenuText[5].push_back(",MI    'Y ");
	MenuText[5].push_back("`MMb.     ");
	MenuText[5].push_back("  `YMMNq. ");
	MenuText[5].push_back(".     `MM ");
	MenuText[5].push_back("Mb     dM ");
	MenuText[5].push_back("P'Ybmmd'  ");                                                           

	menuSelect = STAGE;
	SelectInputDelay = 0;
}

void Menu::Progress()
{
	SelectInputDelay++;
	if (SelectInputDelay > 10)
	{
		if (menuSelect == STAGE)
		{
			if (GetAsyncKeyState(VK_RIGHT))
			{
				menuSelect = RANKING;
				SelectInputDelay = 0;
			}
		}
		else if (menuSelect == RANKING)
		{
			if (GetAsyncKeyState(VK_LEFT))
			{
				menuSelect = STAGE;
				SelectInputDelay = 0;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				menuSelect = EXIT;
				SelectInputDelay = 0;
			}
		}
		else if (menuSelect == EXIT)
		{
			if (GetAsyncKeyState(VK_LEFT))
			{
				menuSelect = RANKING;
				SelectInputDelay = 0;
			}
		}
	}
	

	if (GetAsyncKeyState(VK_SPACE))
	{
		ScenesManager::Get()->Initalize(menuSelect);
	}
}

void Menu::Render()
{
	DoubleBuffer::Get()->WriteBuffer(22, 15, "-Menu-", WHITE);
	
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < MenuText[j].size(); i++)
		{
			DoubleBuffer::Get()->WriteBuffer(7*j+5, 3 + i, MenuText[j][i].c_str(), MenuTextColor[j]);
		}
	}
	switch (menuSelect)
	{
	case EXIT:
		ExitTextColor = RED;
		StageTextColor = WHITE;
		RankingTextColor = WHITE;
		break;
	case STAGE:
		ExitTextColor = WHITE;
		StageTextColor = RED;
		RankingTextColor = WHITE;
		break;
	case RANKING:
		ExitTextColor = WHITE;
		StageTextColor = WHITE;
		RankingTextColor = RED;
		break;
	default:
		break;
	}

	DoubleBuffer::Get()->WriteBuffer(10, 12, "[Stage]", StageTextColor);
	DoubleBuffer::Get()->WriteBuffer(20, 12, "[Ranking]", RankingTextColor);
	DoubleBuffer::Get()->WriteBuffer(30, 12, "[Exit]", ExitTextColor);
}

void Menu::Release()
{
}
