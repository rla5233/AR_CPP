#pragma once
#include "Global.h"
//#include "Monster.h"
// 클래스의 헤더에서 다른 클래스의 헤더를
// include해야 하는 경우는 2가지가 있다.
// 1. 상속해야 할때
// 2. 값형으로 쓸때

class Player
{
	// 몬스터의 헤더를 알아야 한다.
	// 몬스터의 크기를 알아야 플레이어의 크기가 정의 되기 때문
	//Monster NewMonster; // 값형으로 사용

	// 전방선언
	// 이러이러한 클래스가 있을거야.
	// 포인터나 레퍼런스 일때만 사용할 수 있다.
	class Monster* NewMonster; // 포인터의 크기는 8바이트
};

