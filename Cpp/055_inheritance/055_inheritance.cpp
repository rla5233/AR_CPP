// 055_inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 둘다 Att, Hp 갖네...
// 두번 치는건 불합리해..

// 문법의 발전은 모두다 프로그래밍 코드의 재활용성을
// 증가 시키기 위해서 발전해 왔다.
// 코드 재활용성 => 두번치기 귀찮네. 복붙도 귀찮네.

// 상속?
// 코드 재활용성을 위해

// XXXX분야의 클래스들이 공통적으로 가져야할 기능을 가진다.


// 싸우는 애들이 공통적으로 가져야할 기능을 가진다.

// 부모클래스 접근 제한 지정자
//              외부      자식      내부
// public        o         o         o
// protected     x         o         o
// private       x         x         o

class FightUnit
{
public:
    void Damage(int _Att)
    {
        Hp -= _Att;
    }

public:
    int Att = 0;
    int Hp = 100;

    int publicInt = 0;
    void publicFunction()
    {

    }

protected:
    int protectedInt = 0;
    void protectedFunction()
    {

    }

private:
    int privateInt = 0;
    void privateFunction()
    {

    }

};

// 상속하기 (cf. 상속은 헤더를 추가해야한다.)
// 그 기능을 물려받기 원하는 클래스 이름
// 오른쪽에 : 접근제한지정자 부모클래스 이름
class Player : public FightUnit
{
    
};

// 상속에서 접근제한 지정자
// 내부의 기존 접근제한 지정자와 비교해 좁은 범위로 바꿈
class Monster : public FightUnit
{
public:
    void Func()
    {
        
    }
};

// 상속관계를 처음부터 생각하는 것은 별로 좋지않다.
// 생각만하다 진행을 못한다.

int main()
{
    Player NewPlayer = Player();
    //NewPlayer.Att = 10;
    //NewPlayer.Damage(20);

    Monster NewMonster = Monster();
    //NewMonster.Att = 5;
    //NewMonster.Damage(10);
}