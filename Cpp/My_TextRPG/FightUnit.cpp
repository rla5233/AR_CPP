#include "FightUnit.h"
#include <iostream>

FightUnit::FightUnit()
{}

void FightUnit::Init(int _MaxHp, int _MinAtt, int _MaxAtt, int _Exp)
{}

void FightUnit::DamageLogic(const FightUnit& _Unit)
{
	Hp -= _Unit.Att;
	if (Hp < 0)	{ Hp = 0; }
}

void FightUnit::DamageRender()
{
	printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", this->GetName(), Att);
}

void FightUnit::FightStart(FightUnit& _Unit)
{}

void FightUnit::FightEnd(FightUnit& _Other)
{
}

void FightUnit::Hp_Recovery(int _HpValue)
{
	SetHp(Hp + _HpValue);
}

void FightUnit::RandomSetAtt()
{
	Att = (rand() % (Max_Att - Min_Att)) + Min_Att;
}
