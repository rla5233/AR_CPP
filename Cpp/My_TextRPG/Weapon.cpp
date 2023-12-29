#include "Weapon.h"
#include <iostream>

void Weapon::StatusRender()
{
	int Size = printf_s("%s (+ %d강) ", GetName(), m_Level);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	printf_s("공격력 증가량 %d\n", m_Att);

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}

bool Weapon::TryWeaponUp()
{
	int RandomValue = (rand() % 100) + 1;

	if (RandomValue <= m_UpProbability)
	{
		WeaponUpSuccess();
		return true;
	}
	else
	{
		WeaponUpFail();
		return false;
	}

}

void Weapon::WeaponUpSuccess()
{
	++m_Level;
	++m_Att;
}

void Weapon::WeaponUpFail()
{
	if (m_Level > 10 && m_Level < 20)
	{
		m_Level -= 5;
		m_Att -= 5;
	}
	else if (m_Level >= 20)
	{
		m_Level = 0;
		m_Att = 5;
	}
}
