#include <iostream>
#include <My_ConsoleEngine/ConsoleScreen.h>
#include <My_ConsoleEngine/EngineDebug.h>
#include "Player.h"
#include "Bullet.h"

int main()
{
    LeakCheck;

    ConsoleScreen NewScreen = ConsoleScreen();
    NewScreen.CreateScreen(30, 10);

    Player NewPlayer = Player();

    const int BulletCount = 10;
    Bullet* NewBullet = new Bullet[BulletCount];

    int CurBullet = 0;
    while (true)
    {
        Sleep(100);
        NewPlayer.KeyInput();

        if (NewPlayer.GetIsFire())
        {
            NewBullet[CurBullet].SetPos(NewPlayer.GetPos());
            NewBullet[CurBullet].Fire();

            ++CurBullet;
            CurBullet %= BulletCount;
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

    NewScreen.ReleaseScreen();
}