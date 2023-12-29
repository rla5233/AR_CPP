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
		printf_s("�������� ������ �Ͻðڽ��ϱ�?\n");
		printf_s("1. ��ȭ.\n");
		printf_s("2. �޽�.\n");
		printf_s("3. ������.\n");
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

		printf_s("���⸦ ��ȭ�Ͻðڽ��ϱ�? (��ȭ��� : %d Gold, ������ : %d Gold)\n", _Player.m_NewWeapon.GetWeaponUpCost(), _Player.GetGold());
		printf_s("(���� ��ȭ Ȯ�� : %d%%)\n", _Player.m_NewWeapon.GetUpProbability());
		printf_s("1. ��.\n");
		printf_s("2. �ƴϿ�.\n");

		char Input = _getch();
		switch (Input)
		{
			case '1':
			{
				if (_Player.GetGold() < _Player.m_NewWeapon.GetWeaponUpCost())
				{
					printf_s("\nGold�� �����մϴ�!");
					break;
				}

				_Player.SetGold(_Player.GetGold() - _Player.m_NewWeapon.GetWeaponUpCost());
				bool IsUp = _Player.m_NewWeapon.TryWeaponUp();
				
				if (IsUp)
				{
					system("cls");

					_Player.m_NewWeapon.StatusRender();

					printf_s("���⸦ ��ȭ�Ͻðڽ��ϱ�? (��ȭ��� : %d Gold, ������ : %d Gold)\n", _Player.m_NewWeapon.GetWeaponUpCost(), _Player.GetGold());
					printf_s("(���� ��ȭ Ȯ�� : %d%%)\n", _Player.m_NewWeapon.GetUpProbability());
					printf_s("1. ��.\n");
					printf_s("2. �ƴϿ�.\n");
					printf_s("\n��ȭ�� �����߽��ϴ�!!\n");
				}
				else
				{
					system("cls");

					_Player.m_NewWeapon.StatusRender();

					printf_s("���⸦ ��ȭ�Ͻðڽ��ϱ�? (��ȭ��� : %d Gold, ������ : %d Gold)\n", _Player.m_NewWeapon.GetWeaponUpCost(), _Player.GetGold());
					printf_s("(���� ��ȭ Ȯ�� : %d%%)\n", _Player.m_NewWeapon.GetUpProbability());
					printf_s("1. ��.\n");
					printf_s("2. �ƴϿ�.\n");
					printf_s("\n��ȭ�� �����߽��ϴ�!!\n");
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

	printf("\n�޽��Ͽ� ü���� %d ȸ���Ǿ����ϴ�!", Hp_RecoveryValue);
	{
		char break_point = _getch();
	}	
}