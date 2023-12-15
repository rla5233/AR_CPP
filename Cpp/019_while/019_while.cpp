// 019_while.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 함수의 인자로 정적배열을 쓸 수 없다.
// 정적배열 -> int Arr[10] -> 상수로 배열의 크기가 정해진 배열
void MyPrintf(char* _Ptr)
{
    int count = 0;

    // char CurCh = *(_Ptr + 0);
    // char CurCh =  _Ptr[0];

    while (_Ptr[count])
    {
        char ch = _Ptr[count];
        putchar(static_cast<int>(ch));
        count++;
    }
}

int main()
{
    {
        char String0[5] = "AAAA";
        char String1[5] = { 'A', 'A', 'A', 'A', 0 };

        
        // while(메모리영역) <---- 조건문
        // {
        //      실행코드
        // }
        //
        // 조건문으로 들어가서 메모리영역의 조건이 참이라면
        // 실행코드를 1번 실행하고 다시 조건문으로 들어간다.
        //

        int count = 5;
        while (count)
        {
            putchar('A');
            count--;
        }
        std::cout << std::endl;

        count = 0;
        while (String0[count])
        {
            putchar(static_cast<int>(String0[count]));
            count++;
        }
        std::cout << std::endl;

        {
            char string[5] = "AAAA";
            MyPrintf(string);
        }
    }

    // do
    // {
    //      실행코드
    // } while(메모리영역)
    // 
    // 어떤 실행코드든 최초에 1번은 실행되기를 원한다면
    // do while문을 쓸 수 있다.
    {

    }
}