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
		printf_s("어디로 가시겠습니다.\n");
		printf_s("1. 마을.\n");
		printf_s("2. 사냥터.\n");
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
