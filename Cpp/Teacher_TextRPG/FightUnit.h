#pragma once
#include "StatusUnit.h"

class FightUnit : public StatusUnit
{
public:
	FightUnit();

	// Get
	inline bool IsDeath() const
	{
		return Hp <= 0;
	}

	inline int GetMinAtt() const
	{
		return MinAtt;
	}

	// Fight�� �Լ�
	void DamageLogic(const FightUnit& _Unit);

	void DamageRender();

protected:

private:
};
