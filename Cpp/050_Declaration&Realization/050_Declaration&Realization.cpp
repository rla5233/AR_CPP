// 050_Declaration&Realization.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 전처리기 -> 컴파일러 -> 어셈블러 -> 링커
// 링커 : 선언과 구현을 이어줌

// Declaration 선언
// 이런함수 구현되어 있을거야.
// 믿고 호출하면 구현과 연결될거야.
void FightDamage(int* _Hp, int _Att);


// 몬스터는 아래 FightDamage 함수를 사용할 수 없다.
// C++은 코드를 위에서부터 아래로 읽기 때문에
// 뒤에 선언된 FightDamage 함수를 사용할 수 없다.
class Monster
{
public :
    int Hp;

    void Damage(int _Att)
    {
        FightDamage(&Hp, _Att);
    }
};

class Player
{
public:
    int Hp;

    void Damage(int _Att)
    {
        FightDamage(&Hp, _Att);
    }

    void TestPlayerRender();
};


// Realization 구현
// 링커는 이 구현부를 선언부와 연결해준다.
void FightDamage(int* _Hp, int _Att)
{
    *_Hp -= _Att;
}

// 클래스 함수의 선언과 구현의 분리는
// 클래스 바깥쪽에서 이루어진다.
// 아래와 같이 구현하면 전역함수로 인식하므로
// FullName을 사용해야 한다.
void TestPlayerRender()
{

}

// Fullname
void Player::TestPlayerRender()
{

}

int main()
{
    
}