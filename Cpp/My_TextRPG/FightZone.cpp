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
		printf_s("\n전투 종료");

		if (_Monster.IsDeath())
		{
			_Player.SetGold(_Player.GetGold() + _Monster.GetGold());
			printf_s("\n전투에서 승리하였습니다!");
			printf_s("\n%d Gold 를 획득하였습니다!", _Monster.GetGold());
		}
		else
		{
			printf_s("\n전투에서 패배하였습니다.");
		}

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
		printf_s("\n전투 종료"); 

		if (_Monster.IsDeath())	
		{ 
			_Player.SetGold(_Player.GetGold() + _Monster.GetGold()); 
			printf_s("\n전투에서 승리하였습니다!");
			printf_s("\n%d Gold 를 획득하였습니다!", _Monster.GetGold());
		}
		else
		{
			printf_s("\n전투에서 패배하였습니다.");
		}

		{ char break_point = _getch(); }

		return true;
	}

	{ char break_point = _getch(); }
	system("cls");

	return false;
}

void FightZone::In(Player& _Player, int _Type)
{
	MonsterSetting(_Type);

	while (true)
	{
		bool IsEnd = false;
		
		system("cls");

		_Player.StatusRender();
		NewMonster.StatusRender();

		// 선공 후공이 결정 나고
		// 조건에 따라서

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

		if (true == IsEnd) { return; }
	}
}

void FightZone::FightZoneMenu(class Player& _Player)
{
	FightZone NewFightZone = FightZone();

	while (true)
	{
		system("cls");

		_Player.StatusRender();
		printf_s("어느 사냥터로 가시겠습니다.\n");
		printf_s("1. 초급 사냥터.\n");
		printf_s("2. 중급 사냥터.\n");
		printf_s("3. 고급 사냥터.\n");
		printf_s("4. 나가기.\n");
		char Input = _getch();

		switch (Input)
		{
			case '1':
			{
				NewFightZone.In(_Player, 1);
				break;
			}
			case '2':
			{
				NewFightZone.In(_Player, 2);
				break;
			}
			case '3':
			{
				NewFightZone.In(_Player, 3);
				break;
			}
			case '4':
			{
				return;
			}
		}
	}
}

void FightZone::MonsterSetting(int _Type)
{
	switch (_Type)
	{
		case 1 :
		{
			NewMonster.SetMinAtt(5);
			NewMonster.SetMaxAtt(15);
			NewMonster.SetMaxHp(100);

			break;
		}
		case 2:
		{
			NewMonster.SetMinAtt(10);
			NewMonster.SetMaxAtt(20);
			NewMonster.SetMaxHp(200);

			break;
		}
		case 3:
		{
			NewMonster.SetMinAtt(20);
			NewMonster.SetMaxAtt(40);
			NewMonster.SetMaxHp(300);

			break;
		}
	}

	NewMonster.SetName("Monster");
	NewMonster.SetHp(NewMonster.GetMaxHp());
	NewMonster.SetAtt(NewMonster.GetMinAtt());
}
