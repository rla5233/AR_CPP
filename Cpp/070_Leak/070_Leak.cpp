// 070_Leak.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Monster
{
private:
    int m_Hp = 100;
    int m_Att = 10;
    int m_Def = 5;
};

int main()
{
    // 이건 그냥 외워야함
    
    // 메모리 누수는 매우 심각한 문제를 발생시킬수 있다.
    // 아래의 함수를 이용해 메모리 누수를 체크할수 있다.
    // new를 하고 delete를 하지 않은 메모리롤 체크할 수 있다.
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

    Monster* NewMonster = new Monster();

    delete NewMonster;

    // leak 때문에 컴퓨터가 느려지진 않는다.
}