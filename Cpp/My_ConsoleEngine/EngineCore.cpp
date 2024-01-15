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

        // map �� enum class �� �̿��� ordering�� �����ϴ� player = 0, bullet = 1, monster = 2
        {
            std::map<int, std::list<ConsoleObject*>>::iterator Order_iter
                = std::map<int, std::list<ConsoleObject*>>::iterator();

            // ������Ʈ ����
            for (Order_iter = m_AllUpdateObject.begin(); Order_iter != m_AllUpdateObject.end(); ++Order_iter)
            {
                std::list<ConsoleObject*>& Object_List = Order_iter->second;
                std::list<ConsoleObject*>::iterator Object_iter = std::list<ConsoleObject*>::iterator();
                for (Object_iter = Object_List.begin(); Object_iter != Object_List.end(); ++Object_iter)
                {
                    ConsoleObject* Object = *Object_iter;

                    // list�� ��� nullptr �����൵ �ȴ� �׷����� nullptr
                    // ������ �߻��Ѱ�� �ſ� �ɰ��� �����̹Ƿ� üũ���ش�.
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

            // ������ ����
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

        // ���� ������ ����
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

        // ������Ʈ ������ ����
        {
            std::map<int, std::list<ConsoleObject*>>::iterator Order_iter
                = std::map<int, std::list<ConsoleObject*>>::iterator();

            for (Order_iter = m_AllUpdateObject.begin(); Order_iter != m_AllUpdateObject.end(); ++Order_iter)
            {
                std::list<ConsoleObject*>& Object_List = Order_iter->second;
                std::list<ConsoleObject*>::iterator Object_iter = std::list<ConsoleObject*>::iterator();
               
                // ����Ʈ�� ���� ����� ���ž� �մϴ�.
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

    // ���� �Ҵ� �޸� ����
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
