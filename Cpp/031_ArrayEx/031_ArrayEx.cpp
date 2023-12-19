// 031_ArrayEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// C++ 문법적으로 허용은 하는데..
void Function(int _Ptr[10]) // 컴파일러가 밑 코드처럼 바꿔버림...
// void Function(int* _Ptr)
{
	int Size = sizeof(_Ptr);

	int a = 0;
}

int main()
{
	{
		int ArrayEx[10];
		// 암시적 형변환이 일어남.
		Function(ArrayEx);
	}

	{
		int ArrayEx[99];
		// 암시적 형변환이 일어남.
		Function(ArrayEx);
	}

	// HW (숙제)
	{
		// int *
		// 0b00000000 00000000 00000000 00000001
		int Value = 0b00000000000000000000000000000001;

		char* Ptr = reinterpret_cast<char*>(&Value);

		//			  Ptr[0]   Ptr[1]	Ptr[2]	 Ptr[3]
		//			0b00000000 00000000 00000000 00000001
		//  이렇게 될것 같지만 밑에 처럼 된다 역순이 된다.
		//  이 현상의 이름은? -> 리틀 엔디안
		//			  Ptr[0]   Ptr[1]	Ptr[2]	 Ptr[3] 
		// char *	0b00000001 00000000 00000000 00000000

		char Test0 = Ptr[0];
		char Test1 = Ptr[1];
		char Test2 = Ptr[2];
		char Test3 = Ptr[3];

		int a = 0;
	}
}