#pragma once
#include "ZoneBase.h"
#include "Monster.h"

class FightZone : ZoneBase
{
public:
	void In(class Player& _Player) override;

private:
	Monster NewMonster = Monster();

	// �ѹ��� ����
	// ����� ������ ������ �����ؾ� �մϴ�.
	bool FightLogic(FightUnit& _Left, FightUnit& _Right, FightUnit& _Top, FightUnit& _Bot);
};

