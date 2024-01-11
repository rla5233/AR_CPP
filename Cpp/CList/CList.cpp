// CList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <My_ConsoleEngine/EngineDebug.h>
#include <list>

// 노드형태
typedef int DataType;
//template <typename DataType>
class MyList
{
private:
    class Node
    {
    public:
        DataType Data;
        Node* Next;
        Node* Prev;
    };

public:
    class iterator
    {
    public:
        iterator(Node* _CurNode)
            : CurNode(_CurNode)
        {}

        bool operator != (const iterator & _Other)
        {
            return CurNode != _Other.CurNode;
        }

        DataType& operator*()
        {
            return CurNode->Data;
        }

        void operator++()
        {
            CurNode = CurNode->Next;
        }

    private:
        Node* CurNode = nullptr;
    };

    MyList()
    {
        Start->Next = End;
        End->Prev = Start;
    }

    iterator begin()
    {
        return iterator(Start->Next);
    }

    iterator end()
    {
        return iterator(End);
    }

    // End의 Prev에 새로운 데이터를 넣겠다.
    void push_back(const DataType& _Data)
    {
        Node* NewNode = new Node();
        NewNode->Data = _Data;

        NewNode->Next = End;
        NewNode->Prev = End->Prev;

        Node* PrevNode = NewNode->Prev;
        Node* NextNode = NewNode->Next;

        PrevNode->Next = NewNode;
        NextNode->Prev = NewNode;
    }

    // Start의 Next에 새로운 데이터를 넣겠다.
    void push_front(const DataType& _Data)
    {
        Node* NewNode = new Node();
        NewNode->Data = _Data;

        NewNode->Prev = Start;
        NewNode->Next = Start->Next;

        Node* PrevNode = NewNode->Prev;
        Node* NextNode = NewNode->Next;
        
        PrevNode->Next = NewNode;
        NextNode->Prev = NewNode;
    }

protected:


private:
    Node* Start = new Node();
    Node* End = new Node();

};

int main()
{
    LeakCheck;

    {
        std::cout << "std::list" << std::endl;
        std::list<int> NewList = std::list<int>();
        for (int i = 0; i < 10; i++)
        {
            //NewList.push_back(i);
            NewList.push_front(i);
        }

        std::list<int>::iterator iter = NewList.begin();
        for (iter; iter != NewList.end(); ++iter)
        {
            std::cout << *iter << std::endl;
        }
    }

    {
        std::cout << "\nMyList" << std::endl;
        MyList NewList = MyList();
        for (int i = 0; i < 10; i++)
        {
            //NewList.push_back(i);
            NewList.push_front(i);
        }

        MyList::iterator iter = NewList.begin();
        for (iter; iter != NewList.end(); ++iter)
        {
            std::cout << *iter << std::endl;
        } 
    }   
}