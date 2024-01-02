#pragma once
#include "NameUnit.h"

class StatusUnit : public NameUnit
{
public:
	virtual void Init(int _MaxHp, int _MinAtt, int _MaxAtt, int _Exp);

	void StatusRender();	

	virtual void StatusRenderStart();
	virtual void StatusRenderBase();
	virtual void StatusRenderEnd();

	inline void SetMinAtt(int _MinAtt) { Min_Att = _MinAtt; }
	inline void SetMaxAtt(int _MaxAtt) { Max_Att = _MaxAtt; }
	inline void SetMaxHp(int _MaxHp) { Max_Hp = _MaxHp; }
	inline void SetAtt(int _Att) { Att = _Att; }
	inline void SetExp(int _Exp) { Exp = _Exp; }
	void SetHp(int _Hp);

	inline void HpReset() { Hp = Max_Hp; }
	virtual void RandomGoldSet(int _Min, int _Max);
	int RandomValue(int _Min, int _Max);

protected:
	int Hp = 100;
	int Att = 10;
	int Gold = 0;
	int Exp = 0;

	int Min_Att = 0;
	int Max_Att = 10;
	int Max_Hp = 100;
};

