#pragma once
#include "NameUnit.h"

class Weapon : public NameUnit
{
public:
	void StatusRender();
	bool TryWeaponUp();
	void WeaponUpSuccess();
	void WeaponUpFail();

	inline void SetAtt(int _Att) { m_Att = _Att; }
	inline int GetAtt() const { return m_Att; }
	inline int GetUpProbability() const { return m_UpProbability; }
	inline int GetWeaponUpCost() const { return m_WeaponUpCost; }
	inline int GetLevel() const { return m_Level; }
	inline int GetMaxLevel() const { return m_MaxLevel; }

	
private:
	int m_Att = 5;
	int m_Level = 0;
	int m_MaxLevel = 30;
	int m_UpProbability = 75;
	int m_WeaponUpCost = 1;
};

