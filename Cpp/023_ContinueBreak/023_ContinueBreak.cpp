// 023_ContinueBreak.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // for문이나 while문 안에서 break 구문을 사용할 수 있다.
    // 즉시 반복문을 종료하라는 의미이다.
    
    {
        int count = 0;
        while (true)
        {
            ++count;

            if (10 < count)
            {
                break; // 즉시 반복문 종료
            }
        }
    }

    {
        int Hp = 100;
        for (int i = 0; i < 5; i++)
        {
            Hp -= 80;
            if (Hp <= 0)
            {
                break; // 즉시 반복문 종료
            }
        }
    }

    // for문이나 while문 안에서 continue 구문을 사용할 수 있다.
    {
        for (int i = 0; i < 100; i++)
        {
            if (i % 2 != 0)
            {
                continue; // 곧바로 증감문으로 이동
            }

            // i가 짝수일때만 뭔가를 하고 싶어
            int a = 1;
        }
    }

    {
        int Value = 0;

        while (Value < 100)
        {
            ++Value;
            if (Value % 2 != 0)
            {
                continue; // 곧바로 조건문으로 이동
            }

            // Value가 짝수일때만 뭔가를 하고 싶어
            int a = Value;
        }
    }
}