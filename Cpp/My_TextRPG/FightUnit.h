#pragma once
#include "StatusUnit.h"

class FightUnit : public StatusUnit
{
public:
	FightUnit();
	
	void SetMinAtt(int _MinAtt);
	void SetSizeAtt(int _SizeAtt);
	void virtual RandomSetAtt();

	// Get
	inline bool IsDeath() const	{ return Hp <= 0; }

	// Fight¿ë ÇÔ¼ö
	void DamageLogic(const FightUnit& _Unit);
	void DamageRender();

protected:

private:
};
