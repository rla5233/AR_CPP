// 018_CharArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    'A';    // 문자 상수 표현식
    "AAA";  // 문자열 상수 표현식

    {
        // 일반적인 변수 -> 그냥 초기화
        int Arr[5] = { 1, 2, 3, 4, 5 };
    }

    // 문자열은 굉장히 예외가 많다.
    {
        // 마지막에 무조건 0(\0)을 넣어줘야 한다.
        char String0[5] = "AAAA";
        char String1[5] = { 'A', 'A', 'A', 'A', 0 };

        printf_s(String1);
    }
}