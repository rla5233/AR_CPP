#include "StatusUnit.h"
#include <iostream>

void StatusUnit::SetName(const char* _Name)
{
	int idx = 0;
	while (_Name[idx])
	{
		Name[idx] = _Name[idx];
		++idx;
	}
}

void StatusUnit::StatusRender()
{
	// �޸𸮿� ���õ� ��Ȯ�� ������ ���� ��������
	// �ڽ��� �ɹ��Լ����� �ڽ��� �ɹ������� �����Ӱ� ����� �����մϴ�.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	printf_s("���ݷ� %d\n", Att);
	printf_s("ü�� %d\n", Hp);

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}
