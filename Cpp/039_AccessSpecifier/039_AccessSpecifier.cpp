// 039_AccessSpecifier.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 고급언어는 인간의 현실적인 생각을
// 프로그래밍으로도 나타내기 위해서 만들어졌다.
// C부터 시작하는 모든 프로그래밍 언어들은
// 인간의 생각이나 가치관이나 개념을 프로그램으로 표현하기
// 위해서 만들어졌기 때문에 지극히 인간적인 문법들을 가지고있다.
// 
// C++은 그 중간에 있는 언어라서 게임에서 사용된다.
//

// 접근 지정자 (접근 제한 지정자)
class Monster
{
// 클래스의 내부 멤버

public :
//  외부  자식  멤버
//   o     o     o

    int publicint;
    void publicFuction()
    {

    }

protected:
//  외부  자식  멤버
//   x     o     o

    int protectedint;
    void protectedFunction()
    {

    }

private: //생략되어있는 디폴트 접근 지정자
//  외부  자식  멤버
//   x     x     o

    int privateint;
    void privateFunction()
    {

    }

};

class Player
{
public:
    void Test()
    {
        // Monster에게 Player는 외부이다.
        Monster newMonster;
        newMonster.publicFuction();
    }

    int GetHp()
    {
        return Hp;
    }

    void SetHp(int _Value)
    {
        Hp = _Value;
    }

protected:

private:
    // 변수는 보통 기본적으로 private이거나 protected
    int Hp;
    int Att;
};

int main()
{
    // 지역(외부)
    
    Monster NewMonster = Monster();
    // 객체가 값형이거나 레퍼런스 형일때 .을 누르면
    // 객체를 사용이 가능하다. -> NewMonster.
    //
    // 클래스의 기본은 캡슐화
    // 객체지향의 4대특성 : 추상화, 상속, 다형성, 캡슐화
    
    // <추상화>
    // 몬스터를 만들고 싶다. -> 클래스 만들면 끝.
    // 
    // <캡슐화>
    // 객체가 모든것을 외부에 공개할 필요는 없다.
    // 

    
}