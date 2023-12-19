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
        char temp = _Ptr[length - 1 - i];
        _Ptr[length - 1 - i] = _Ptr[i];
        _Ptr[i] = temp;
    }
}

// 선생님 정답 코드
void SSam_NumberToString(int _Number, char* _Ptr)
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

int main()
{
    //int Number = My_StringToNumber("1234");
    int Number = SSam_StringToNumber("1234");
    
    char Arr[10] = {};
    //My_NumberToString(120123, Arr);
    SSam_NumberToString(120123, Arr);

    int a = 0;
}