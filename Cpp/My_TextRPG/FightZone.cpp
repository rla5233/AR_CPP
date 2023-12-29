#include "FightZone.h"
#include <conio.h>
#include <iostream>

#include "Player.h"

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{
		int Input = _getch();
	}

	_First.RandomSetAtt();
	_Second.RandomSetAtt();

	system("cls");

	_Top.StatusRender();
	_Bot.StatusRender();

	{
		int Input = _getch();
	}

	system("cls");

	_Second.DamageLogic(_First);
	_Top.StatusRender();
	_Bot.StatusRender();

	_First.DamageRender();
	if (true == _Second.IsDeath())
	{
		printf_s("게임 종료\n");
		return true;
	}


	{
		int Input = _getch();
		system("cls");
	}


	_First.DamageLogic(_Second);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	_Second.DamageRender();
	if (true == _First.IsDeath())
	{
		printf_s("게임 종료\n");
		return true;
	}
	{
		int Input = _getch();
	}
	system("cls");

	return false;
}

void FightZone::In(Player& _Player)
{
	NewMonster.SetName("Monster");
	NewMonster.SetMinAtt(5);
	NewMonster.SetSizeAtt(5);

	while (true)
	{
		system("cls");

		_Player.StatusRender();
		NewMonster.StatusRender();

		// 선공 후공이 결정 나고
		// 조건에 따라서

		bool IsEnd = false;
		int FirstHitPer = rand() % 100;

		// 60퍼 확률로 플레이어 선공
		if (FirstHitPer < 60)
		{
			printf_s("%s 의 선공\n", _Player.GetName());
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else 
		{
			printf_s("%s 의 선공\n", NewMonster.GetName());
			IsEnd = FightLogic(NewMonster, _Player, _Player, NewMonster);
		}

		if (true == IsEnd)
		{
			return;
		}
	}
}