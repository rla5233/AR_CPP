// 017_switch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

enum class PlayerJOBType
{
    Fighter,
    Mage,
    BowMan,

};

int main()
{
    // switch는 자동완성 기능이 있다.
    PlayerJOBType Type = PlayerJOBType::BowMan;
    switch (Type)
    {
    case PlayerJOBType::Fighter:
        break;
    case PlayerJOBType::Mage:
        break;
    case PlayerJOBType::BowMan:
        break;
    default:
        break;
    }
    
    
    // switch는 다음과 같이 사용하고.
    // case 상수 : 의 조건과 같다면 실행
    // switch문은 완전히 if문으로 대체될 수 있다.
    // switch문 내부에서는 일반적으로 지역변수를 사용할 수 없다.
    // switch 메모리 == 상수 -> 이러한 비교 밖에 안됨
    // -> 모든 변수는 case의 비교 대상이 될 수 없다.
    int A = 10;

    switch (A)
    {
    case 0:
        break;
    case 10:
    {
        // 이러한 식으로 해야 지역변수 사용이 가능하다.
        int a = 0;
        break;
    }
    case 20:
        break;
    default:
        break;
    }
}