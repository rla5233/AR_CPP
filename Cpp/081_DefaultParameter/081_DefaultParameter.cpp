// 081_DefaultParameter.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 함수의 매개변수의 default 값을 지정할 수 있다. 
int Func1(int _Value = 1)
{
	return _Value * 3;
}

// 선언쪽에만 디폴트 인자를 넣어 줄 수 있다.
int Func2(int _Value = 2);

// 디폴트 인자는 가장 우측부터 채워넣는다.
int Func3(int _Value1, int _Value2 = 2);

int main()
{
	// 그래서 이렇게 호출 할 수 도 있다.
	int a = Func1();
}

int Func2(int _Value)
{
	return _Value * 3;
}

int Func3(int _Value1, int _Value2)
{
	return _Value1 * _Value2;
}
