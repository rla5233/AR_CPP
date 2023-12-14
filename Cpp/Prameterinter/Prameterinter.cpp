// Prameterinter.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

// 기본적으로 함수의 인자는 -> 지역변수
// 지역변수와 약간 다른점이 있다.
void Test(int _Value0, int _Value1, int _Value2, int _Value3)
{
    __int64 Address0 = reinterpret_cast<__int64>(&_Value0);
    __int64 Address1 = reinterpret_cast<__int64>(&_Value1);
    __int64 Address2 = reinterpret_cast<__int64>(&_Value2);
    __int64 Address3 = reinterpret_cast<__int64>(&_Value3);

    // 8바이트씩 떨어져있음. 
    // -> 가장 큰 기본자료형이 8바이트이기 떄문이다!
    // -> 함수의 매개변수는 선형구조이다!
    cout << Address0 << endl;
    cout << Address1 << endl;
    cout << Address2 << endl;
    cout << Address3 << endl;
}

int main()
{
    int Value0 = 0;
    int Value1 = 1;
    int Value2 = 2;
    int Value3 = 3;

    Test(Value0, Value1, Value2, Value3);

    return 0;
}