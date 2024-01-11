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

    // iterator 부모 클래스 추가

public:
    class iterator
    {
        friend MyList;
    public:
        iterator() {}
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

    class reverse_iterator
    {
        friend MyList;
    public:
        reverse_iterator() {}
        reverse_iterator(Node* _CurNode)
            : CurNode(_CurNode)
        {}

        bool operator != (const reverse_iterator& _Other)
        {
            return CurNode != _Other.CurNode;
        }

        DataType& operator*()
        {
            return CurNode->Data;
        }

        void operator++()
        {
            CurNode = CurNode->Prev;
        }

    private:
        Node* CurNode = nullptr;
    };

    MyList()
    {
        Start->Next = End;
        End->Prev = Start;
    }

    ~MyList()
    {
        Node* DeleteNode = Start;
        while (DeleteNode != nullptr)
        {
            Node* Next = DeleteNode->Next;
            delete DeleteNode;
            DeleteNode = Next;
        }
    }

    iterator begin()
    {
        return iterator(Start->Next);
    }

    iterator end()
    {
        return iterator(End);
    }

    reverse_iterator rbegin()
    {
        return reverse_iterator(End->Prev);
    }

    reverse_iterator rend()
    {
        return reverse_iterator(Start);
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

    iterator erase(iterator& _Iter)
    {
        if (_Iter.CurNode == Start || _Iter.CurNode == End)
        {
            MsgBoxAssert("Delete Range Error.");
        }

        iterator ReturnIter = iterator();
        if(_Iter.CurNode != nullptr)
        {
            ReturnIter = iterator(_Iter.CurNode->Next);

            Node* PrevNode = _Iter.CurNode->Prev;
            Node* NextNode = _Iter.CurNode->Next;

            PrevNode->Next = NextNode;
            NextNode->Prev = PrevNode;
        
            delete _Iter.CurNode;
            _Iter.CurNode = nullptr;
        }

        return ReturnIter;
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
        for (int i = 0; i < 5; i++)
        {
            NewList.push_back(i);
            //NewList.push_front(i);
        }

        std::list<int>::reverse_iterator iter = NewList.rbegin();
        for (iter; iter != NewList.rend(); ++iter)
        {
            std::cout << *iter << std::endl;
        }
    }

    {
        std::cout << "\nMyList" << std::endl;
        MyList NewList = MyList();
        for (int i = 0; i < 5; i++)
        {
            NewList.push_back(i);
            //NewList.push_front(i);
        }

        MyList::reverse_iterator iter = NewList.rbegin();
        for (iter; iter != NewList.rend(); ++iter)
        {
            std::cout << *iter << std::endl;
        }
    }   
}