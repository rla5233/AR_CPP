#pragma once
#include "ZoneBase.h"
#include "Monster.h"

class FightZone : ZoneBase
{
public:
	void In(class Player& _Player, int _Type);
	void FightZoneMenu(class Player& _Player);
	void CreateMonster(int _Type);

private:
	Monster NewMonster = Monster();

	// 한번의 전투
	// 선언과 구현은 완전히 동일해야 합니다.
	bool FightLogic(FightUnit& _Left, FightUnit& _Right, class Player& _Player, class Monster& _Monster);
};

