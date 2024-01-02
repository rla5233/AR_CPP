#pragma once
#include "ZoneBase.h"
#include "Monster.h"

class FightZone : ZoneBase
{
public:
	void In(class Player& _Player, int _Type);
	void FightZoneMenu(class Player& _Player);
	void MonsterSetting(int _Type);

private:
	Monster NewMonster = Monster();

	// �ѹ��� ����
	// ����� ������ ������ �����ؾ� �մϴ�.
	bool FightLogic(FightUnit& _Left, FightUnit& _Right, class Player& _Player, class Monster& _Monster);
};

