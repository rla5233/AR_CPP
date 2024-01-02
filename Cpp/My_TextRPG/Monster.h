#pragma once
#include "FightUnit.h"

class Monster : public FightUnit
{
public:
	Monster();

	void Init(int _MaxHp, int _MinAtt, int _MaxAtt, int _Exp) override;

	void FightEnd(FightUnit& _Player) override;
	void FightStart(FightUnit& _Unit) override;

	void RandomGoldSet(int _Min, int _Max) override;
};

