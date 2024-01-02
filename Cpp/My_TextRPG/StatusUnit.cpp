#include "StatusUnit.h"
#include <iostream>

void StatusUnit::Init(int _MaxHp, int _MinAtt, int _MaxAtt, int _Exp)
{

}

void StatusUnit::StatusRender()
{
	// 메모리에 관련된 명확한 설명은 안한 상태지만
	// 자신의 맴버함수에서 자신의 맴버변수는 자유롭게 사용이 가능합니다.
	int Size = printf_s("%s ", this->GetName());
	for (int i = 0; i < 50 - Size; i++)	{ printf_s("-"); }

	StatusRenderStart();
	StatusRenderBase();

	for (int i = 0; i < 50; i++) { printf_s("-"); }
	printf_s("\n");
}

void StatusUnit::StatusRenderStart()
{}

void StatusUnit::StatusRenderBase()
{
	printf_s("\n");
	printf_s("공격력 %d ~ %d\n", Min_Att, Max_Att);
	printf_s("체력 %d / %d\n", Hp, Max_Hp);
	printf_s("소지금 %d Gold\n", Gold);
}

void StatusUnit::StatusRenderEnd()
{}

void StatusUnit::SetHp(int _Hp)
{
	Hp = _Hp;

	if (Hp < 0) { Hp = 0; }
	else if (Hp > Max_Hp) { Hp = Max_Hp; }
}

void StatusUnit::RandomGoldSet(int _Min, int _Max)
{
	
}

int StatusUnit::RandomValue(int _Min, int _Max)
{
	return (rand() % (_Max - _Min) + _Min);
}
