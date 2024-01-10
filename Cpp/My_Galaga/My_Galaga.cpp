#include <iostream>
#include <My_ConsoleEngine/ConsoleScreen.h>
#include <My_ConsoleEngine/EngineDebug.h>
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"

int main()
{
    LeakCheck;

    ConsoleScreen NewScreen = ConsoleScreen();
    NewScreen.CreateScreen(20, 25);
 
    const int MonsterCount = NewScreen.GetScreenX() / 2;
    
    std::vector<ConsoleObject*> AllObject;
    AllObject.reserve(1000);

    // 업캐스팅
    Player* NewPlayer = new Player();
    NewPlayer->SetPos({ NewScreen.GetScreenX() / 2, NewScreen.GetScreenY() - 2 });
    NewPlayer->SetAllObject(&AllObject);
    AllObject.push_back(NewPlayer);

    for (int i = 0; i < MonsterCount; i++)
    {
        Monster* NewMonster = new Monster();
        NewMonster->SetPos({ i, 0 });
        NewMonster->SetRenderChar('@');
        AllObject.push_back(NewMonster);
    }

    //const int BulletCount = NewScreen.GetScreenY() * 2;
    //Bullet* NewBullet = new Bullet[BulletCount];

    //int CurBullet = 0;

    while (true)
    {
        Sleep(100);

        for (int i = 0; i < AllObject.size(); i++)
        {
            AllObject[i]->Update();
        }
        
        for (int i = 0; i < AllObject.size(); i++)
        {
            NewScreen.SetChar(AllObject[i]);
        }

        if (NewPlayer->GetIsEnd())
        {
            break;
        }

        NewScreen.PrintScreen();
    }

    for (int i = 0; i < AllObject.size(); i++)
    {
        if (AllObject[i] != nullptr)
        {
            delete AllObject[i];
            AllObject[i] = nullptr;
        }
    }
}