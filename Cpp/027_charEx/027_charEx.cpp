﻿// 027_charEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // 문자 표현 방식
    // abcde ㄱㄴㄷㄹㅁ -> 인간이 보기 편하게 만든
    //                    디스플레이적인 내용일 뿐이다.
    //                    글자에 대한 모든 권한은 
    //                    OS가 가지고 있다.
    //                    그리고 우리가 char을 사용한다고 하면
    //                    C++ 운영체제에게
    //                    이거 글자로 보여줘야해 알려주는것이다.
    //                    어떠한 메모리영역을 글자로 바꿔주는 것임.
    //                    메모리 영역 = 바이트(8비트)로 이루어진 램안의 특정 메모리 상태
    //                               -> 그건 결국 2진수 일뿐이다.
    //                    글자 => 숫자 => 정수
    //
    {
        char Ch = 'A'; // 정수 65

        char Arr[10] = "12321";

        char Number = Arr[0]; // 정수 49
        Number = '0'; // 정수 48

        int iNumber = '1' - '0';
    }
}