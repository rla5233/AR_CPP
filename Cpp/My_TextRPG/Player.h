#pragma once
#include "FightUnit.h"
#include "Weapon.h"

class Player : public FightUnit
{
public:
	Player();

	void Init(int _MaxHp, int _MinAtt, int _MaxAtt, int _LevelUpExp) override;
	void StatusRenderStart() override;
	void StatusRenderBase() override;

	void FightStart(FightUnit& _Player) override;
	void FightEnd(FightUnit& _Other) override;

	void LevelUpCheck();
	inline void SetLevelUpExp(int _LevelUpExp) { LevelUpExp = _LevelUpExp; };

	void SetGold(int _Gold);
	void RandomSetAtt() override;

public:
	Weapon m_NewWeapon = Weapon();

private:
	int Level = 1;
	int LevelUpExp = 0;
};

