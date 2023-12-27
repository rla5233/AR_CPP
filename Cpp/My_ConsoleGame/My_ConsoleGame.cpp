#include "ConSoleGameProject.h"

// 함수의 실행 메모리는 고정되어 있어야 한다. -> exe 파일에 적혀있다.
// 한번 컴파일 되고나면 절대 바뀔 수 없다.
// main 함수는 100바이트를 사용한다.
int main()
{
    // 1. 키 입력받아 플레이어 상하좌우 움직이기
    // 2. 벽 채우기 및 벽 바깥으로 못나가게 하기
    // 3. 플레이어가 키 입력받아 총알 발사 (방향은 아무데나)

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