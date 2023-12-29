#pragma once
#include "NameUnit.h"

class StatusUnit : public NameUnit
{
public:
	void StatusRender();	

protected:
	int Hp = 100;
	int Att = 10;
	int Gold = 0;

	int Min_Att = 0;
	int Size_Att = 10;
};

