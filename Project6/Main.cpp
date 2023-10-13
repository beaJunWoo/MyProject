#include <Windows.h>
#include "Map.h"
#include "Obj.h"
#include "Engine.h"

using namespace std;

Map* map;
int main()
{
	
	vector<string> map1;
	map1.push_back("1111111111111111111111111111111");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000010000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1000000000000000000000000000001");
	map1.push_back("1111111111111111111111111111111");

	map = new Map(map1);

	Obj player(10,10);
	Obj player2(10, 20);

	vector<string> playerImage;
	playerImage.push_back("¡à¡à¡à¡à");
	playerImage.push_back("¡à¡à¡à");
	playerImage.push_back("¡à");
	player.SetImage(playerImage);

	player.Pysicics();
	player.GetEngine()->SetMap(map);

	vector<string> playerImage2;
	playerImage2.push_back("£À£À£À");
	playerImage2.push_back("£À£À£À");
	playerImage2.push_back("£À£À£À");
	player2.SetImage(playerImage2);

	player2.Pysicics();
	player2.GetEngine()->SetMap(map);

	while (true)
	{
	  system("cls");

	  map->Show();

	  player.Show();
	
	  player.GetEngine()->Move(VK_LEFT, VK_RIGHT,VK_UP,VK_DOWN,1);
	  player.GetEngine()->Show_Infomation();
	
	  player2.Show();
	  player2.GetEngine()->Move(0x41, 0x44,1);

	  Sleep(20);
	}
	
	return 0;
}