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
        // �и������� ����
        Sleep(100);

        // ������Ʈ
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = m_AllUpdateObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = m_AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                for (; StartIter != EndIter; ++StartIter)
                {
                    ConsoleObject* Object = *StartIter;

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    Object->Update();
                }
            }
        }

        // ������
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = m_AllRenderObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = m_AllRenderObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                for (; StartIter != EndIter; ++StartIter)
                {
                    ConsoleObject* Object = *StartIter;

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    m_Screen.SetChar(Object);
                }
            }
        }

        m_Screen.PrintScreen();


        //// ���� ������ ����
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = m_AllRenderObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = m_AllRenderObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // ����Ʈ�� ���� ����� ���ž� �մϴ�.
                for (; StartIter != EndIter; )
                {
                    ConsoleObject* Object = *StartIter;

                    if (false == Object->IsPendingKill())
                    {
                        ++StartIter;
                        continue;
                    }

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    // ��带 �����.
                    StartIter = ObjectList.erase(StartIter);
                }
            }
        }

        //// ������Ʈ ������ ����
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = m_AllUpdateObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = m_AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // ����Ʈ�� ���� ����� ���ž� �մϴ�.
                for (; StartIter != EndIter; )
                {
                    ConsoleObject* Object = *StartIter;

                    if (false == Object->IsPendingKill())
                    {
                        ++StartIter;
                        continue;
                    }

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    delete Object;
                    Object = nullptr;

                    // ��带 �����.
                    StartIter = ObjectList.erase(StartIter);
                }
            }
        }
    }

    {
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = m_AllUpdateObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = m_AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // ����Ʈ�� ���� ����� ���ž� �մϴ�.
                for (; StartIter != EndIter; ++StartIter)
                {
                    ConsoleObject* Object = *StartIter;
                    if (nullptr != Object)
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
