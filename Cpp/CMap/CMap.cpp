#include <iostream>
#include <My_ConsoleEngine/EngineDebug.h>
#include <map>

// 노드형태
typedef int KeyType;
typedef int DataType;
//template <typename DataType>

class MyPair
{
public:
    MyPair(){}
    MyPair(KeyType _first, DataType _second)
        : first(_first), second(_second)
    {}

    KeyType first = KeyType();
    DataType second = DataType();
};

class MyMap
{
private:
    class Node
    {
    public:
        MyPair Pair;
        Node* Parent = nullptr;
        Node* LeftChild = nullptr;
        Node* RightChild = nullptr;

        void insertNode(Node* _Node)
        {
            _Node->Parent = this;

            if (Pair.first > _Node->Pair.first)
            {
                if (LeftChild == nullptr)
                {
                    LeftChild = _Node;
                    return;
                }

                LeftChild->insertNode(_Node);
            }

            if (Pair.first < _Node->Pair.first)
            {
                if (RightChild == nullptr)
                {
                    RightChild = _Node;
                    return;
                }

                RightChild->insertNode(_Node);
            }
        }

        // 어차피 매개변수는 8바이트씩 떨어져 있어서
        // 참조형으로 넘기는게 성능이 더 좋다.
        bool containsNode(const KeyType& _Key)
        {
            if (Pair.first == _Key)
            {
                return true;
            }

            if (Pair.first > _Key)
            {
                if (LeftChild != nullptr)
                {
                    // 리턴과 동시에 재귀를 하는것을 꼬리 재귀라고 합니다.
                    // 컴파일러가 가능하다면 while문 형식으로 바꿔버립니다.
                    // inline이랑 비슷하게 생각해라. 
                    return LeftChild->containsNode(_Key);
                }
            }

            if (Pair.first < _Key)
            {
                if (RightChild != nullptr)
                {
                    return RightChild->containsNode(_Key);
                }
            }

            return false;
        }

        Node* minnode()
        {
            if (LeftChild == nullptr)
            {
                return this;
            }

            return LeftChild->minnode();
        }

        Node* maxnode()
        {
            if (RightChild == nullptr)
            {
                return this;
            }

            return RightChild->maxnode();
        }

        Node* OverParent()
        {
            Node* PNode = Parent;
            while (PNode != nullptr)
            {
                if (Pair.first < PNode->Pair.first)
                {
                    return PNode;
                }

                PNode = PNode->Parent;
            }

            return nullptr;
        }

        Node* UnderParent()
        {
            Node* PNode = Parent;
            while (PNode != nullptr)
            {
                if (Pair.first > PNode->Pair.first)
                {
                    return PNode;
                }

                PNode = PNode->Parent;
            }

            return nullptr;
        }

        Node* NextNode()
        {
            if (RightChild != nullptr)
            {
                return RightChild->minnode();
            }

            return OverParent();
        }

        Node* PrevNode()
        {
            if (LeftChild != nullptr)
            {
                return LeftChild->maxnode();
            }

            return UnderParent();
        }

        Node* FindNode(const KeyType& _Key)
        {
            if (Pair.first == _Key)
            {
                return this;
            }

            if (Pair.first > _Key)
            {
                if (LeftChild != nullptr)
                {
                    return LeftChild->FindNode(_Key);
                }
            }

            if (Pair.first < _Key)
            {
                if (RightChild != nullptr)
                {
                    return RightChild->FindNode(_Key);
                }
            }

            return nullptr;
        }

        bool IsLeaf()
        {
            return RightChild == nullptr && LeftChild == nullptr;
        }

        void Release()
        {
            if (Parent != nullptr)
            {
                if (Parent->LeftChild == this)
                {
                    Parent->LeftChild = nullptr;
                }

                if (Parent->RightChild == this)
                {
                    Parent->RightChild = nullptr;
                }
            }
        }

        // 트리 전위 순회
        void FirstOrderPrint()
        {
            // 할일을 맨 앞에서 함.
            std::cout << Pair.first << std::endl;
            if (LeftChild != nullptr)
            {
                LeftChild->FirstOrderPrint();
            }
            if (RightChild != nullptr)
            {
                RightChild->FirstOrderPrint();
            }
        }

        // 트리 중위 순회
        void MidOrderPrint()
        {
            if (LeftChild != nullptr)
            {
                LeftChild->MidOrderPrint();
            }
            // 할일을 중간에서 함.
            std::cout << Pair.first << std::endl;
            if (RightChild != nullptr)
            {
                RightChild->MidOrderPrint();
            }
        }

