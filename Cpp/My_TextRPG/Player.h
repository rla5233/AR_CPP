#pragma once
#include "FightUnit.h"
#include "Weapon.h"

class Player : public FightUnit
{
public:
	Player();

	void SetGold(int _Gold);

protected:
	void RandomSetAtt() override;

public:
	Weapon m_NewWeapon = Weapon();

};

