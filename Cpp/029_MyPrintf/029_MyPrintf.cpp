// 029_MyPrintf.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void NumberToString(int _Number, char* _Ptr)
{
	// 어떤 함수든 원본값을 보존해 놓는게 좋습니다.
	int CalNumber = _Number;
	int NumberCount = 0;
	const char* CPtr = _Ptr;

	// 정수가 몇 자리인지 알아야 합니다.
	while (CalNumber)
	{
		CalNumber /= 10;
		++NumberCount;
	}

	int Mul = 1;
	for (int i = 0; i < NumberCount - 1; i++)
	{
		Mul *= 10;
	}

	// 숫자를 분해하기 시작한다.
	CalNumber = _Number;
	int Value = 0;
	for (int i = 0; i < NumberCount; i++)
	{
		Value = CalNumber / Mul;
		_Ptr[i] = Value + '0';
		CalNumber -= Value * Mul;
		Mul /= 10;
	}
}

			// 500번지                  508번지 ...
int MyPrintf(const char* const _Format, ...)
{
	// 그냥 사용하면 500번지   
	// _Format 의 값은 전달받은 문자열의 주소값이다!
	__int64 Address = reinterpret_cast<__int64>(&_Format);
	const int* Ptr = reinterpret_cast<int*>(Address);
	
	// 다음 매개변수 위치로 접근 
	Ptr = Ptr + 2;
	//////////////////////

	int count = 0;
	while (_Format[count])
	{
		char Ch = _Format[count];

		// 포맷팅이 아닐경우 글자를 출력하고 다시 반복한다.
		if (Ch != '%')
		{			
			putchar(_Format[count]);
			++count;
			continue;
		}
		
		// 포맷팅 문자(%)일 경우
		char NextCh = _Format[++count];
		switch (NextCh)
		{
		case 'd':
			{
				int * Ptr = reinterpret_cast<int*>(Address + 8);
				char Arr[100] = {};

				NumberToString(*Ptr, Arr);

				MyPrintf(Arr);
				++count;
				break;
			}
		}

	}

	return count;
}

int main()
{
	// int Value = printf_s("%d", 123456);

	{
		int Return = MyPrintf("aaaa bbb %d %d", 123, 123);

		int a = 0;
	}
}