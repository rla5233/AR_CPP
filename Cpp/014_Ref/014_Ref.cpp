// 014_Ref.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void DamagePtr(int* _Hp, int _Damage)
{

}

void DamageRef(int& _Hp, int _Damage)
{

}

int main()
{
    {
        int MonsterHp = 100;
        int* MonsterHpPtr = &MonsterHp;

        *MonsterHpPtr = 200;
        *MonsterHpPtr = 300;

        DamagePtr(MonsterHpPtr, 20);
    }

    // 레퍼런스 : 쉽게 말해 상시 *가 붙은 상태로 사용하는 포인터
    // -> 레퍼런스의 크기는 참조하는 자료형에 따라 달라진다.
    // 레퍼런스가 포인터에 비해 사용하기 편해 보인다.
    {
        int MonsterHp = 100;
        int& MonsterHpRef = MonsterHp;

        // 레퍼런스를 사용할때는 절대 무조건 어떤일이 있어도 값이 들어올때 사용한다.
        // int& Ref; // 오류!!

        MonsterHpRef = 200;
        MonsterHpRef = 300;

        DamageRef(MonsterHpRef, 20);
    }

    // 레퍼런스와 포인터는 기계어에서 똑같이 작동한다. (성능이 같다.)
    // 포인터는 중간에 가리키는 대상을 바꿀수 있다.
    // 레퍼런스는 중간에 가리키는 대상을 바꿀수 없다.
    // -> 오직 딱 1번만 초기화된다.
    {
        int Value0 = 100;
        int Value1 = 200;

        int* Ptr = &Value0;
        Ptr = &Value1; // Ptr에 저장된 주소값을 바꿀수 있다.
        Ptr = nullptr;

        int& Ref = Value0;
        Ref = Value1; // 그저 Value1 값이 Value0에 대입될 뿐이다.
    }
}