// 040_Struct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 1. C++에서 struct와 class의 차이를 설명하라.
struct Monster
{
// public: 디폴트 접근제한 지정자가 public 이다.
// 그 이외의 차이점 없음.

// C에서 관습적으로 내려오는 방식으로 사용되는 경우가 많다.
// 1. 멤버 변수가 공개돼도 되는경우
// 2. 멤버 함수가 필요없는 경우
	int Hp;
	int Att;
};

// 2. C의 struct와 C++의 struct, class의 차이를 설명하라.
// C에서의 struct는 데이터의 집합
struct MyStruct
{
// C의 struct
// 접근제한 지정자 없음
// 내부에 함수도 만들 수 없다.
// 이름생략이 불가능해서 struct Mystruct로 표현해야 한다.
// -> 그냥 Mystruct는 안된다.

	int Hp;
};

int main()
{
	 Monster NewMonster;
	 NewMonster.Hp;
	 // 클래스에서 배우게될 모든 문법이 struct에도 그냥 적용된다.

}