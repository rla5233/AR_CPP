#pragma once
#include "NameUnit.h"

class Weapon : public NameUnit
{
public:
	inline void SetAtt(int _Att) { m_Att = _Att; }
	inline int GetAtt() const { return m_Att; }

private:
	int m_Att = 5;
};

