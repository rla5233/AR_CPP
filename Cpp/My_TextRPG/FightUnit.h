#pragma once
#include "StatusUnit.h"

class FightUnit : public StatusUnit
{
public:
	FightUnit();

	virtual void Init(int _MaxHp, int _MinAtt, int _MaxAtt, int _Exp);
	
	// Fight¿ë ÇÔ¼ö
	void DamageLogic(const FightUnit& _Unit);
	void DamageRender();
	virtual void FightStart(FightUnit& _Unit);
	virtual void FightEnd(FightUnit& _Other);

	void Hp_Recovery(int _HpValue);
	void virtual RandomSetAtt();
	


	// Get
	inline bool IsDeath() const	{ return Hp <= 0; }
	inline int GetMaxHp() const { return Max_Hp; }
	inline int GetMinAtt() const { return Min_Att; }
	inline int GetHp() const { return Hp; }
	inline int GetGold() const { return Gold; }
	inline int GetExp() const { return Exp; }

protected:

private:
};
