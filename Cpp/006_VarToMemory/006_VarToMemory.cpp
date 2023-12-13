// 006_VarToMemory.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 전역 -> 그 어떤 {}에도 속하지 않는 영역
int GlobalA = 10; // 전역 변수
// 절대로 지역 변수와 전역 변수의 이름을 같게 지으면 안된다!

void Test()
{
    // 지역 -> 함수의 {}에 속하는 영역
    int LocalA = 5; // 지역 변수
}

void PlayerMove();
void MonsterMove();

// 함수가 실행되면 함수 실행을 위한 메모리가 스택영역에 할당 된다.
// (내부변수 + a 크기 만큼)
int main()
{ // { : 지역을 만든다.
    // 대부분의 객체지향을 포함했다고 하는 프로그래밍 언어는
    // 개념, 행동, 상태로 인간의 욕구를 구분합니다.

    // 개념 : 몬스터를 만들고 싶다.
    // 몬스터는 움직여야 한다. -> 행동 -> 함수
    // 움직이려면 스피드(속도) -> 상태 -> 변수

    // 변수의 첫번째 규칙
    // 같은 이름의 변수는 같은 영역 안에서 2번 선언 할 수 없다.
    // -> 메모리영역이 겹치기 때문에!
    int MonsterSpeed = 5;
    // int MonsterSpeed = 3; // 오류!
    // FullName -> int mainMonsterSpeed = 5;

    // 위의 변수처럼 함수(지역)안에 만들어진 변수를 지역변수라 한다.
    
    // 번외 지식
    // 이름없는 메모리 영역을 만들수 있다.
    // 이때 메모리 규칙은 함수의 메모리 규칙과 동일하게 적용된다.
    {
        MonsterSpeed = 3;
    }

    MonsterMove();
    Test();

} // } : 지역을 끝낸다.


void PlayerMove()
{
}

void MonsterMove()
{
    // main함수에 만들수 있으면
    // 다른 함수에도 만들수 있다.

    // 서로 다른 함수내에서는 똑같은 이름의 변수를 선언 할 수 있다.
    // -> 함수 내부의 변수는 함수의 이름과 함께 해석 되기 때문이다.
    int MonsterSpeed = 3;
    // int MonsterMoveMonsterSpeed = 3;

    
}