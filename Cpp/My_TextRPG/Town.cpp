#include "Town.h"
#include <iostream>
#include <conio.h>

#include "Player.h"

void Town::In(Player& _Player)
{
	while (true)
	{
		system("cls");

		_Player.StatusRender();
		printf_s("마을에서 무엇을 하시겠습니까?\n");
		printf_s("1. 강화.\n");
		printf_s("2. 휴식.\n");
		printf_s("3. 나가기.\n");
		char Input = _getch();

		switch (Input)
		{
			case '1':
			{
				WeaponUp(_Player);
				break;
			}
			case '2':
			{
				Rest(_Player);
				break;
			}
			case '3':
			{
				return;
			}
		}		
	}
}

void Town::WeaponUp(Player& _Player)
{
	while (true)
	{
		system("cls");

		_Player.m_NewWeapon.StatusRender();

		printf_s("무기를 강화하시겠습니까? (강화비용 : %d Gold, 소지금 : %d Gold)\n", _Player.m_NewWeapon.GetWeaponUpCost(), _Player.GetGold());
		printf_s("(현재 강화 확률 : %d%%)\n", _Player.m_NewWeapon.GetUpProbability());
		printf_s("1. 네.\n");
		printf_s("2. 아니오.\n");

		char Input = _getch();
		switch (Input)
		{
			case '1':
			{
				if (_Player.GetGold() < _Player.m_NewWeapon.GetWeaponUpCost())
				{
					printf_s("\nGold가 부족합니다!");
					break;
				}

				_Player.SetGold(_Player.GetGold() - _Player.m_NewWeapon.GetWeaponUpCost());
				bool IsUp = _Player.m_NewWeapon.TryWeaponUp();
				
				if (IsUp)
				{
					system("cls");

					_Player.m_NewWeapon.StatusRender();

					printf_s("무기를 강화하시겠습니까? (강화비용 : %d Gold, 소지금 : %d Gold)\n", _Player.m_NewWeapon.GetWeaponUpCost(), _Player.GetGold());
					printf_s("(현재 강화 확률 : %d%%)\n", _Player.m_NewWeapon.GetUpProbability());
					printf_s("1. 네.\n");
					printf_s("2. 아니오.\n");
					printf_s("\n강화에 성공했습니다!!\n");
				}
				else
				{
					system("cls");

					_Player.m_NewWeapon.StatusRender();

					printf_s("무기를 강화하시겠습니까? (강화비용 : %d Gold, 소지금 : %d Gold)\n", _Player.m_NewWeapon.GetWeaponUpCost(), _Player.GetGold());
					printf_s("(현재 강화 확률 : %d%%)\n", _Player.m_NewWeapon.GetUpProbability());
					printf_s("1. 네.\n");
					printf_s("2. 아니오.\n");
					printf_s("\n강화에 실패했습니다!!\n");
				}

				break;
			}
			case '2':
			{
				return;
			}
		}

		{
			char break_point = _getch();
		}
	}
}

void Town::Rest(Player& _Player)
{
	int Hp_RecoveryValue = _Player.GetMaxHp() - _Player.GetHp() <= 50 ? _Player.GetMaxHp() - _Player.GetHp() : 50;
	
	_Player.Hp_Recovery(Hp_RecoveryValue);

	printf("\n휴식하여 체력이 %d 회복되었습니다!", Hp_RecoveryValue);
	{
		char break_point = _getch();
	}	
}