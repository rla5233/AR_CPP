// CList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <My_ConsoleEngine/EngineDebug.h>
#include <map>

// 노드형태
typedef int DataType;
//template <typename DataType>
class MyMap
{
private:
    class Node
    {
    public:
        DataType Data;
        Node* Parent;
        Node* LeftChild;
        Node* RightChild;
    };

public:
    MyMap() {}
    

};

int main()
{
    LeakCheck;

    
}