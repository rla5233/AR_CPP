// 051_HeaderAndCpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ConsoleScreen.h"
#include "Galaga.h"
#include "Player.h"
#include "Bullet.h"

int main()
{
    ConsoleScreen NewScreen = ConsoleScreen(ScreenBackGround);
    Galaga NewGalaga = Galaga();

    Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, Default_Player);
    Bullet NewBullet = Bullet(NewPlayer.GetPos(), Default_Bullet);

    bool& Ref = NewBullet.GetIsFireRef();
    NewPlayer.SetBulletFire(&Ref);

    while (1)
    {
        NewScreen.ClearScreen();
        NewGalaga.GalagaMapDraw(NewScreen);

        NewScreen.SetPixel(NewPlayer.GetPos(), NewPlayer.GetRenderChar());

        if (NewBullet.GetIsFireRef() == true)
        {
            NewScreen.SetPixel(NewBullet.GetPos(), NewBullet.GetRenderChar());
        }

        NewScreen.PrintScreen();
        NewPlayer.Update();
    }
}