#include "MainMenu.h"
#include <iostream>
#include <conio.h>

#include "Player.h"
#include "FightZone.h"
#include "Town.h"

void MainMenu::In(Player& _Player)
{
	Town NewTown = Town();
	FightZone NewFightZone = FightZone();

	while (true)
	{
		system("cls");

		_Player.StatusRender();
		printf_s("���� ���ðڽ��ϴ�.\n");
		printf_s("1. ����.\n");
		printf_s("2. �����.\n");
		char Input = _getch();

		switch (Input)
		{
			case '1':
			{
				NewTown.In(_Player);
				break;
			}
			case '2':
			{
				NewFightZone.FightZoneMenu(_Player);
				break;
			}
		}

		
	}
}
