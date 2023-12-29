#pragma once
#include "StatusUnit.h"

class FightUnit : public StatusUnit
{
public:
	FightUnit();
	
	// Fight¿ë ÇÔ¼ö
	void DamageLogic(const FightUnit& _Unit);
	void DamageRender();

	void Hp_Recovery(int _HpValue);

	void virtual RandomSetAtt();
	
	void SetMinAtt(int _MinAtt);
	void SetMaxAtt(int _MaxAtt);
	void SetMaxHp(int _MaxHp);
	void SetHp(int _Hp);

	// Get
	inline bool IsDeath() const	{ return Hp <= 0; }
	inline int GetMaxHp() const { return Max_Hp; }
	inline int GetHp() const { return Hp; }
	inline int GetGold() const { return Gold; }

protected:

private:
};
