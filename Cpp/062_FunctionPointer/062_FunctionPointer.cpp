// 062_FunctionPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 프로그램의 모든건 위치, 크기, 형태, 값 이 있다.
// 그런데 함수는?
void Test1()
{
    printf_s("AAAAAA\n");
}

int Test2()
{
    printf_s("AAAAAA\n");
    return 0;
}

void PlayerAttack()
{
    printf_s("플레이어가 공격합니다.\n");
}

void PlayerMove()
{
    printf_s("플레이어가 이동합니다.\n");
}

class Button
{
public:
    virtual void Click()
    {
        // 이걸 콜백 방식이라 함
        Function();
    }

public:
    int Image;
    int Color;
    int ScreenPos;

    // 함수포인터를 이용하자
    void (*Function)() = nullptr;
};

// 이런식으로 상속해 버튼을 구현하면...
// 버튼 300개가 필요하다면 클래스 300개를 구현해야한다...
class MoveButton : public Button
{
public:
    void Click() override
    {
        printf_s("플레이어가 이동합니다.\n");
    }
};

class AttackButton : public Button
{
public:
    void Click() override
    {
        printf_s("플레이어가 공격합니다.\n");
    }
};

int main()
{
    // 함수포인터 선언
    // Type(*변수명) ()

    void(*Ptr1)() = Test1;
    int(*Ptr2)() = Test2;

    // 함수의 포인터이기 때문에
    // 이름만 다를뿐 그 함수를 사용하는 방법 그대로 사용함
    Ptr1();
    Ptr2();
    printf_s("\n");

    // 함수 포인터 문법은 UI등등에서 가장 많이 사용된다.
    {
        // 버튼마다 클래스를 만들어야 될수도 있다..
        AttackButton AButton;
        MoveButton MButton;
        // ...

        AButton.Click();
        MButton.Click();
    }

    printf_s("\n");

    // 함수 포인터를 이용해 기능을 바꿔줄 수 있다.
    {
        Button NewButton;
        NewButton.Function = PlayerAttack;
        NewButton.Click();

        NewButton.Function = PlayerMove;
        NewButton.Click();
    }
}