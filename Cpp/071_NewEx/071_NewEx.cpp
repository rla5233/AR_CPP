// 071_NewEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{

};

class Sword
{

};

class Player1
{
public:
    Sword* Weapon = nullptr;

public:
    void CreateSword()
    {
        Weapon = new Sword();
    }

    void DeleteSword()
    {
        delete Weapon;
    }

};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

    {
        // Value를 사용한다는건 사실상 포인터와 원리가 같다.
        int Value = 0;
        // 위치 200번지
        // 크기 4
        // 형태 int
        // 값 0

        // 200번지 = 20;

        int* Ptr = &Value;
        // 위치 220번지
        // 크기 8
        // 형태 int*
        // 값 200번지

        // Ptr = nullptr;
        // 220번지 = nullptr;

        *Ptr = 1000;
        // 200번지 = 1000;
    }

    {
        // 일반적으로 new의 리턴값을 받지 않으면 무조건 leak 됩니다.

        //new int(10); // leak
        // operator new(sizeof(int));
        // int* operator new(int _size);

        // 진짜 본모습 (생략하지 않은)
        //reinterpret_cast<int*>(operator new(sizeof(int)));

        //new Player(); // leak
        // operator new(sizeof(Player));

        //new int[10]; // leak
        // operator new(sizeof(int) * 10);

        int* Ptr        =   new int(10);
        // 위치 1000번지    // 위치 500번지
        // 크기 8           // 크기 4
        // 형태 int*        // int
        // 값 500번지       // 값 10

        delete Ptr;
    }
}