// 037_Object.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 개념만으로는 게임을 만들 수 없다.
// 몬스터를 만들고 싶다.
// -> 몬스터의 개념을 먼저 만들어야 한다.
// -> 구현은 일단 생각하지 마라
// 
// class = 개념을 만들겠다.
//

// 이게 끝이다. 몬스터란 개념을 만든것이다.
// 몬스터란 개념을 문법화 시켰다.
// 이걸 사용자 정의 자료형(user definition type)이라 한다.
class Monster
{
    // 클래스 내부

    // 상태와
    // 행동
    // 을 구체화 해야한다.

    // 상태
    char Name[100];
    int Hp;
    int Att;
    int Speed;

    // 행동
    void Damage(int _Att);
    void StatusRender();
};

class Player
{

};
     

int main()
{
    // 자료형 == 개념
    int; // 정수라고 부르는 개념
    // 이 개념만으로는 아무것도 할 수 없다.
    // 정수를 사용하고 계산하려면 객체화해야한다.

    int A = 0;
    // 이것이 객체화
    // A는 int라는 개념이 메모리화된 객체이다.

    // 그러나 이것만으로는  게임을 만들 수 없다.

    // 똑같은 객체화
    Monster Monster1;
    Monster Monster2 = Monster(); // 초기화까지 
    
}

