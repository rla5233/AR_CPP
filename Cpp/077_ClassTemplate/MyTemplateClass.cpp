#include "MyTemplateClass.h"

// ������ �ȵȴ�! (�����߷��� �ȵǱ� ����)
//void MyTemplateClass::Test()
//{
//	std::cout << Value << std::endl;
//}

// ���ڸ� ������ָ� �����ϱ��ϴ�
// �ٵ� �̷��� ���ø��� ���� ������..?
void MyTemplateClass<int>::Test()
{
	std::cout << Value << std::endl;
}

void MyTemplateClass<bool>::Test()
{
	std::cout << Value << std::endl;
}