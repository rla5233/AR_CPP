// 066_TypeDef.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// typedef : 자료형에 별명을 붙여주는 것
typedef int int32;

// 사용자 정의 자료형 Job
enum class Job
{
    Fighter,
};

// typedef -> 특정 자료형에 별명을 붙여줄 수 있다.
// 사실 C++에서는 별로 사용할 필요가 없다.
typedef Job JobType;

// typedef가 문법적으로 별로 아름답지 못하다고 생각해서
// 등장한 using -> typedef랑 다른게 하나도 없다.
using myint = int;


int main()
{
    myint i = 0;
}