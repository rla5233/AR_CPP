#include "FightZone.h"
#include <conio.h>
#include <iostream>

#include "Player.h"
#include "Monster.h"

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, Player& _Player, Monster& _Monster)
{
	{ char break_point = _getch(); }

	_First.RandomSetAtt();
	_Second.RandomSetAtt();

	system("cls");

	_Player.StatusRender();
	_Monster.StatusRender();

	{ char break_point = _getch(); }
	system("cls");

	_Second.DamageLogic(_First);
	_Player.StatusRender();
	_Monster.StatusRender();
	_First.DamageRender();
	if (_Second.IsDeath())
	{
		if (_Monster.IsDeath())	{ _Player.SetGold(_Player.GetGold() + _Monster.GetGold()); }

		printf_s("\n���� ����");
		printf_s("\n%d Gold �� ȹ���Ͽ����ϴ�!", _Monster.GetGold());
		{ char break_point = _getch(); }

		return true;
	}

	{ char break_point = _getch(); }
	system("cls");

	_First.DamageLogic(_Second);
	_Player.StatusRender();
	_Monster.StatusRender();
	_First.DamageRender();
	_Second.DamageRender();
	if (_First.IsDeath())
	{
		if (_Monster.IsDeath())	{ _Player.SetGold(_Player.GetGold() + _Monster.GetGold()); }

		printf_s("\n���� ����"); 
		printf_s("\n%d Gold �� ȹ���Ͽ����ϴ�!", _Monster.GetGold());
		{ int break_point = _getch(); }

		return true;
	}

	{ char break_point = _getch(); }
	system("cls");

	return false;
}

void FightZone::In(Player& _Player)
{
	NewMonster.SetName("Monster");
	NewMonster.SetMinAtt(5);
	NewMonster.SetMaxAtt(10);
	NewMonster.SetMaxHp(50);
	NewMonster.SetHp(NewMonster.GetMaxHp());

	while (true)
	{
		bool IsEnd = false;
		
		system("cls");

		_Player.StatusRender();
		NewMonster.StatusRender();

		// ���� �İ��� ���� ����
		// ���ǿ� ����

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

		if (true == IsEnd) { return; }
	}
}