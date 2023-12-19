// CharConvert.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// _PrevCh 문자를 _NextCh 문자로 바꾸는 함수 - 바뀐 글자수를 리턴
int CharConvert(char* _String, char _PrevCh, char _NextCh)
{
    int change = 0, count = 0;
    while (_String[count])
    {
        if (_String[count] == _PrevCh)
        {
            _String[count] = _NextCh;
            ++change;
        }

        ++count;
    }

    // 바뀐 글자수를 리턴
    return change;
}

int main()
{
	char Arr[10] = "aaabbbccc";

	int count = CharConvert(Arr, 'c', 'd');

    int a = 0;
}