// 086_Default.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 클래스를 만들때마다 기본 생성자, 기본소멸자, 기본대입연산자를
// 만들어주는 것은 귀찮은 일이다.
class MyClass
{
public:
    MyClass() {}
    ~MyClass() {}

    MyClass& operator=(const MyClass& _Other)
    {

    }

private:

};

int main()
{
    std::cout << "Hello World!\n";
}
