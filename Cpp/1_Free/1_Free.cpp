#include <iostream>
using namespace std;

class Parent
{
public:
    Parent()
    {
        this;

        int a = 0;
    }

    virtual void Func1()
    {

    }

    virtual void Func2()
    {

    }
};

class Child : public Parent
{
public:
    Child()
    {
        this;

        int a = 0;
    }

    void Func1() override
    {

    }
};

int main()
{
    Child NewChild;
    int size1 = sizeof(Child);
    int size2 = sizeof(Parent);

    int a = 0;

    return 0;
}
