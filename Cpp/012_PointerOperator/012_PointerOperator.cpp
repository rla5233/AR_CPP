// 012_PointerOperator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Damage(int* _Hp, int _Att)
{
    // 내가 가리키는 번지의 값에 접근하겠다.
    *_Hp = *_Hp - _Att;
}

int main()
{
    int MonsterHp = 200;
    // 위치 : 100번지
    // 크기 : 4바이트
    // 형태 : int
    // 값 : 200

    int* MonsterHpPtr = &MonsterHp;
    // 위치 : 120번지
    // 크기 : 8바이트
    // 형태 : int*
    // 값 : 100번지

    // int* -> int
    // 내가 가진 번지 값의 값이 된다.
   
    *MonsterHpPtr = 50;

    {
        int MonsterHp = 200;

        Damage(&MonsterHp, 20);
    }
}