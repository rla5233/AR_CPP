#include "FightUnit.h"
#include <iostream>

FightUnit::FightUnit()
{}

void FightUnit::SetMinAtt(int _MinAtt) { Min_Att = _MinAtt; }
void FightUnit::SetMaxAtt(int _MaxAtt) { Max_Att = _MaxAtt; }
void FightUnit::SetMaxHp(int _MaxHp) { Max_Hp = _MaxHp; }
void FightUnit::SetHp(int _Hp) 
{ 
	Hp = _Hp;
	
	if(Hp < 0) { Hp = 0; }
	else if (Hp > Max_Hp) {	Hp = Max_Hp; }
}
void FightUnit::SetAtt(int _Att) { Att = _Att; }
void FightUnit::RandomSetAtt(){	Att = (rand() % (Max_Att - Min_Att)) + Min_Att; }

void FightUnit::DamageLogic(const FightUnit& _Unit)
{
	Hp -= _Unit.Att;
	if (Hp < 0)	{ Hp = 0; }
}

void FightUnit::DamageRender()
{
	printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", this->GetName(), Att);
}

void FightUnit::Hp_Recovery(int _HpValue)
{
	SetHp(Hp + _HpValue);
}
