#include "FightZone.h"
#include <conio.h>
#include <iostream>

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	system("cls");

	_First.RandomSetAtt();
	_Second.RandomSetAtt();

	_Top.StatusRender();
	_Bot.StatusRender();

	{
		int Input = _getch();
		system("cls");
	}
	
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

void FightZone::Fight(FightUnit& _Player)
{
	NewMonster.SetName("Monster");
	NewMonster.SetMinAtt(5);
	NewMonster.SetSizeAtt(5);

	while (true)
	{
		_Player.StatusRender();
		NewMonster.StatusRender();

		// 선공 후공이 결정 나고
		// 조건에 따라서

		bool IsEnd = false;
		int FirstHitPer = rand() % 100;

		// 60퍼 확률로 플레이어 선공
		if (FirstHitPer < 60)
		{
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else 
		{
			IsEnd = FightLogic(NewMonster, _Player, _Player, NewMonster);
		}

		if (true == IsEnd)
		{
			return;
		}
	}
}