// 044_OperatorOverLoad.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 보통 수학관련 사용자 정의 자료형을 만들때 많이 사용함
class MyInt
{
public:

	MyInt()
		// : Value(0)
	{

	}

	MyInt(int _Value)
		: Value(_Value)
	{

	}

	// 연산자 겹지정은 클래스의 함수를 만들때
	// 연산자 형식으로 사용할 수 있게 만들 수 있는 함수입니다.
	MyInt operator- (MyInt _Other)
	{
		return Value - _Other.Value;
	}

	MyInt operator+ (MyInt _Other)
	{
		return Value + _Other.Value;
	}

	// 이것때문에 사용한다 할 수 있다.
	// 복사
	void operator= (const MyInt& _Other)
	{
		return;
	}

private:
	int Value = 0;
};

class Player
{
public:
	// 복사
	void operator=(const Player& _Other)
	{
		Hp = _Other.Hp;
		Att = _Other.Att;
		Def = _Other.Def;
		Cri = _Other.Cri;
		Exp = _Other.Exp;
		Gold = _Other.Gold;
	}


public:
	int Hp;
	int Att;
	int Def;
	int Cri;
	int Exp;
	int Gold;
	// ......
};

// 함수의 값에의한 호출은 값을 복사하므로 크기가 커지면 비효율적이다.
void StatusRender(Player NewPlayer)
{

}

// 포인터나 레퍼런스를 사용하는 이유이다. (레퍼런스 추천)-> 8바이트로 줄었다. 
// 레퍼런스이기 때문에 nullptr이나 비어있는 값이 인자로 들어오지 않는다.
void Ref_StatusRender(const Player& NewPlayer)
{

}

int main()
{
	{
		MyInt Left = 20;
		MyInt Right = 20;
		MyInt Result = 0;

		// Result = Left - Right;
		Result = Left.operator-(Right);
	}

	{
		int Left = 20;
		int Right = 20;

		Left - Right;
	}

	{
		Player NewPlayer = Player();
		
		// 함수의 값에의한 호출은 값을 복사하므로 크기가 커지면 비효율적이다.
		StatusRender(NewPlayer);
	}

	{
		Player NewPlayer1 = { 1,1,1,1,1,1 };
		Player NewPlayer2 = { 2,2,2,2,2,2 };

		//NewPlayer1 = NewPlayer2;
		NewPlayer1.operator=(NewPlayer2);
	}
}