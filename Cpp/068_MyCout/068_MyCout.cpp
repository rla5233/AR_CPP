// 068_MyCout.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

namespace std
{
    class MyStream
    {
    public:
        void operator << (const char* _Text)
        {
            printf_s(_Text);
        }
    };

    // 전역 객체
    extern MyStream mycout;
}

std::MyStream mycout;

int main()
{
    std::mycout << "Hello World!\n";
}