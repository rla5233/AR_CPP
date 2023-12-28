// 056_inheritanceMemory.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit
{
public:
    FightUnit() 
    {
        printf_s("FightUnit 생성자\n");
    }

    void Func()
    {
        int a = 0;
    }

protected:
    int Att = 0;
    int Hp = 0;
};


// 상속시 클래스의 크기는 부모와 자식의 
// 변수를 한곳에 합친 클래스의 크기를 구하면 된다.
class Player : public FightUnit
{
public:

    // 상속시 부모 클래스 부터 생성되고
    // 자식 클래스가 생성 된다.
    Player()
    {
        printf_s("Player 생성자\n");
    }

private:
    int Mp = 0;
};

int main()
{
    Player NewPlayer = Player();

    int a = sizeof(Player);
}