// 080_Recursive.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Test(int& _Data)
{
    if (_Data > 100)
    {
        // 종료되는 시점을 반드시 만들어줘야 한다.
        return;
    }


    std::cout << _Data << std::endl;
    ++_Data;

    // 어떤 함수가 자신과 완전히 동일한 함수를 내부에서
    // 다시 실행하는 것을 재귀함수라고 한다.
    Test(_Data);
}

bool Func(int _Data)
{
    if (_Data < 0)
    {
        return true;
    }
    else
    {
        // 리턴과 동시에 재귀를 하는것을 꼬리 재귀라고 한다.
        // 컴파일러가 가능한다면 while문 형식으로 바꿔버린다.
        // inline이랑 비슷하게 생각하면 된다.
        return Func(_Data - 1);
    }
}

int main()
{
    int Value = 0;
    Test(Value);

    Func(10);
}