﻿// 038_ClassBase.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 클래스 문법을 설명함에 있어서
// 언제나 int와 비교한다.
// int를 class라 생각하면 매우 유사하다.

// int가 할 수 있는것을 내 클래스가 못한다.
// -> 내가 그 기능을 안만든것

// int가 할 수 없는것을 내 클래스가 한다.
// -> 내가 그 기능을 만들어 준것


// 내가 클래스를 만들었을때 명심해야 할게 있다.
class Monster
{
    // 내용이 하나도 없네?
    // Monster() 는 뭐지?
    // 내부에 아무것도 정의하지 않았는데도 되네?
    // -> 컴파일러가 만들어 준 것이다.
    //

};


int main()
{
    Monster newMonster = Monster(); // <- 나는 이런거 만든적이 없는데?

}