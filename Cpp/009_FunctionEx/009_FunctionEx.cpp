// 009_FunctionEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 함수의 리턴값 쪽에 자료형을 넣는것과 아닌것의 차이에 대해서 알아보자.
void Test1()
{

}

int Test2()
{
	// 함수를 종료하고 만약 리턴할 값이 있다면 외부에 리턴한다.
	// -> 함수의 실행 스택 메모리를 삭제한다.
	return 10;
}

// 인자란 외부의 값을 복사받아서 내부에서 사용하는것을 의미한다.
void ParameterStart(int Value)
{
	Value = 99999;
}

// 함수의 인자는 n개 넣을 수 있다.
// 함수의 return은 1개이다.
int Damage(int _Hp, int _Att)
{
	_Hp = _Hp - _Att;
	// 원래의 변수 MonsterHp를 변화 시킬 수 없다. 
	// -> 행동이 행동이 아니다!

	return _Hp;
}

// 리턴값이라는것이 무엇인지 알아보자.
// 리턴 이라는 용어가 무엇인지 알아보자.
int main() // (12byte + a) 크기
{
	{
		int Left = 1;
		// 위치 : main실행 스택안에 들어있다.
		// 크기 : 4바이트
		// 형태 : 정수
		// 값 : 1

		int Right = 1;
		// 눈에 보이지 않는 +의 결과값이 존재한다!!
		// 이런 값들을 RValue라고 한다!
		//(Left + Right) = 20;
		// 12바이트 1(4바이트) + 1(4바이트) = 2(4바이트)
		//         LValue Type              RValue Type
		// LValue Type : 왼쪽에 올 수 있는 타입 
		// -> 명시적 이름(주소, 번지, 포인터)이 있어서 메모리에 접근이 가능해야 한다.
		// RValue Type : 오른쪽에 올 수 있는 타입
		// -> 명시적 이름이 없어 메모리에 접근이 불가해 수정할 수 없다.

		// 여기는? (8바이트)
		Left = Test2(); // 4바이트 = 4바이트
	}

	{
		int TestValue = 10;
		ParameterStart(TestValue);
		// 메모리 구조상 TestValue 보다 ParameterStart의 주소값이 더 낮다(low).
		int a = 0;
	}

	{
		int MonsterHp = 100;
		MonsterHp = Damage(MonsterHp, 10);
	}
}