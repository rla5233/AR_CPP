// 057_HasA_IsA.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 플레이어
// 플레이어 is a 싸우는애
// 플레이어는 싸우는 애다
// 그걸 표현하는 문법이 상속

// 장비
// 플레이어 has a 장비
// 장비는 플레이어가 가져야할 요소는 맞지만
// 장비 != 플레이어

class Item
{
public:

protected:
    int m_Cost = 0;
};

class Potion : public Item
{

};

class Sword : public Item
{

};

class FightUnit
{

};

// 멤버변수로 다른 클래스를 가지면
// 플레이어 has a sword

class Player : public FightUnit
{
private:
    Sword m_Sword;
};

int main()
{
    
}