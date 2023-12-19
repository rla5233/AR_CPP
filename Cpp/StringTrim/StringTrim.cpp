// StringTrim.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int StringCount(const char* _Ptr)
{
	int count = 0;
	while (_Ptr[count])
	{
		++count;
	}

	return count;
}

// [_Start, _Ptr.length()) 왼쪽으로 한칸이동
void LeftMoveString(char* _Ptr, int _Start)
{
	int count = 0;
	while (_Ptr[count])
	{
		if (count == _Start)
		{
			if (count != 0)
			{
				_Ptr[count - 1] = _Ptr[count];
			}

			_Ptr[count] = _Ptr[count + 1];
		}
		else if (count > _Start)
		{
			_Ptr[count] = _Ptr[count + 1];
		}

		count++;
	}
}

void SSam_LeftMoveString(char* _Ptr, int _Start)
{
	// 방어코드
	if (_Ptr == nullptr)
	{
		return;
	}

	int Count = StringCount(_Ptr);
	
	// 방어 코드
	if (_Start < 1)
	{
		_Start = 1;
	}

	for (int i = _Start - 1; i < Count; ++i)
	{
		_Ptr[i] = _Ptr[i + 1];
	}
}

// _Ptr에서 _Char을 지우는 함수
void DeleteChar(char* _Ptr, char _DeleteCh)
{
	int count = 0;
	while (_Ptr[count])
	{
		if (_Ptr[count] == _DeleteCh)
		{
			if (_Ptr[count + 1])
			{
				LeftMoveString(_Ptr, count + 1);
			}
			else
			{
				_Ptr[count] = 0;
			}
		}
		else
		{
			count++;
		}
	}
}

int main()
{
	{
		char Arr[100] = "abcde";
		//LeftMoveString(Arr, 5);
		
		SSam_LeftMoveString(Arr, 5);

		int a = 0;
	}

	{
		char Arr[100] = " a b  c d e  ";
		DeleteChar(Arr, 'a');

		int a = 0;
	}
}