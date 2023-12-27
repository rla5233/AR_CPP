#pragma once
// #include "Monster.h"
// 헤더에서 헤더참조를 최대한 피하지만 극단적으로 가면 안된다.
// 이건 경험이다.
// 어쩔수 없을때는 순환참조를 주의하면서 헤더 추가하면 된다.


class Player
{
	// 전방선언
	class Monster* NewMonster;

	void Test()
	{
		
	}

};

