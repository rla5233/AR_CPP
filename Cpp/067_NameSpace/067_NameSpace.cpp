// 067_NameSpace.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// UI 팀 담당자
// -> 인벤토리에 아이템을 표시한다.
// 

// UI 팀 Item
namespace UI
{
    class Item
    {
    public:
        Item()
        {
            printf_s("UI Item\n");
        }
    };
}


// Play 팀 Monster 담당자
// -> 몬스터가 죽으면 아이템을 떨군다.
//

// Play 팀 Item
namespace Play
{
    class Item
    {
    public:
        Item()
        {
            printf_s("Play Item\n");
        }
    };
}

// 위 두 Item 클래스는 이름이 겹친다.
// 이렇게 이름이 겹치는 것을 막기 위해 만든것이 
// nampspace -> 내 클래스를 사용하기 위해서는 접두사를 붙여라

class Item
{
public:
    Item()
    {
        printf_s("Item\n");
    }
};

// 이름에 UI를 사용하지 않아도 알아서 연결해 달라는 문법
// 근데 이럴거면 왜 나눴나?
using namespace UI;

int main()
{
    Play::Item PlayItem;
    UI::Item UIItem2;
    //Item item;

    // std:: 가 바로 namespace
    // std -> 스탠다드
    // C++ 언어차원에서 지원하는 기본기능이라는 뜻
    std::cout << "Hello World!\n";
}