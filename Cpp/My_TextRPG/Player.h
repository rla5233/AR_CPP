#pragma once
#include "FightUnit.h"
#include "Weapon.h"

class Player : public FightUnit
{
public:
	Player();

protected:
	void RandomSetAtt() override;

public:
	Weapon m_NewWeapon = Weapon();

};

