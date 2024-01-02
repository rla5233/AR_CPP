#include "Monster.h"
#include <iostream>

Monster::Monster()
{
}

void Monster::Init(int _MaxHp, int _MinAtt, int _MaxAtt, int _Exp)
{
	SetName("Monster");
	SetMinAtt(_MinAtt);
	SetMaxAtt(_MaxAtt);
	SetMaxHp(_MaxHp);
	SetHp(_MaxHp);
	SetAtt(_MinAtt);
	SetExp(_Exp);
}


void Monster::FightEnd(FightUnit& _Player)
{
}

void Monster::FightStart(FightUnit& _Unit)
{
	HpReset();
	RandomGoldSet(100, 200);
}

void Monster::RandomGoldSet(int _Min, int _Max)
{
	Gold = (rand() % (_Max - _Min)) + _Min;
}
