// 049_this.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 플레이어
class Player
{
private:
	int Mp = 100;

public:
	void Damage(int _Damage)
	{
		Hp -= _Damage;
	}

public:
	int Att = 10;
	int Hp = 100;

	// __thiscall (함수호출규약) : 자신을 호출한 객체의 포인터를 첫번째 인자로 받음
	void __thiscall Damage(/* Player* const _this, */ int _Damage)
	{
		// 이렇게 치기 귀찮다 -> 그래서 this 사용
		//_this->Hp -= _Damage;

		// const인 이유 자기자신의 주소값을 바꾸지 않는다!
		this->Hp -= _Damage;

		// 멤버함수 내에서는 사실 위마저도 생략된다
		/*this->*/Hp -= _Damage;

		// 자기 클래스안에 자신과 똑같은 클래스의 다른
		// 객체를 인자로 넣으면 그 객체의 멤버를 
		// 다 public으로 사용할 수 있다.
		// 
	}
};

// Player 클래스의 멤버함수 Damage는 사실
// 아래 전역함수처럼 인식된다.
//void Damage(Player* const this, int _Damage)
//{
//	Hp -= _Damage;
//}

// 문법적으로는 차이가 없지만
// 결과적으로는 차이가 있다.
void Damage(Player* _this, int _Damage)
{
	if (_this == nullptr) { return; }

	// 클래스를 포인터로 사용할때는
	// .이 아니라 ->
	_this->Hp -= _Damage;
}

int main()
{
	// const 복습
	const int CValue = 0; // CValue를 바꿀수 없다.
	// 위치 100번지
	// 크기 4
	// 형태 const int
	// 값   0

	// 100번지를 20으로 바꿔
	// 불가능. const 붙음
	// CValue = 20;

	const int* CPtr = &CValue;
	// 위치 150번지
	// 크기 8
	// 형태 const int*
	// 값   100번지

	//*CPtr = 100; // 값을 변경하는일이 불가능하다.

	// 150번지의 값을 0번지로 바꿔
	// 가능
	//CPtr = nullptr;
	{
		// 이렇게 선언하면 바꿀수 없다.
		const int* const CPtr = &CValue;
	}


	Player NewPlayer0 = Player();
	Player NewPlayer1 = Player();

	NewPlayer0.Damage(10);
	NewPlayer1.Damage(20);

}