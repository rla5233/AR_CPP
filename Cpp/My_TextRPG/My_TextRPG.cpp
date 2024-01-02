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
    NewPlayer.SetMaxAtt(20);
    NewPlayer.SetMaxHp(100);
    NewPlayer.SetHp(NewPlayer.GetMaxHp());

    // FightZone 3개 만들기
    // 초급 중급 고급

    // 초급 몬스터 : 5 ~ 15 att 100 hp
    // 중급 몬스터 : 10 ~ 20 att 200 hp
    // 고급 몬스터 : 20 ~ 40 att 300 hp


    MainMenu NewMainMenu = MainMenu();
    NewMainMenu.In(NewPlayer);
}