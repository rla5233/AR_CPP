// StringToNumber.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 문자의 개수를 세서 return 하는 함수
int StringCount(const char* _Ptr)
{
    int count = 0;
    while (_Ptr[count])
    {
        ++count;
    }

    return count;
}

// 문자열을 int형으로
int My_StringToNumber(const char* const _NumberString)
{
    int number = 0, tmp = 0;
    int length = StringCount(_NumberString);
    for (int i = 0; i < length; i++)
    {
        char c = _NumberString[length - i - 1];
        tmp = static_cast<int>(c - '0');
        for (int j = 0; j < i; j++)
        {
            tmp *= 10;
        }
        number += tmp;
    }

    return number;
}

// 선생님 정답 코드
int SSam_StringToNumber(const char* const _NumberString)
{
    int Count = StringCount(_NumberString);

    int Value = 1;
    for (int i = 0; i < Count - 1; i++)
    {
        Value *= 10;
    }
    
    int Result = 0;
    for (int i = 0; i < Count; i++)
    {
        char Ch = _NumberString[i];
        // '6' = 54 => 6
        int Number = Ch - '0';
        Result += Number * Value;
        Value /= 10;
    }

    return Result;
}



// int를 문자열로
void My_NumberToString(int _Number, char* _Ptr)
{
    _Ptr[0] = '0';
    
    int idx = 0;
    while (_Number)
    {
        _Ptr[idx++] = _Number % 10 + '0';
        _Number /= 10;
    }

    int length = StringCount(_Ptr);
    for (int i = 0; i < length / 2; i++)
    {
        char tmp = _Ptr[length - 1 - i];
        _Ptr[length - 1 - i] = _Ptr[i];
        _Ptr[i] = tmp;
    }
}

// 선생님 정답 코드
void SSam_NumberToString(int _Number, char* _Ptr)
{

}

int main()
{
    int Number = SSam_StringToNumber("1234");
    
    char Arr[100] = {};
    My_NumberToString(120123, Arr);

    int a = 0;
}