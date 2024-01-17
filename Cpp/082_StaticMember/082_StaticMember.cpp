// 082_StaticMember.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Monster
{
public:
	Monster()
	{
		++Static_MonsterCount;
		++MonsterCount;
	}

	// static 멤버함수 -> 객체를 만들필요 없이 호출가능
	static int /*Monster::*/GetMonsterCount()
	{
		return Static_MonsterCount;
	}

	int MonsterCount = 0;

	// 클래스의 객체 모두가 공유하는 개념의 값
	// 각자가 가지면 안되고
	// 모든 몬스터를 통틀어서 1개만 만들어져야 하는 값.
private:
	// 다른 객체가 접근 못하게 private
	static int Static_MonsterCount; // 선언

};

int Monster::Static_MonsterCount = 0; // 구현

class Player
{
public:
	void Update()
	{
		if (Monster::GetMonsterCount() <= 0)
		{

		}

		std::cout << Monster::GetMonsterCount() << " 의 Monster가 남아있습니다.\n";
	}
};

int main()
{
	Monster NewMonster1 = Monster();
	Monster NewMonster2 = Monster();
	Monster NewMonster3 = Monster();

	Player NewPlayer = Player();
	NewPlayer.Update();

	int a = 0;
}