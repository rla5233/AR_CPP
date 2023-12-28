// 059_DownCasting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit
{
public:
    int Att;
    int Hp;
};

class Player : public FightUnit
{
public:

};

class Monster : public FightUnit
{
public:

};

int main()
{
    Monster NewMonster;
    FightUnit* NewUnit = &NewMonster;

    {
        // 다운 캐스팅
        // - 부모 클래스의 참조형에서 자식클래스의 참조형으로 변환하는 것
        // 건강하지 못한 캐스팅, 구분 할 수 가 없다.
        Player* CurPlayer = reinterpret_cast<Player*>(NewUnit);
    }
}