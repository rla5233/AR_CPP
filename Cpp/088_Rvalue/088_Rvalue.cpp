// 088_Rvalue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class Test
{
public:
	int* NewValue = nullptr;

	Test()
	{
		NewValue = new int();
	}

	~Test()
	{
		if (NewValue != nullptr)
		{
			delete NewValue;
			NewValue = nullptr;
		}
	}

	Test(Test&& _Other) noexcept
	{

	}


	Test(const Test& _Other)
	{
		if (nullptr != NewValue)
		{
			delete NewValue;
			NewValue = nullptr;
		}

		NewValue = new int;
		*(NewValue) = *(_Other.NewValue);
	}
	
	// 일반 복사 대입연산자의 경우 동적할당에 대해
	// 지우고 다시만드는건 너무 비효율적이다.
	// 얕은 복사가 이득이다.
	void operator=(const Test& _Other)
	{
		if (NewValue != nullptr)
		{
			delete NewValue;
			NewValue = nullptr;
		}

		NewValue = new int;
		*(NewValue) = *(_Other.NewValue);		
	}


	// Rvalue 대입연산자, 생성자는 다음과 같이 만들 수 있다.
	// 컴파일러가 알아서 선택한다.
	void operator=(Test&& _Other) noexcept // noexcept : trycatch 하지 말아라 여기서 처리하지 못하면 터뜨려라
	{
		if (NewValue != nullptr)
		{
			delete NewValue;
			NewValue = nullptr;
		}

		NewValue = _Other.NewValue;
		_Other.NewValue = nullptr;
	}

};


Test CreateTest()
{
	Test NewTest;


	// 반환(복사) 후 파괴된다.
	return NewTest;
}


int main()
{
	Test MainTest0 = Test();
	Test MainTest1 = Test();

	MainTest0 = CreateTest();
	MainTest1 = CreateTest();
}