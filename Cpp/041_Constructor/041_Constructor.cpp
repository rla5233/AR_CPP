﻿// 041_Constructor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 초기화

class Monster
{
    // 멤버
private:
    // 클래스 안의 변수 -> 멤버 변수

    // 초기화 되지 않은 멤버 변수이다.
    int Hp1;

    // 클래스의 멤버변수를 초기화하는 방법이 여러가지가 있다.
    
    // 1. 최신 C++ 방식인 리터럴 초기화
    int Hp2 = 20;

};

class Monster2
{

public:
    int Hp;
};

class NPC
{
public:

    // 3. 생성자
    // 생성자는 멤버함수의 규칙에서 예외가 됩니다.
    // - 리턴값이 없다. -> 어차피 자기자신을 포함하고 있는 객체를 만들어서 리턴함
    // - 생성자는 객체 없이도 호출이 가능한다. -> 모순을 해결하기 위해 생성자는 객체없이도 호출 가능
    // - 무조건 클래스의 이름과 동일해야 한다.
    // - 초기화를 위한 멤버이니셜라이즈 문법이라는 것을 유일하게 사용할 수 있다.
    // - 디폴트 생성자를 만들지 않았다면 아래와 같은 기본생성자를 만들어 버린다.
    // 

    // 대입과 초기화의 차이를 확실히 이해해야한다.
    // 멤버이니셜 라이저 문법 생성자 () : 멤버이름()
    NPC() : Hp(100), Att(10) // 초기화
    {
        // 사용할 수 있다 == 이미 만들어져 있다.
        // 이건 대입
        Hp = 20;
    }

private:
    int Hp;
    int Att;
};

class Test
{
public:
    
    // 실무에선 한가지 생성자 방식으로 통일한다.
    Test()
        : Value(20)
    {

    }

    int Value = 10;
};

int main()
{
    // 지역 변수
    int LoclaVar = 10;

    // 지역 변수
    Monster Monster1 = Monster();

    // 2. 이니셜라이즈 리스트 초기화 방식
    // 모든 변수가 public 일때만 가능하다.
    // 배열초기화를 하는것처럼 초기화 할 수 있다.
    Monster2 Monster2 = { 10 };

    // 3. 생성자
    // NPC() 가 생성자
    NPC NewNPC = NPC();

    {
        // 대입과 초기화의 차이를 확실히 알아야한다.
        // 메모리가 만들어짐과 동시에 초기화
        int Value = 0;

        // 메모리가 만들어진 이후에 값을 넣어주는 대입
        Value = 10;
    }    
}