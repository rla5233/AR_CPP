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
    NewPlayer.Init(100, 10, 20, 100);

    MainMenu NewMainMenu = MainMenu();
    NewMainMenu.In(NewPlayer);
}