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
    LeakCheck;

    ConsoleScreen NewScreen = ConsoleScreen();
    NewScreen.CreateScreen(20, 25);
 
    const int MonsterCount = NewScreen.GetScreenX() / 2;
    
    std::map<ContentsObjectType, std::list<ConsoleObject*>> AllObject;

    // 업캐스팅
    Player* NewPlayer = new Player();
    NewPlayer->SetPos({ NewScreen.GetScreenX() / 2, NewScreen.GetScreenY() - 2 });
    NewPlayer->SetAllObject(&AllObject);
    AllObject[ContentsObjectType::Player].push_back(NewPlayer);

    for (int i = 0; i < MonsterCount; i++)
    {
        Monster* NewMonster = new Monster();
        NewMonster->SetPos({ i, 0 });
        NewMonster->SetRenderChar('@');
        AllObject[ContentsObjectType::Monster].push_back(NewMonster);
    }

    // 사실 이렇게 반복문을 직접 돌리는건 클라 프로그래머가 하는일이 아니다
    // 엔진 에서 해줘야 한다.
    while (true)
    {
        Sleep(100);

        // map 과 enum class 를 이용해 ordering이 가능하다 player = 0, bullet = 1, monster = 2
        {
            std::map<ContentsObjectType, std::list<ConsoleObject*>>::iterator Order_iter
                = std::map<ContentsObjectType, std::list<ConsoleObject*>>::iterator();

            // 업데이트 구조
            for (Order_iter = AllObject.begin(); Order_iter != AllObject.end(); ++Order_iter)
            {
                std::list<ConsoleObject*>& Object_List = Order_iter->second;
                std::list<ConsoleObject*>::iterator Object_iter = std::list<ConsoleObject*>::iterator();
                for (Object_iter = Object_List.begin(); Object_iter != Object_List.end(); ++Object_iter)
                {
                    ConsoleObject* Object = *Object_iter;

                    // list의 경우 nullptr 안해줘도 된다 그럼에도 nullptr
                    // 문제가 발생한경우 매우 심각한 문제이므로 체크해준다.
                    if (Object == nullptr)
                    {
                        MsgBoxAssert("Object NULL Error.");
                    }

                    Object->Update();
                }
            }
        }
        
        {
            std::map<ContentsObjectType, std::list<ConsoleObject*>>::iterator Order_iter
                = std::map<ContentsObjectType, std::list<ConsoleObject*>>::iterator();

            // 렌더링 구조
            for (Order_iter = AllObject.begin(); Order_iter != AllObject.end(); ++Order_iter)
            {
                std::list<ConsoleObject*>& Object_List = Order_iter->second;
                std::list<ConsoleObject*>::iterator Object_iter = std::list<ConsoleObject*>::iterator();
                for (Object_iter = Object_List.begin(); Object_iter != Object_List.end(); ++Object_iter)
                {
                    ConsoleObject* Object = *Object_iter;

                    if (Object == nullptr)
                    {
                        MsgBoxAssert("Object NULL Error.");
                    }

                    NewScreen.SetChar(Object);
                }
            }

            NewScreen.PrintScreen();
        }

        {
            std::map<ContentsObjectType, std::list<ConsoleObject*>>::iterator Order_iter
                = std::map<ContentsObjectType, std::list<ConsoleObject*>>::iterator();

            // 릴리즈 구조 (중간에 삭제하지 않고, 업데이트 및 렌더링 후 릴리즈 한다.)
            for (Order_iter = AllObject.begin(); Order_iter != AllObject.end(); ++Order_iter)
            {
                std::list<ConsoleObject*>& Object_List = Order_iter->second;
                std::list<ConsoleObject*>::iterator Object_iter = std::list<ConsoleObject*>::iterator();
                for (Object_iter = Object_List.begin(); Object_iter != Object_List.end();)
                {
                    ConsoleObject* Object = *Object_iter;

                    // 리스트의 삭제 방식
                    if (Object == nullptr)
                    {
                        MsgBoxAssert("Object NULL Error.");
                    }

                    if (Object->IsPendingKill())
                    {
                        // 오브젝트를 먼저 지우고 (Player, Bullet, Monster ...)
                        delete Object;
                        Object = nullptr;

                        // 노드를 지운다.
                        Object_iter = Object_List.erase(Object_iter); // erase 하고 다음 iterator를 반환함.
                    }
                    else
                    {
                        ++Object_iter;
                    }
                }
            }
        }

        if (NewPlayer->GetIsEnd())
        {
            break;
        }       
    }

    {
        std::map<ContentsObjectType, std::list<ConsoleObject*>>::iterator Order_iter
            = std::map<ContentsObjectType, std::list<ConsoleObject*>>::iterator();

        for (Order_iter = AllObject.begin(); Order_iter != AllObject.end(); ++Order_iter)
        {
            std::list<ConsoleObject*>& Object_List = Order_iter->second;
            std::list<ConsoleObject*>::iterator Object_iter = std::list<ConsoleObject*>::iterator();
            for (Object_iter = Object_List.begin(); Object_iter != Object_List.end(); ++Object_iter)
            {
                ConsoleObject* Object = *Object_iter;

                if (Object != nullptr)
                {
                    delete Object;
                }
            }
        }
    }
}