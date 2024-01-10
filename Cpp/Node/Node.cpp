// Node.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 노드 구조
// - 자료구조 메모리의 2가지 형태중 하나
// - 어떠한 데이터가 자기자신 데이터의 참조형을 n개 가지면 노드구조라 한다.

template<typename DataType>
class Node
{
public:
    DataType Value;
    Node* Next = nullptr;
};

int main()
{
    Node<int> Node0;
    Node<int> Node1;
    Node<int> Node2;
    Node<int> Node3;
    Node<int> Node4;
    Node<int> Node5;

    Node0.Value = 0;
    Node1.Value = 1;
    Node2.Value = 2;
    Node3.Value = 3;
    Node4.Value = 4;
    Node5.Value = 5;

    Node0.Next = &Node1;
    Node1.Next = &Node2;
    Node2.Next = &Node3;
    Node3.Next = &Node4;
    Node4.Next = &Node5;


    /////////////////////////////////////////
    // CurNode 만 가지고 나머지값 모두 출력
    Node<int>* CurNode = &Node0;
 
    while (CurNode != nullptr)
    {
        std::cout << CurNode->Value << std::endl;
        CurNode = CurNode->Next;
    }
}
