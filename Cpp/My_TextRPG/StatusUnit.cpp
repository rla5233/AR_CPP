#include "StatusUnit.h"
#include <iostream>

void StatusUnit::Init(int _MaxHp, int _MinAtt, int _MaxAtt, int _Exp)
{

}

void StatusUnit::StatusRender()
{
	// �޸𸮿� ���õ� ��Ȯ�� ������ ���� ��������
	// �ڽ��� �ɹ��Լ����� �ڽ��� �ɹ������� �����Ӱ� ����� �����մϴ�.
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
	printf_s("���ݷ� %d ~ %d\n", Min_Att, Max_Att);
	printf_s("ü�� %d / %d\n", Hp, Max_Hp);
	printf_s("������ %d Gold\n", Gold);
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
