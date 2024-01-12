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

            if (this->Pair.first > _Node->Pair.first)
            {
                if (this->LeftChild == nullptr)
                {
                    this->LeftChild = _Node;
                    return;
                }

                this->LeftChild->insertNode(_Node);
            }

            if (this->Pair.first < _Node->Pair.first)
            {
                if (this->RightChild == nullptr)
                {
                    this->RightChild = _Node;
                    return;
                }

                this->RightChild->insertNode(_Node);
            }
        }

        // 어차피 매개변수는 8바이트씩 떨어져 있어서
        // 참조형으로 넘기는게 성능이 더 좋다.
        bool containsNode(const KeyType& _Key)
        {
            if (this->Pair.first == _Key)
            {
                return true;
            }

            if (this->Pair.first > _Key)
            {
                if (this->LeftChild != nullptr)
                {
                    // 리턴과 동시에 재귀를 하는것을 꼬리 재귀라고 합니다.
                    // 컴파일러가 가능하다면 while문 형식으로 바꿔버립니다.
                    // inline이랑 비슷하게 생각해라. 
                    return this->LeftChild->containsNode(_Key);
                }
            }

            if (this->Pair.first < _Key)
            {
                if (this->RightChild != nullptr)
                {
                    return this->RightChild->containsNode(_Key);
                }
            }

            return false;
        }
    };

public:
	class iterator
	{
	public:
		iterator()
		{}

		iterator(Node* _CurNode)
		{}
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

        Root->insertNode(NewNode);
    }

    bool contains(const KeyType& _Key)
    {
        if (Root == nullptr)
        {
            return false;
        }

        return this->Root->containsNode(_Key);
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
            
            // map을 순회를 돌리는건 효율적인 일이 아니다.
            // 데이터가 많아 질수록 더욱 그렇다.
            std::map<int, int>::iterator it = NewMap.begin();
            for (it; it != NewMap.end(); ++it)
            {
                std::cout << "( " << it->first << ", " << it->second << " )" << std::endl;
            }   

            // 원소 찾기
            // contains() C++20 에서 사용가능
            if (NewMap.contains(15))
            {

            }

            std::map<int, int>::iterator FindIter = NewMap.find(15);
            if (FindIter != NewMap.end())
            {

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

        if (true == NewMap.contains(1))
        {
            int a = 0;
        }

        //MyMap::iterator FindIter;// = NewMap.find(12);
        //std::cout << "Key : " << FindIter->first << std::endl;
        //std::cout << "Value : " << FindIter->second << std::endl;
        //
        //MyMap::iterator it = NewMap.begin();
        //for (it; it != NewMap.end(); ++it)
        //{
        //    std::cout << "( " << it->first << ", " << it->second << " )" << std::endl;
        //}
    }
    
}