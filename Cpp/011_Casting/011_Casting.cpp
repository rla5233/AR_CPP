// 011_Casting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // 캐스팅이란?
    // 1. 자료형이 다르면 대입이 안되어야 한다!! -> 기본 생각.
    // -> 그냥 무조건 안되게 만들어야 했다.
    int Value = 0;
    //int* ValuePtr = Value; // 오류!
    // 2. 그러나 될때가 있고 안될때가 있다.
    // C & C++ 에서 자료형이 무슨의미야 -> 어차피 바이트 덩어리인데
    // 1바이트 문자형
    // 0b00000000
    // char
    // 1바이트 논리형
    // 0b00000000
    // bool
    
    // 대입이 된다!
    // 무슨일이 일어나는지 확실히 알아야한다!
    __int64 int64 = 1000000000000;
    int int32 = 0;
    int32 = int64; // 이건 그냥 됐다 그러나 자료의 변형이 일어났다.

    // 일반적인 자료형은 정식적인 캐스팅이라는 것을 통해서 변경해야 한다.
    // 암시적(묵시적)형변환 : 컴파일러가 자동으로 수행하는 타입 변환
    // 암시적(묵시적)형변환은 최대한 피한다.

    // 명시적 형변환 : 사용자가 강제적으로 수행하는 형 변환
    // C스타일 캐스팅 방식
    {
        // C스타일 형변환
        int Value = 100;
        bool Check = (bool)Value;
        Value = (int)Check;
    }

    // C++ 에는 참조형과 값형이 있다.
    // 일반적인 변수 : 값형
    // 포인터, 레퍼런스 : 참조형
    // C++ 스타일에서 값 <-> 값 형변환 (바이트 크기만 다른)
    {
        int Value = 100;
        bool Check = static_cast<bool>(Value);
        Value = static_cast<int>(Check);
    }    

    // 참조 <-> 값
    {
        int Value = 100;
        int* Ptr = &Value;

        __int64 Address = reinterpret_cast<__int64>(Ptr);
    }
}