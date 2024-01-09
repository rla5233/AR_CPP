// Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <My_ConsoleEngine/EngineDebug.h>

//

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

class Monster
{
public:
    void StatusRender()
    {
        std::cout << "몬스터 ";
    }

private:

};

int main()
{
    LeakCheck;

    {
        CArray<int> TestArray = CArray<int>(10);

        for (int i = 0; i < TestArray.Num(); i++)
        {
            TestArray[i] = i;
        }

        for (int i = 0; i < TestArray.Num(); i++)
        {
            std::cout << TestArray[i] << " ";
        }  
    }

    {
        CArray<const char*> TestArray = CArray<const char*>(10);

        for (int i = 0; i < TestArray.Num(); i++)
        {
            TestArray[i] = "AA";
        }

        std::cout << std::endl;
        for (int i = 0; i < TestArray.Num(); i++)
        {
            std::cout << TestArray[i] << " ";
        }
    }

    {
        CArray<Monster> TestArray = CArray<Monster>(10);

        std::cout << std::endl;
        for (int i = 0; i < TestArray.Num(); i++)
        {
            TestArray[i].StatusRender();
        }
    }

    {
        // 템플릿 운용의 극한
        // 템플릿 클래스 안에 다시 템플릿 클래스를 넣는것
        CArray<CArray<int>> TestArray = CArray<CArray<int>>(10);

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                TestArray[i][j] = j;
            }
        }

        std::cout << std::endl;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                std::cout << TestArray[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}