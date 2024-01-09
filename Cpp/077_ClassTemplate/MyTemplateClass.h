#pragma once
#include <iostream>

template<typename ValueType>
class MyTemplateClass
{
public:
	// 템플릿 클래스는 인자추론이 안되기 때문에
	// 일반적으로 헤더에 모든것을 구현한다.

	void Test()
	{
		std::cout << Value << std::endl;
	}
	
	ValueType Value;
};

