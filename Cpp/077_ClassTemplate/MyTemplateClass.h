#pragma once
#include <iostream>

template<typename ValueType>
class MyTemplateClass
{
public:
	// ���ø� Ŭ������ �����߷��� �ȵǱ� ������
	// �Ϲ������� ����� ������ �����Ѵ�.

	void Test()
	{
		std::cout << Value << std::endl;
	}
	
	ValueType Value;
};

