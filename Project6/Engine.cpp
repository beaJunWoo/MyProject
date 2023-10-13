#include "Engine.h"
#include <Windows.h>
#include "SetPos.h"

void Engine::Move(int left_KeyPad, int right_KeyPad, int speed)
{
	this->speed = speed;
	if (obj != nullptr)
	{
		bool is_crash = false;
		if (GetAsyncKeyState(left_KeyPad))
		{
			if (GetAsyncKeyState(left_KeyPad))
			{
				for (int y = 0; y < obj->GetShape().size(); y++)
				{
					if (maps->GetMap()[obj->GetY() + y][obj->GetX() - speed] == '1')
						is_crash = true;
				}
				if (!is_crash)
				{
					obj->SetX(obj->GetX() - speed);
					obj->SetDir(LEFT);
				}
			}
		}

		if (GetAsyncKeyState(right_KeyPad))
		{
			for (int y = 0; y < obj->GetShape().size(); y++)
			{
				if (maps->GetMap()[obj->GetY() + y][obj->GetX() + (obj->GetShape()[y].size() / 2) - 1 + speed] == '1')
					is_crash = true;
			}
			if (!is_crash)
			{
				obj->SetX(obj->GetX() + speed);
				obj->SetDir(RIGHT);
			}
		}
	}
}
void Engine::Move(int left_KeyPad, int right_KeyPad, int up_KeyPad, int down_KeyPad, int speed)
{
	if (obj != nullptr)
	{
		moveTimeNow++;
		if ((GetAsyncKeyState(left_KeyPad) && GetAsyncKeyState(up_KeyPad)) || (GetAsyncKeyState(left_KeyPad) && GetAsyncKeyState(down_KeyPad)) ||
			(GetAsyncKeyState(right_KeyPad) && GetAsyncKeyState(up_KeyPad)) || (GetAsyncKeyState(right_KeyPad) && GetAsyncKeyState(down_KeyPad)))
		{
			moveTimeMax = 2;
		}
		else { moveTimeMax = 1; }
		if (moveTimeNow >= moveTimeMax)
		{
			bool is_crash = false;
			if (GetAsyncKeyState(left_KeyPad))
			{
				for (int y = 0; y < obj->GetShape().size(); y++)
				{
					if (maps->GetMap()[obj->GetY() + y][obj->GetX() - speed] == '1')
						is_crash = true; 
				}
				if (!is_crash)
				{
					obj->SetX(obj->GetX()-speed);
					obj->SetDir(LEFT);
				}
			}
			if (GetAsyncKeyState(right_KeyPad))
			{

				for (int y = 0; y < obj->GetShape().size(); y++)
				{
					if (maps->GetMap()[obj->GetY() + y][obj->GetX() +(obj->GetShape()[y].size()/2)-1+ speed] == '1')
						is_crash = true;
				}
				if (!is_crash)
				{
					obj->SetX(obj->GetX() + speed);
					obj->SetDir(RIGHT);
				}
			}
			if (GetAsyncKeyState(up_KeyPad))
			{
				for (int x = 0; x < obj->GetShape()[0].size()/2; x++)
				{
					if (maps->GetMap()[obj->GetY()-speed][obj->GetX() + x] == '1')
						is_crash = true;
				}
				if (!is_crash)
				{
					obj->SetY(obj->GetY() - speed);
					obj->SetDir(UP);
				}
				
			}
			if (GetAsyncKeyState(down_KeyPad))
			{
				for (int y = 0; y < obj->GetShape().size(); y++)
				{
					for (int x = 0; x < obj->GetShape()[y].size() / 2; x++)
					{
						if(maps->GetMap()[obj->GetY()+y+speed][obj->GetX() + x] == '1')
							is_crash = true;
					}
				}
				if (!is_crash)
				{
					obj->SetY(obj->GetY() + speed);
					obj->SetDir(DOWN);
				}
			}
			moveTimeNow = 0;
		}
	}
}

void Engine::Show_Infomation()
{
	SetPos s;
	
	int x = obj->GetX();
	int y = obj->GetY();

	s.SetPosition(3, 3);
	cout << "xÁÂÇ¥:" << x;
	s.SetPosition(3, 4);
	cout << "yÁÂÇ¥:" << y;
	s.SetPosition(3, 5);
	cout << "Dir:" << obj->GetDir();


}