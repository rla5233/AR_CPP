#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "FightZone.h"

// 데미지가 Random Damage가 되게 해라.

// 선공 후공이 랜덤이 되게 만들어라.

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

    FightZone NewZone;

    NewZone.Fight(NewPlayer);
}