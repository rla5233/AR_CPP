#include "FightUnit.h"
#include <iostream>

FightUnit::FightUnit()
{}

void FightUnit::DamageLogic(const FightUnit& _Unit)
{
	Hp -= _Unit.MinAtt;
}

void FightUnit::DamageRender()
{
	printf_s("%s �� %d~%d�� ���ݷ����� �����߽��ϴ�.\n", Name, MinAtt, MaxAtt);
}