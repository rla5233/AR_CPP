// StringFunction000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 문자의 개수를 세서 return 하는 함수
int StringCount(char* _Ptr)
{
    int count = 0;
    while (_Ptr[count])
    {
        ++count;
    }

    return count;
}

// 문자열을 뒤집는 함수
void StringReverse(char* _Ptr)
{
    int length = StringCount(_Ptr);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = _Ptr[length - 1 - i];
        _Ptr[length - 1 - i] = _Ptr[i];
        _Ptr[i] = temp;
    }
}

int main()
{
    {
        char Arr[100] = "sadf;kh;shflsl;jkfea;";
        int Result = StringCount(Arr);
        printf("%d\n", Result);
    }

    {
        char Arr[100] = "sadf;kh;shflsl;jkfea;";
        StringReverse(Arr);
        printf("%s\n", Arr);
    }
}