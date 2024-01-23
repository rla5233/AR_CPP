// 090_string_view.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

class MyString
{
public:
    std::vector<char> Buffer;

    // 동적 할당
    MyString(const char* _Ptr)
    {
        Buffer.resize(strlen(_Ptr));
    }
};

class MyString_View
{
public:
    const char* Test;

    // 얕은 복사 이용 -> 따라서 더 빠르다.
    // const 인자를 받을때 유용
    MyString_View(const char* _Ptr)
    {
        Test = _Ptr;
    }
};

// 동적할당이 일어날 것이다.
void Function1(const MyString& _Name)
{

}

// 얕은 복사를 이용한다
void Function2(std::string_view _Name)
{

}

int main()
{
    
}