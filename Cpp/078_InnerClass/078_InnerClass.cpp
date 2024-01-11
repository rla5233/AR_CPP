// 078_InnerClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

class Image
{

};

// 
// 어떤 개념안에 있는 멤버변수들을 여러개 두고 또 다른 개념안에 묶는다.
// 어떤 개념의 하위 개념을 표현한다.
class Inventory
{
private:
    // 하나의 인벤토리라는 개념이 있는데 그 인벤토리라는 개념안에 
    // 인벤토리 아이콘이라는 개념이 있다.
    class InventoryIcon
    {
        Image Image;
        int Count;

        void Test()
        {
            // class 안에 포함되어 있어도
            // 서로의 멤버변수에 무조건 접근가능한건 아니다
            // 접근제한 지정자를 따른다. 
            //Icons; 
        }
    };

    std::vector<InventoryIcon> Icons;
};

int main()
{
    Inventory Inventory;
    //Inventory::InventoryIcon;
}