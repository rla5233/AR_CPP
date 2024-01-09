#include "MyTemplateClass.h"

// 구현이 안된다! (인자추론이 안되기 때문)
//void MyTemplateClass::Test()
//{
//	std::cout << Value << std::endl;
//}

// 인자를 명시해주면 가능하긴하다
// 근데 이러면 템플릿을 쓰는 이유가..?
void MyTemplateClass<int>::Test()
{
	std::cout << Value << std::endl;
}

void MyTemplateClass<bool>::Test()
{
	std::cout << Value << std::endl;
}