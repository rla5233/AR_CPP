// 076_Template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A
{
public:
    // 오버로딩
    void Test(int _Value)
    {

    }

    void Test(char* _Value)
    {

    }

    // 오버로딩
    void operator+(int _Value)
    {

    }

    void operator+(const char* _Value)
    {

    }

};


// 자료형만 다른데 2번치기 귀찮다..
//void Print(int _Value)
//{
//    std::cout << _Value << std::endl;
//}
//
//void Print(char* _Value)
//{
//    std::cout << _Value << std::endl;
//}

// 이럴때 단 1번만 함수를 만들어도 되는 문법이 템플릿 문법이다.
// -> 자료형을 마치 변수처럼 사용하는 문법

// 템플릿은 기본적으로 함수나 클래스 위에 template<typename 이름>
// 을 붙여 사용

// typename 변수처럼 사용하고 싶은 자료형의 이름
template<typename Type>
void Print(Type _Value)
{
    std::cout << *_Value << std::endl;
}

// 실제로 내가 만든 함수는 템플릿 함수 1개지만
// 내가 다양한 자료형을 사용해 코딩을하면
// 컴파일러가 알아서 맞는 함수를 만들어 준다.


// template 에러 확인 팁
// template 함수를 함수만 복사해 매개변수의 type을 넣은 채로 다시 생성해 확인


// 템플릿 특수화
// 오버로딩이랑 똑같다.
// 이미 같은 이름의 템플릿 함수가 있으면
// 이걸 템플릿 특수화 라고 부른다.
// (예외를 두는 문법)
// 거의 사용하지 않는편
void Print(const char* _Value)
{
    std::cout << _Value << std::endl;
}



// 클래스 멤버함수에도 사용가능



int main()
{
    {
        A NewA = A();

        NewA + 10;
        NewA + "aaaa";
    }

    {
        bool bValue = true;
        bool* bPtr = &bValue;

        int Value = 10;
        int* iPtr = &Value;

        // 템플릿으로 만들어진 함수의
        // 실제 정식 호출 방식은
        Print<bool*>(bPtr);
        Print<const char*>("AAAA");
        Print<int*>(iPtr);

        // 보통은 그냥 사용
        // 템플릿 인자추론에 의해 어떤 자료형인지를 알아서 해준다.
        Print(bPtr);
        Print("AAAA");
        Print/*<int*>*/(iPtr);
    }
}