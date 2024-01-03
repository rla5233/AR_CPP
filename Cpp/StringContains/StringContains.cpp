#include <iostream>

enum class StringReturn
{
    Equal,
    NotEqual
};

StringReturn StringEqual(const char* const _Left, const char* const _Right)
{
    int countL = 0, countR = 0;
    while (_Left[countL])
    {
        countL++;
    }

    while (_Right[countR])
    {
        countR++;
    }

    if (countL == countR)
    {
        for (int i = 0; i < countL; i++)
        {
            if (_Left[i] != _Right[i])
            {
                return StringReturn::NotEqual;
            }
        }
    }
    else
    {
        return StringReturn::NotEqual;
    }

    return StringReturn::Equal;
}

void StringAdd(char* _Dest, const char* const _Left, const char* const _Right)
{
    int Dest_idx = 0, Left_idx = 0, Right_idx = 0;
    while (_Left[Left_idx])
    {
        _Dest[Dest_idx] = _Left[Left_idx];

        ++Dest_idx;
        ++Left_idx;
    }

    while (_Right[Right_idx])
    {
        _Dest[Dest_idx] = _Right[Right_idx];

        ++Dest_idx;
        ++Right_idx;
    }
}


int StringContains(const char* const _Dest, const char* const _Find)
{
    char find_char = _Find[0];

    int count = 0, idx = 0;
    while (_Dest[idx])
    {
        if (_Dest[idx] == find_char)
        {
            count++;
        }

        ++idx;
    }

    return count;
}


int main()
{
    {
        // 오른쪽과 왼쪽이 같아?
        switch (StringEqual("ABCD", "ABCD"))
        {
        case StringReturn::Equal:
            printf_s("Equal\n");
            break;
        case StringReturn::NotEqual:
            printf_s("NotEqual\n");
            break;
        }
    }

    {
        // Arr 배열에 두 문자열을 합쳐 저장해
        char Arr[100] = {};
        StringAdd(Arr, "absdfsdcd", "efghsdfsd");

        printf_s("%s\n", Arr);
    }

    {
        int Result = StringContains("abcsafdvacabccccabab", "c");
        printf_s("%d\n", Result);
    }
}