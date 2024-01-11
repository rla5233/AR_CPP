// CVector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <My_ConsoleEngine/EngineDebug.h>

// 인터페이스?
// 클래스와 코드의 함수의 사용방식을 말함
// 익숙한 인터페이스
// 익숙한 클래스 사용방법
// 익숙한 클래스의 멤버변수들

// 자료 구조 3대장
// vector
// map
// list

// string
// queue
// stack

// 자료구조는 원리도 알아야하지만
// 어디서, 왜, 어떻게 사용했나가 중요하다.

// vector
// 시퀀스 컨테이너
// - 배열기반 메모리 구조를 가짐
// - 임의 접근 가능
// - size 와 capacity 의 차이를 알아야한다.

template<typename DataType>
class CArray
{
public:
    CArray()
    {

    }

    CArray(int _Size)
    {
        ReSize(_Size);
    }

    CArray(const CArray& _Other)
    {
        Copy(_Other);
    }

    ~CArray()
    {
        Release();
    }

    void operator= (const CArray& _Other)
    {
        Copy(_Other);
    }


    DataType& operator[](int _Count)
    {
        return ArrPtr[_Count];
    }

    void ReSize(int _Size)
    {
        if (_Size <= 0)
        {
            MsgBoxAssert("Array Range Error!");
        }

        //////////////////////////
        DataType* Temp = nullptr;
        Temp = new DataType[_Size];

        if (Temp == nullptr)
        {
            MsgBoxAssert("Memory Allocation Error!");
        }

        int Size = NumValue < _Size ? NumValue : _Size;

        for (int i = 0; i < Size; i++)
        {
            Temp[i] = ArrPtr[i];
        }

        ///////////////////////////


        if (ArrPtr != nullptr)
        {
            Release();
        }

        ArrPtr = Temp;
        NumValue = _Size;
        Temp = nullptr;
    }

    void Copy(const CArray& _Other)
    {
        ReSize(_Other.NumValue);
        for (int i = 0; i < NumValue; i++)
        {
            ArrPtr[i] = _Other.ArrPtr[i];
        }
    }

    void Release()
    {
        if (ArrPtr != nullptr)
        {
            delete[] ArrPtr;
            ArrPtr = nullptr;
        }
    }

    int Num()
    {
        return NumValue;
    }

private:
    int NumValue = 0;
    DataType* ArrPtr = nullptr;

};

template<typename DataType>
class MyVector
{
public:
    void resize(int _Size)
    {
        Array.ReSize(_Size);
        sizeValue = _Size;
    }

    void reserve(int _Size)
    {
        // 크기만 확장시킴
        Array.ReSize(_Size);
    }

    DataType& operator[](size_t _Index)
    {
        if (size() <= _Index)
        {
            MsgBoxAssert("Index Range Error.");
        }

        return Array[_Index];
    }

    void push_back(const DataType& _Data)
    {
        if (capacity() <= sizeValue + 1)
        {
            Array.ReSize((Array.Num() + 1) * 2);
        }
        
        Array[sizeValue] = _Data;
        ++sizeValue;
    }

    void emplace_back()
    {
        if (capacity() <= sizeValue + 1)
        {
            Array.ReSize((Array.Num() + 1) * 2);
        }

        Array[sizeValue] = DataType();
        ++sizeValue;
    }

    size_t capacity()
    {
        return Array.Num();
    }

    size_t size()
    {
        return sizeValue;
    }

    void clear()
    {
        sizeValue = 0;
    }

private:
    int sizeValue = 0;
    CArray<DataType> Array;
};

int main()
{
    {
        MyVector<int> ArrVector = MyVector<int>();
        std::vector<int> StdVector = std::vector<int>();

        std::cout << "Std Vector" << std::endl;;
        for (int i = 0; i < 10; i++)
        {
            StdVector.emplace_back();
            std::cout << "size : " << StdVector.size() << std::endl;
            std::cout << "capacity : " << StdVector.capacity() << std::endl;
            std::cout << "value : " << StdVector[i] << std::endl;
        }

        std::cout << std::endl << "My Vector" << std::endl;;
        for (int i = 0; i < 10; i++)
        {
            ArrVector.emplace_back();
            std::cout << "size : " << ArrVector.size() << std::endl;
            std::cout << "capacity : " << ArrVector.capacity() << std::endl;
            std::cout << "value : " << StdVector[i] << std::endl;
        }
    }
}