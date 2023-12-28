#include "FightUnit.h"
#include <iostream>

FightUnit::FightUnit()
{}

void FightUnit::SetMinAtt(int _MinAtt)
{
	Min_Att = _MinAtt;
}

void FightUnit::SetSizeAtt(int _SizeAtt)
{
	Size_Att = _SizeAtt;
}

void FightUnit::RandomSetAtt()
{
	Att = (rand() % Size_Att) + Min_Att;	
}

void FightUnit::DamageLogic(const FightUnit& _Unit)
{
	Hp -= _Unit.Att;

	if (Hp < 0)	{ Hp = 0; }
}

void FightUnit::DamageRender()
{
	printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", Name, Att);
}