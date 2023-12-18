// 028_Variableargument.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int StringCount(const char* _Ptr)
{
    int count = 0;
    while (_Ptr[count])
    {
        ++count;
    }

    return count;
}

// 함수의 인자는 일반적으로 내가 정해준 개수만큼만 넣어줄수 있다.
// 많이 넣어줘도 에러, 적게 넣어줘도 에러
void MyPrintf(const char* const _Format, ...)
{
    int Number = StringCount(_Format);
    for (int i = 0; i < Number; i++)
    {
        char Ch = _Format[i];

        putchar(_Format[i]);
    }
}

// 가변인자란 
// 인자의 개수를 정하지 않고
// 내가 인자를 넣어주는 순간 이 함수를 지우고
// 그 인자 개수만큼의 함수를 만든다.
// 딱히 안쓴다 (위험하다)
void VarTest(...)
{

}

// 왜 8바이트씩 떨어져 있을까?
// C++의 기본자료형의 최대크기는 8바이트이다.
void VarTest1(int _Count, int _Check1, int _Check2)
{
    int* Ptr = &_Count;

    // 포인터의 더하기는
    // 내 현재위치 + sizeof(자료형) * 넣어준 정수
    // 100번지 + sizeof(int) * 2 -> 108
    // 100번지 + sizeof(int) * 2
}

void VarCountCheck(int _Count, ...)
{
    int* Ptr = &_Count;

    for (int i = 0; i < _Count; i++)
    {
        Ptr = Ptr + 2;
        int Value = *Ptr;
        int a = 0;
    }
}

int main()
{
    char Arr[10] = { 'a', 'a', 'a', 0,'a', 'a', 'a', 0 };

    MyPrintf(Arr);

    // ?????
    // 인자가 한계가 없어
    // 가변인자는 사용하는 순간 그 함수를 만들어내는게
    // 가변인자 함수이다.
    printf_s("");

    VarTest(1, 2, 3);


}