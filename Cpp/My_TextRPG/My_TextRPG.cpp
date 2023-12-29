#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "FightZone.h"
#include "MainMenu.h"

int main()
{
    // 랜덤시드 세팅
    int SeedValue = 0;
    _int64 Seed = reinterpret_cast<__int64>(&SeedValue);
    srand(Seed);

    Player NewPlayer = Player();
    NewPlayer.SetName("Player");
    NewPlayer.SetMinAtt(10);
    NewPlayer.SetSizeAtt(10);

    MainMenu NewMainMenu = MainMenu();
    NewMainMenu.In(NewPlayer);
}