        // 트리 후위 순회
        void LastOrderPrint()
        {
            if (LeftChild != nullptr)
            {
                LeftChild->LastOrderPrint();
            }
            if (RightChild != nullptr)
            {
                RightChild->LastOrderPrint();
            }
            // 할일을 맨 뒤에서 함.
            std::cout << Pair.first << std::endl;
        }

        void ClearNode()
        {
            if (LeftChild != nullptr)
            {
                LeftChild->ClearNode();
            }
            if (RightChild != nullptr)
            {
                RightChild->ClearNode();
            }
            if (this != nullptr)
            {
                delete this;
            }
        }
    };

public:
    ~MyMap()
    {
        clear();
    }

    

	class iterator
	{
        friend MyMap;
	public:
		iterator()
		{}

		iterator(Node* _CurNode)
            : CurNode(_CurNode)
		{}

        MyPair* operator->()
        {
            if (CurNode == nullptr)
            {
                MsgBoxAssert("Map Range Error.");
            }

            return &(CurNode->Pair);
        }

        bool operator!=(const iterator& _Other)
        {
            return CurNode != _Other.CurNode;
        }
        
        void operator++()
        {
            CurNode = CurNode->NextNode();
        }

    private:
        Node* CurNode = nullptr;
	};

    // map은 자료가 무작위일때 효율을 발휘한다.
    // 자료가 특정 기준으로 이미 정렬된 상태로 들어간다면
    // 대부분 모두다 vector가 map보다 빠르다.
    void insert(const MyPair& _Value)
    {
        Node* NewNode = new Node();
        NewNode->Pair = _Value;

        // 트리의 기본은 root 
        // 최초의 노드는 root가 된다.
        // root는 부모노드가 없다.
        if (Root == nullptr)
        {
            Root = NewNode;
            return;
        }

        if (!contains(_Value.first))
        {
            Root->insertNode(NewNode);
        }
        else
        {
            delete NewNode;
        }
    }

    bool contains(const KeyType& _Key)
    {
        if (Root == nullptr)
        {
            return false;
        }

        return Root->containsNode(_Key);
    }

