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

    KeyType first = 0;
    DataType second = 0;
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
            if (this->Pair.first > _Node->Pair.first)
            {
                this->LeftChild = _Node;
            }

            if (this->Pair.first < _Node->Pair.first)
            {
                this->RightChild = _Node;
            }
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

        // 트리의 기본은 root 최초의 노드는 root가 된다.
        if (Root == nullptr)
        {
            Root = NewNode;
            return;
        }

        Root->insertNode(NewNode);
    }

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
                std::cout << it->first << std::endl;
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
    }
    
}