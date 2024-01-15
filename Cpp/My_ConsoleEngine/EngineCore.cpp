#include "EngineCore.h"
#include "EngineDebug.h"

void EngineCore::Init(int2 _ScreenSize)
{
	LeakCheck;

	m_Screen.CreateScreen(_ScreenSize.X, _ScreenSize.Y);
}

void EngineCore::Start()
{
    while (m_EngineUpdate)
    {
        Sleep(100);

        // map 과 enum class 를 이용해 ordering이 가능하다 player = 0, bullet = 1, monster = 2
        {
            std::map<int, std::list<ConsoleObject*>>::iterator Order_iter
                = std::map<int, std::list<ConsoleObject*>>::iterator();

            // 업데이트 구조
            for (Order_iter = m_AllUpdateObject.begin(); Order_iter != m_AllUpdateObject.end(); ++Order_iter)
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
                        MsgBoxAssert("Update Object NULL Error.");
                    }

                    Object->Update();
                }
            }

        }

        {
            std::map<int, std::list<ConsoleObject*>>::iterator Order_iter
                = std::map<int, std::list<ConsoleObject*>>::iterator();

            // 렌더링 구조
            for (Order_iter = m_AllRenderObject.begin(); Order_iter != m_AllRenderObject.end(); ++Order_iter)
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

                    m_Screen.SetChar(Object);
                }
            }

            m_Screen.PrintScreen();
        }

        // 렌더 릴리즈 구조
        {
            std::map<int, std::list<ConsoleObject*>>::iterator Order_iter
                = std::map<int, std::list<ConsoleObject*>>::iterator();

            for (Order_iter = m_AllRenderObject.begin(); Order_iter != m_AllRenderObject.end(); ++Order_iter)
            {
                std::list<ConsoleObject*>& Object_List = Order_iter->second;
                std::list<ConsoleObject*>::iterator Object_iter = std::list<ConsoleObject*>::iterator();
               
                for (Object_iter = Object_List.begin(); Object_iter != Object_List.end(); )
                {
                    ConsoleObject* Object = *Object_iter;

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("Render Release Nullptr Error.");
                    }

                    if (Object->IsPendingKill())
                    {
                        Object_iter = Object_List.erase(Object_iter);
                    }
                    else
                    {
                        ++Object_iter;
                    }
                }
            }
        }        

        // 업데이트 릴리즈 구조
        {
            std::map<int, std::list<ConsoleObject*>>::iterator Order_iter
                = std::map<int, std::list<ConsoleObject*>>::iterator();

            for (Order_iter = m_AllUpdateObject.begin(); Order_iter != m_AllUpdateObject.end(); ++Order_iter)
            {
                std::list<ConsoleObject*>& Object_List = Order_iter->second;
                std::list<ConsoleObject*>::iterator Object_iter = std::list<ConsoleObject*>::iterator();
               
                // 리스트의 삭제 방식을 배우셔야 합니다.
                for (Object_iter = Object_List.begin(); Object_iter != Object_List.end(); )
                {
                    ConsoleObject* Object = *Object_iter;

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("U Release Nullptr Error.");
                    }

                    if (Object->IsPendingKill())
                    {
                        delete Object;
                        Object = nullptr;

                        Object_iter = Object_List.erase(Object_iter);
                    }
                    else
                    {
                        ++Object_iter;
                    }
                }
            }
        }
    }

    // 동적 할당 메모리 해제
    {
        {
            std::map<int, std::list<ConsoleObject*>>::iterator Order_iter
                = std::map<int, std::list<ConsoleObject*>>::iterator();

            for (Order_iter = m_AllUpdateObject.begin(); Order_iter != m_AllUpdateObject.end(); ++Order_iter)
            {
                std::list<ConsoleObject*>& Object_List = Order_iter->second;
                std::list<ConsoleObject*>::iterator Object_iter = std::list<ConsoleObject*>::iterator();
                for (Object_iter = Object_List.begin(); Object_iter != Object_List.end(); ++Object_iter)
                {
                    ConsoleObject* Object = *Object_iter;

                    if (Object != nullptr)
                    {
                        delete Object;
                        Object = nullptr;
                    }
                }
            }
        }

        m_AllUpdateObject.clear();
    }
}
