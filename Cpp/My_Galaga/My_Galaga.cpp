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

    Player NewPlayer = Player();
    
    // 리스트 이니셜라이저
    NewPlayer.SetPos({ NewScreen.GetScreenX() / 2, NewScreen.GetScreenY() - 1 });

    const int MonsterCount = NewScreen.GetScreenX() / 2;
    ConsoleObject** ArrMonster = new ConsoleObject * [MonsterCount];
    for (int i = 0; i < MonsterCount; i++)
    {
        ArrMonster[i] = new Monster();
        ArrMonster[i]->SetPos({ i, 0 });
        ArrMonster[i]->SetRenderChar('@');
    }

    const int BulletCount = NewScreen.GetScreenY() * 2;
    Bullet* NewBullet = new Bullet[BulletCount];

    int CurBullet = 0;
    while (true)
    {
        Sleep(100);
        NewPlayer.KeyInput();

        if (NewPlayer.GetIsEnd())
        {
            break;
        }

        if (NewPlayer.GetIsFire())
        {
            NewBullet[CurBullet].SetPos(NewPlayer.GetPos());
            NewBullet[CurBullet].Fire();

            ++CurBullet;
            CurBullet %= BulletCount;
        }

        for (int i = 0; i < MonsterCount; i++)
        {
            NewScreen.SetChar(ArrMonster[i]);
        }

        for (int i = 0; i < BulletCount; i++)
        {
            if (NewBullet[i].GetIsFire())
            {
                NewBullet[i].Move();
                NewScreen.SetChar(NewBullet[i]);
            }
        }        

        NewScreen.SetChar(NewPlayer);
        NewScreen.PrintScreen();
    }

    if (NewBullet != nullptr)
    {
        delete[] NewBullet;
        NewBullet = nullptr;
    }
}