    iterator find(const KeyType& _Key)
    {
        if (Root == nullptr)
        {
            return end();
        }

        return iterator(Root->FindNode(_Key));
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    iterator begin()
    {
        if (Root == nullptr)
        {
            return end();
        }

        return iterator(Root->minnode());
    }

    iterator erase(iterator& _Iter)
    {
        iterator Return;

        if (_Iter.CurNode == nullptr)
        {
            MsgBoxAssert("Erase Range Error.");
            return Return;
        }

        Node* NextNode = _Iter.CurNode->NextNode();
        Return.CurNode = NextNode;

        // 자식 노드가 없다.
        if (_Iter.CurNode->IsLeaf())
        {
            Node* ParentNode = _Iter.CurNode->Parent;
            _Iter.CurNode->Release();
            delete _Iter.CurNode;
            return Return;
        }

        // 자식 노드가 있다. -> 교체를 해줘야 한다.
        Node* ChangeNode = nullptr;
        Node* CurNode = _Iter.CurNode;

        // 교체 노드 찾기
        ChangeNode = CurNode->RightChild->minnode();
        if (ChangeNode == nullptr)
        {
            ChangeNode = CurNode->LeftChild->maxnode();
        }

        if (ChangeNode == nullptr)
        {
            MsgBoxAssert("Change Node Error.");
            return Return;
        }

        // 바뀔 노드의 부모에게 이사간다고 알리기
        ChangeNode->Release();

        // 자식 노드에게 삭제되는거 알리기
        Node* LeftChild = CurNode->LeftChild;
        Node* RightChild = CurNode->RightChild;

        if (LeftChild != nullptr)
        {
            LeftChild->Parent = nullptr;
        }

        if (RightChild != nullptr)
        {
            RightChild->Parent = nullptr;
        }

        // 자식 노드에게 새 부모님 알리기
        if (LeftChild != nullptr)
        {
            LeftChild->Parent = ChangeNode;
            if (CurNode->LeftChild != ChangeNode)
            {
                ChangeNode->LeftChild = LeftChild;
            }
        }

        if (RightChild != nullptr)
        {
            RightChild->Parent = ChangeNode;
            if (CurNode->RightChild != ChangeNode)
            {
                ChangeNode->RightChild = RightChild;
            }
        }

        // 바뀌는 노드의 새 부모 노드 알려주기
        ChangeNode->Parent = CurNode->Parent;


        // 새 부모에게 자기소개 하기
        Node* Parent = ChangeNode->Parent;
        if (Parent != nullptr && Parent->LeftChild == CurNode)
        {
            Parent->LeftChild = ChangeNode;
        }

        if (Parent != nullptr && Parent->RightChild == CurNode)
        {
            Parent->RightChild = ChangeNode;
        }

        // 내가 계급 물려주기
        if (Root == CurNode)
        {
            Root = ChangeNode;
        }

        // 승천
        delete CurNode;
        return Return;
    }

    void clear()
    {
        Root->ClearNode();
    }

    // 트리 순회 방법
    // 전위 순회
    void FirstOrderPrint()
    {
        Root->FirstOrderPrint();
    }

    // 중위 순회
    void MidOrderPrint()
    {
        Root->MidOrderPrint();
    }

    // 후위 순회
    void LastOrderPrint()
    {
        Root->LastOrderPrint();
    }

private:
	Node* Root = nullptr;
};

int main()
{
    LeakCheck;

    {
        std::cout << "std Map" << std::endl;

        {
            //      Key, Value
            std::map<int, int> NewMap = std::map<int, int>();
            // map에 자료를 추가하는 방법
            // 1. pair
            NewMap.insert(std::pair<int, int>(5, 45));

            // 2. make_pair
            NewMap.insert(std::make_pair(2, 345));

            // 3. 배열 식
            NewMap[3] = 20;

            // std::map<int, int>::value_type == std::pair<int, int>
            // 4
            NewMap.insert(std::map<int, int>::value_type(7, 10));

            // 5
            NewMap.insert({ 1, 1 });
        }

        {
            std::map<int, int> NewMap = std::map<int, int>();

            NewMap.insert(std::pair<int, int>(10, 0));
            NewMap.insert(std::pair<int, int>(10, 2)); // 중복 key 는 무시된다.
            NewMap.insert(std::pair<int, int>(5, 0));
            NewMap.insert(std::pair<int, int>(15, 0));
            NewMap.insert(std::pair<int, int>(12, 0));
            NewMap.insert(std::pair<int, int>(3, 0));
            NewMap.insert(std::pair<int, int>(7, 0));

            // 원소 찾기
            // contains() C++20 에서 사용가능
            if (NewMap.contains(15))
            {

            }

            std::map<int, int>::iterator FindIter = NewMap.find(5);
            if (FindIter != NewMap.end())
            {

            }

            //NewMap.erase(FindIter);
            
            // map을 순회를 돌리는건 효율적인 일이 아니다.
            // 데이터가 많아 질수록 더욱 그렇다.
            std::map<int, int>::iterator it = NewMap.begin();
            for (it; it != NewMap.end(); ++it)
            {
                std::cout << "( " << it->first << ", " << it->second << " )" << std::endl;
            }   
        }       
    }

    {
        std::cout << "\nMyMap" << std::endl;

        //      Key   Value
        MyMap NewMap = MyMap();

        // 오름차순 작은수 => 큰수로 정렬이 됩니다.
        NewMap.insert(MyPair(10, 0));
        NewMap.insert(MyPair(10, 2)); // 중복 key 는 무시된다.
        NewMap.insert(MyPair(5, 0));
        NewMap.insert(MyPair(15, 0));
        NewMap.insert(MyPair(12, 0));
        NewMap.insert(MyPair(3, 0));
        NewMap.insert(MyPair(7, 0));

        if (true == NewMap.contains(12))
        {
            int a = 0;
        }

        MyMap::iterator FindIter = NewMap.find(10);
        std::cout << "Key : " << FindIter->first << std::endl;
        std::cout << "Value : " << FindIter->second << std::endl;

        NewMap.erase(FindIter);
        
        std::cout << std::endl;
        MyMap::iterator it = NewMap.begin();
        for (it; it != NewMap.end(); ++it)
        {
            std::cout << "( " << it->first << ", " << it->second << " )" << std::endl;
        }

        std::cout << std::endl;
        std::cout << "first" << std::endl;
        NewMap.FirstOrderPrint();
        std::cout << "mid" << std::endl;
        NewMap.MidOrderPrint();
        std::cout << "last" << std::endl;
        NewMap.LastOrderPrint();
    }
    
}