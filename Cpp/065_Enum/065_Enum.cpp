// 065_Enum.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// Job
// 0 전사
// 1 마법사
// 2 궁수
//

// "Fighter"
// 상대적으로 문자열로 표현하는것은
// 1. 메모리가 많이 들고
// 2. 철자 실수가 많이 일어난다. "Flghter"


// enum
// n개의 개수로 표현되는 값들이 있을 때 사용
// 사용자 정의 자료형
// 정수형 상수를 정의하는 자료형
enum Job
{
	// 자동으로 맨위에서부터 0으로 채운다.
	// 명시하지 않은 부분은 자연스럽게 위쪽 Enum값 + 1
	Fighter,	// Job::Fighter = 0
	Mage,       // Job::Mage = 1
};

// enum class
enum class DamageType
{
	PDamage,
	MDamage,
};

int main()
{
	{
		Job Fighter = Job::Fighter;
		// enum은 손쉽게 int가 될 수 있다.

		// 일종의 형변환이다.
		int intFighter = Job::Fighter;
		int intMage = Job::Mage;

		// 그러나 클래스에서의 업캐스팅을 제외하고는 
		// 형변환을 최대한 피하는 것이 좋다.
	}

	{
		DamageType Type = DamageType::MDamage;
		// enum class는 자동 형변환을 문법적으로 막았다.

		//int intMDamage = DamageType::MDamage; // 오류!
	}
}