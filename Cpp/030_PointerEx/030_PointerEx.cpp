// 030_PointerEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{

    // 0b00000000 00000000 00000000 00000001
    
    // 100번지
    int Value = 1;
    
    // 150번지에 있는 100번지
    char** Ptr = reinterpret_cast<char**>(&Value);
    char* Ptr2 = reinterpret_cast<char*>(Ptr);
    int* Ptr3 = reinterpret_cast<int*>(Ptr);

    *Ptr3 = 20;

    __int64 Address = reinterpret_cast<__int64>(Ptr);



}