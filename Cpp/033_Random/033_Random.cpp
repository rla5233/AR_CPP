// 033_Random.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 난수의 시드벨류
int Random = 0;

void SeedChange(int _Value) // srand 
{
    Random = _Value;
}

int Randomint() // rand
{
    return ++Random;
}

int main()
{
    int Value = 0;

    __int64 Address = reinterpret_cast<__int64>(&Value);
    
    // 난수 : 정의되지 않은 수가 나오는 것
    // 특정 공식에 의해 어떠한 수를 변형시킨 수가 나오는 것

    // C 스타일 난수
    // rand()의 초기값(시드벨류)을 바꿔주는 역할
    // 매번 바뀌는 값을 넣어야 한다. ex) 시간
    // 처음 한번만 넣어주면 된다.
    srand(Address);

    for (size_t i = 0; i < 5; i++)
    {
        int Number = rand();
        printf_s("%d\n", Number);
    }
    
}