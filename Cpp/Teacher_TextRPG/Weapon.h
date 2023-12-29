#pragma once
#include "NameUnit.h"

class Weapon : public NameUnit
{
public:
	inline int GetAtt() const
	{
		return Att;
	}

	inline void SetAtt(int _Att)
	{
		Att = _Att;
	}

private:
	int EquipUp = 0;
	int Att;
};

