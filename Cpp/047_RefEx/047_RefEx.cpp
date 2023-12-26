// 047_RefEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test
{
public:
	// 이런식으로 클래스 내부에 레퍼런스가 있다면

	// 레퍼런스는 무조건 초기화를 피할수가 없다.
	// 즉 int&를 사용했다면 int가 하나 필요한것과 같다.
	// 리터럴 초기화는 불가능에 가깝다.
	
	// 이런 초기화는 의미없는 멍청한 코드이다.
	int Value = 0;
	int& Ref = Value;

	// 포인터는 리터럴 초기화가 가능하다.
	int* Ptr = nullptr;

public:
	// 레퍼런스는 다음과 같이 클래스 생성시
	// 초기화 할 수 있다.
	Test(int& _Ref)
		: Ref(_Ref)
	{

	}

};

int main()
{
	{
		int Value0 = 0;
		// 레퍼런스는 무조건 초기화 해야한다.
		// 즉 int&를 사용했다면 int가 하나 필요한것이다.
		int& Ref = Value0;

		// 또한 레퍼런스는 가리키는(참조) 대상이 바뀌지 않는다.
		int Value1 = 2;
		Ref = Value1;

		Ref = 50;
	}

	// 생성자를 이용해 초기화 할 수 있긴하다.
	{
		int Value = 0;
		Test NewTest = Test(Value);
	}
}