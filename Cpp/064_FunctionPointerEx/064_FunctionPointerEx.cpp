// 064_FunctionPointerEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void(*vfptrArr[3])()
=
{
    // FightUnitStatusRender,
    // FightUnitDamage
};

void(**vfptr)() = vfptrArr;


//class FightUnit 
//{
/*virtual */void FightUnitStatusRender()
{
    printf_s("FightUnit 스테이터스 랜더 함수");
}

/*virtual */void FightUnitDamage()
{
    printf_s("FightUnit 데미지 함수");
}

/*virtual */void FightUnitFightEnd()
{
    printf_s("FightUnit 파이트엔드 함수");
}


// 생성자에서 생성이 될때
void FightUnit()
// :
{
    vfptr[0] = FightUnitStatusRender;
    vfptr[1] = FightUnitDamage;
}

// void(*vfptr[2])();
//};

    // class Player {
void PlayerDamage() /*override*/
{
    printf_s("플레이어 데미지 함수");
}

void Player()
{
    vfptr[1] = PlayerDamage;
}
// }

int main()
{
    // Player NewPlayer = Player();
    // 플레이어의 생성자가 실행되면
    FightUnit();
    Player();

    // FightUnitStatusRender();
    vfptr[0]();
    // FightUnitDamage();
    vfptr[1]();

    int Value = sizeof(vfptr);
    int Value2 = sizeof(vfptrArr);

    int a = 0;

}