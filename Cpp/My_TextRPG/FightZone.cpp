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
		printf_s("���� ����\n");
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
		printf_s("���� ����\n");
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

		// ���� �İ��� ���� ����
		// ���ǿ� ����

		bool IsEnd = false;
		int FirstHitPer = rand() % 100;

		// 60�� Ȯ���� �÷��̾� ����
		if (FirstHitPer < 60)
		{
			printf_s("%s �� ����\n", _Player.GetName());
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else 
		{
			printf_s("%s �� ����\n", NewMonster.GetName());
			IsEnd = FightLogic(NewMonster, _Player, _Player, NewMonster);
		}

		if (true == IsEnd)
		{
			return;
		}
	}
}