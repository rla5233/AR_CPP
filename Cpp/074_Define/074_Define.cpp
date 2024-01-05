// 074_Define.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
#include <assert.h>

// #include "파일명" -> 파일 치환
// // -> 주석은 메모기능
//

// 코드 치환 define
#define TEN 10

// define 매크로 함수
#define PLUS(Value) Value + Value

// 요새는 뒤처진 문법 많이 사용하면 안되는 문법으로 통한다.
// 남발하면 실수의 여지가 있다.

#define MsgAssert(TEXT) MessageBoxA(nullptr, TEXT, "Error", MB_OK); assert(false);

int main()
{
    {
        int Value = TEN;
    }

    {
        int Value = PLUS(20);
    }    

    {
        MsgAssert("에러.")
    }
}