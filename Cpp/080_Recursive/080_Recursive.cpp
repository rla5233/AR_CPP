// 080_Recursive.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Test(int& _Data)
{
    std::cout << _Data << std::endl;
    ++_Data;

    // 어떤 함수가 자신과 완전히 동일한 함수를 내부에서
    // 다시 실행하는 것을 재귀함수라고 한다.0
    Test(_Data);
}

int main()
{
    int Value = 0;
    Test(Value);
}