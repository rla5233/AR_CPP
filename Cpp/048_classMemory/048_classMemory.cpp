// 048_classMemory.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 문제 1 : 빈 클래스의 크기는? -> 1바이트
class A
{

};

// 문제 2: B 클래스의 크기는? -> 1바이트
class B
{
public:
    // 멤버함수는 클래스의 크기에 영향을 주지 않는다.
    void Function()
    {

    }
};

// 문제 3: C 클래스의 크기는? -> 1바이트
class C
{
public:
    // 비어있는 클래스의 크기가 1이라고
    // 거기에 더해지는게 아니다.
    bool Test;
};

// 문제 4: D 클래스의 크기는? -> 8바이트
class D
{
public:
    bool Test; // 4
    int Test0; // 4
};

// 문제 5: E 클래스의 크기는? -> 12바이트
class E
{
public:
    bool Test0; // 1 
    // temp;    // 1
    // temp;    // 1
    // temp;    // 1
    int Test1;  // 4 
    bool Test2; // 1 
    // temp;    // 1
    // temp;    // 1
    // temp;    // 1
};


class F // -> 8 바이트
{
// 함수 인자와 비슷한 바이트패딩이라 불리는
// 메모리 정렬법이다.
public:
    bool Test0;  // 1
    bool Test1;  // 1
    // temp;     // 1
    // temp;     // 1
    int Test2;   // 4
};


class G // -> 16 바이트
{
public:
    bool Test0;     // 1
    bool Test1;     // 1
    // Temp;        // 1
    // Temp;        // 1
    __int64 Test2;  // 8
};

class H
{
public:
    G Test0; // G크기
    F Test1; // F크기
};


class Test0
{
    bool Test;
};

class Test1
{
    __int64 Test;
};

class I
{
public:
    Test0 Value0; // G크기
    Test1 Value1; // F크기
};

class J
{
public:
    bool Test0;
    int Test1;
    __int64 Test2;
    // 가장 큰 바이트를 찾는다 => 8
};

class K
{
public:
    bool Test0;
    int Test1;
    bool Test2;
    __int64 Test3;
    // 가장 큰 바이트를 찾는다 => 8
};

int main()
{
    // 문제 1

    // 8바이트 정수 서식문자
    printf_s("A size = %lld\n", sizeof(A)); // 빈 클래스의 크기는 : 1 바이트
    // 아무것도 없는데 0바이트가 아니다? 문법적 모순을 해결하기 위해
    // -> 만약 0바이트를 허용한다면 수많은 문법이 무너진다.
    // ex) 포인터, 배열
    // 
    // ex) 포인터 이동 문법
    // A * NewA;
    // NewA + 2;
    // -> 0바이트라면 포인터가 이동할 수 없다.
    //

    // 문제 2
    printf_s("B size = %lld\n", sizeof(B)); // 1바이트

    // 문제 3
    printf_s("C size = %lld\n", sizeof(C)); // 1바이트

    // 문제 4
    printf_s("D size = %lld\n", sizeof(D)); // 8바이트

    // 문제 4
    printf_s("E size = %lld\n", sizeof(E)); // 8바이트


    printf_s("F Size = %lld\n", sizeof(F)); // 8바이트

    {
        F NewF = F();
        __int64 Address0 = reinterpret_cast<__int64>(&NewF.Test0);
        __int64 Address1 = reinterpret_cast<__int64>(&NewF.Test1);
        __int64 Address2 = reinterpret_cast<__int64>(&NewF.Test2);
    }

    printf_s("G Size = %lld\n", sizeof(G)); // 16바이트

    printf_s("H Size = %lld\n", sizeof(H)); // 24바이트

    printf_s("I Size = %lld\n", sizeof(I)); // 

    {
        J NewJ = J();
        __int64 Address0 = reinterpret_cast<__int64>(&NewJ.Test0);
        __int64 Address1 = reinterpret_cast<__int64>(&NewJ.Test1);
        __int64 Address2 = reinterpret_cast<__int64>(&NewJ.Test2);

        int a = 0;
    }

    printf_s("J Size = %lld\n", sizeof(J)); //

    printf_s("K Size = %lld\n", sizeof(K)); // 
}