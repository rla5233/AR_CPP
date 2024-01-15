#include <iostream>
#include <My_ConsoleEngine/ConsoleScreen.h>
#include <My_ConsoleEngine/EngineDebug.h>
#include <My_ConsoleEngine/EngineCore.h>

#include "Player.h"
#include "Bullet.h"
#include "Monster.h"

#include "ContentsEnum.h"
#include "map"


int main()  
{
    // Engine 초기화
    EngineCore Engine;
    Engine.Init({ 20, 20 });

    // 플레이어 설정
    {
        Player* NewObject = Engine.CreateObject<Player>(GalagaUpdateType::Player, GalagaRenderType::Player);
        NewObject->SetPos({ Engine.m_Screen.GetScreenX() / 2, Engine.m_Screen.GetScreenY() - 2 });
    }

    // 몬스터 설정
    {
        const int MonsterCount = Engine.m_Screen.GetScreenX() / 2;
        for (int i = 0; i < MonsterCount; i++)
        {
            Monster* NewObject = Engine.CreateObject<Monster>(GalagaUpdateType::Monster, GalagaRenderType::Monster);
            NewObject->SetPos({ i, 0 });
            NewObject->SetRenderChar('@');
        }
    }

    // 엔진 시작
    Engine.Start();
}