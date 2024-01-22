// 087_Delete.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test1
{
public:
    // 함수를 사용하지 못하게 명시적으로 막는 방법이 있다.
    
    // 내가 깊은복사를 할지 얕은 복사를 할지 결정 해야한다.
    // 안전장치로 복사 관련 기본 함수를 delete 하고 나중에
    // 필요할때 정의한다.
    void operator=(const Test1& _Other) = delete;

// 과거의 방법
// 어거지 방법이며 완전히 막을 수 있는 것도 아니다.
//private:
//    void operator=(const Test& _Other)
//    {
//
//    }
};

int main()
{
    Test1 NewTest0;
    Test1 NewTest1;

    // 디폴트 대입연산자.
    //NewTest0 = NewTest1;
    
}