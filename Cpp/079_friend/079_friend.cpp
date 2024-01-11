// 079_friend.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class A1
{
    // 객체 지향에 어긋나는 문법 그러나 C++에서는 지원해준다.
    // 특정 클래스에 한해 접근제한 지정자를 풀어줌.
    // private 이어도 public 처럼 사용할 수 있게함
    // 사용하면 사용할수록 안좋아지는 문법이라 남발하면 안된다.
    
    friend class C;
    friend class B;
private:
    int Value;
};

class B
{
public:
    void BFunc1(A1& _Other)
    {
        _Other.Value;
    }

private:
    void BFunc2(A1& _Other)
    {
        _Other.Value;
    }
};

class C
{
public:
    class A2
    {
        friend class C;
    private:
        int Value;
    };

    void Test1(A1& _Other)
    {
        _Other.Value;
    }

    void Test2(A2& _Other)
    {
        _Other.Value;
    }
};

int main()
{
    
}