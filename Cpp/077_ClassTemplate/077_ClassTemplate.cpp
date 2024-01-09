// 077_ClassTemplate.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

template<typename MemberType>
class TemplateClass
{
public:
    MemberType Value;
};


class TemplateClassint
{
public:
    int Value;
};

int main()
{
    // 클래스템플릿
    // 1. 인자 추론이 안된다. 
    // -> 클래스의 크기가 결정 되어야 하기 때문이다.
    // 2. header Cpp 분할이 불가능하다 (선언과 구현의 분리가 불가능하다) 
    // -> 명시하면 가능하긴한다... 그럴꺼면 템플릿을 왜쓰나?
    // -> 따라서 일반적으로 헤더에 모든것을 구현해야한다.
    //

    // 자료형을 명시해 주어야 한다.
    TemplateClass<int> New;
    // 위처럼 호출하면 TemplateClass를 지우고 TemplateClassint 클래스를 만들어
    // TemplateClassint New; 를 한것과 같다.



}