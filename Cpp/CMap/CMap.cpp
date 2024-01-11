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
	class iterator
	{
	public:
		iterator()
		{}

		iterator(Node* _CurNode)
		{}
	};

	Node* Root;
};

int main()
{
    LeakCheck;

    {
        std::cout << "\nstd Map" << std::endl;
    }

    {
        std::cout << "\nMyMap" << std::endl;
    }
    
}