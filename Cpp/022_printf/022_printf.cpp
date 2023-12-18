// 022_printf.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 컴파일러의 판단하에
// 이걸 그대로 복사해서 넣을수 있다면
// 이 함수가 실행된 위치에 이 함수의 내용을 복사하고
// 함수자체는 지워버린다.
// inline -> 치환 해줄수 있니?
inline int /*_cdecl*/ Test()
{
    return 1 + 1;
}

int main()
{
    // printf는 C에서 사용하던 출력 함수
    // 내부 내용이 C스타일로 짜여져 있다.

    // extern "C"                   : 이 부분을 컴파일 C스타일로 컴파일 해줘.
    // inline                       : 함수를 치환 해줄수 있나?
    // int                          : 리턴값
    // __cdecl                      : 함수 호출 규약
    // printf                       : 함수 이름
    // (    
    // const char* _Format,         : const - 수정 할 수 없다!
    // ...                          : 가변인자
    // );

    int a = printf_s("123");

    int b = 0;
}