﻿// 020_For.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // while문인데
    // 어떠한 변수를 초기화하는 초기화문과
    // 그 변수를 증감시키는 증감문이 합쳐진 형태

    for (
        int i = 0;  // 초기화문
        i < 10;     // 조건문
        i++         // 증감문
        )
    {
        // 실행 코드
        putchar('A');
    }

    // 초기화문
    // 조건문 (참)
    // 실행코드
    // 증감문
    // 조건문 (참)
    // 실행코드
    // 증감문
    // ...
    // 조건문 (거짓)
    // for문 종료
}