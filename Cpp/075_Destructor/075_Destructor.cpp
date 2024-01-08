// 075_Destructor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <assert.h>

class Weapon
{

};

class FightUnit
{
public:
	FightUnit() {}
	FightUnit(int _Att, int _Hp)
		: Att(_Att), Hp(_Hp)
	{}

public:
	int Att;
	int Hp;

};

class Player : public FightUnit
{
public:
	// 생성자 : 초기화 때문에 만듦
	Player() 
		: FightUnit(10, 20), Sword(nullptr)
	{}

	// 소멸자
	// 1. 이름이 정해져 있다 ( ~클래스명 )
	//    사실 소멸자의 이름은 ~ 하나라고 볼수 있다.
	//
	// 2. 생성자와는 다르게 일반 멤버변수처럼
	//    직접 호출할 수 있는데, 아무도 직접호출하지 않는다.
	// 
	// 3. 상속관계 하에서 자식의 소멸자가 먼저 호출된다.
	~Player()
	{
		// 대부분 소멸자에서 동적할당을 정리한다.
		// (Leak 안남기기 위해)
		// 이런식으로 소멸자에 넣는다.
		DeleteSword();
	}

	void CreateSword()
	{
		// new를 중복으로 해선 안된다.
		if (Sword != nullptr)
		{
			// assert(false);
			DeleteSword();
		}

		Sword = new Weapon();
	}

	// C++ 프로그래머는 이런 함수를 특정 상황이 아니면
	// 명시적으로 호출하지 않는다.  -> 소멸자가 존재하기 때문
	void DeleteSword()
	{
		delete Sword;
		Sword = nullptr;
	}

private:
	Weapon* Sword = nullptr;

};

// 100
class Orc : public FightUnit
{

};

// 20
class Dragon : public FightUnit
{

};

// 20
class Kobolt : public FightUnit
{

};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	
	Player NewPlayer;
	
	// 한번 할당한 주소값은 잃어버리면 안된다.
	// 애초에 잃어버리지 않는것이 중요하다.
	Weapon* Ptr = new Weapon();
	//Ptr = new Weapon();
	//Ptr = new Weapon();
	//Ptr = new Weapon();
	//Ptr = new Weapon();
	

	// 소멸자 직접호출
	// 아무도 직접호출 하지 않는다. 그냥 거의 불문율이다.
	//NewPlayer.~Player();

	 
	// 보통 동적할당을 사용하면서 다형성을 더더욱 적극적으로 이용하기 시작합니다.
	{
		FightUnit* NewFightUnit = new Player(); // (업캐스팅)
	}

	// Orc 100, Dragon 20, Kobolt 20 만들어서 관리해봐
	// 절대 이렇게 안한다.
	//Orc ArrOrc[100];
	//Dragon ArrDragon[20];
	//Kobolt ArrKobolt[20];

	// 보통 이렇게 관리한다.
	// 다형성을 통한 관리하는 방식이다.
	FightUnit** AllMonster = new FightUnit * [140];
	for (int i = 0; i < 100; i++)
	{
		AllMonster[i] = new Orc();
	}

	for (int i = 100; i < 120; i++)
	{
		AllMonster[i] = new Dragon();
	}

	for (int i = 120; i < 140; i++)
	{
		AllMonster[i] = new Kobolt();
	}

	// 자식의 소멸자가 호출되자 않는다면 굉장히 위험하다.
	// 다형성을 이용하려고 부모 포인터로 관리하고 있었는데.
	// 자식의 소멸자가 호출되지 않았다.
	{
		FightUnit* NewFightUnit = new Player();
	}


}
