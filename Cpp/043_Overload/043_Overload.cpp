// 043_Overload.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// C++의 기본 규칙은 달라지지 않았다.
// 리턴값은 함수 이름에 포함되지 않습니다.
// 이름이 같은데 인자가 다른함수를 여러개 만들 수 있는 규칙을 
// 오버로딩이라고 부른다.

// 이 오버로딩 규칙은 모든 규격(전역함수, 멤버함수, 생성자)의 함수에 사용할 수 있다.

// 사실 완전히 똑같은 이름의 함수는 여러개 만들 수 없다.
// Test() 의 FullName => Test(void)
void Test()
{

}

// Test(int)
void Test(int _Value)
{

}

// Test(char)
void Test(char _Ch)
{

}


class Monster
{
public:
    // 생성자
    Monster() // 생성자 1
    {

    }

    Monster(int _Value) // 생성자 2
    {

    }

    Monster(int _Value0, int _Value1, int _Value2) // 생성자 3
    {

    }
};

int main()
{
    {
        // 생성자 1 호출
        Monster NewMonster0 = Monster();
    }
    {
        // 생성자 2 호출
        Monster NewMonster0 = Monster(10);
        Monster NewMonster0 = 10;
    } 
    {
        // 생성자 3 호출
        Monster NewMonster0 = Monster(10, 10, 10);
        Monster NewMonster0 = { 10, 10, 10 };
    }


}