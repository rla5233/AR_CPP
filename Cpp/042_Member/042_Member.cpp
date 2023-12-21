// 042_Member.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
public:
    
    // 멤버 함수
    void Damage()
    {

    }

    // 멤버 변수
    int Hp;

    // 일반적인 멤버들은 사용을 위해서는 무조건 객체가 필요하다.
};

int main()
{
    // 클래스는 일종의 설계도이다.
    // 멤버를 사용하려면 무조건 객체가 필요하다.
    Player NewPlayer = Player();

    // 기본적인 멤버변수 멤버함수의 사용법이다.
    // 객체 멤버접근연산자(.) 함수
    NewPlayer.Damage();
    NewPlayer.Hp = 20;
}