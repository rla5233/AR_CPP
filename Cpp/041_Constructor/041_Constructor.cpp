// 041_Constructor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
    
}