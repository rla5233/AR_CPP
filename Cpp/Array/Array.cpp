// Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <windows.h>
#include <assert.h>

#define MsgBoxAssert(TEXT) MessageBoxA(nullptr, TEXT, "Error", MB_OK); assert(false)
//#define SHALLOW

class IntArray
{
// private: // 디폴트 접근제한 지정자
public:
    // 디폴트 생성자
    //IntArray()
    //{}

    IntArray(int _Size)
    {
        ReSize(_Size);
    }
    
    // 디폴트 복사 생성자
    //IntArray(const IntArray& _Other)
    //{}

#ifdef SHALLOW
    IntArray(const IntArray& _Other)
    {
        ReSize(_Other.NumValue);
        for (int i = 0; i < NumValue; i++)
        {
            ArrPtr[i] = _Other.ArrPtr[i];
        }
    }
#else
    IntArray(const IntArray& _Other)
    {
        Copy(_Other);
    }
#endif

    // 디폴트 소멸자
    //~IntArray()
    //{}

    ~IntArray()
    {
        Release();
    }

    // 디폴트 대입연산자
    //void operator= (const IntArray& _Other)
    //{}


#ifdef SHALLOW
    // 얕은 복사 (Shallow Copy)
    // 1. 참조만 복사하는 복사
    // 깊은 복사가 더 좋아 얕은 복사는 나빠 -> 이건 아니다. 상황에따라 써야한다.
    void operator= (const IntArray& _Other)
    {
        NumValue = _Other.NumValue;
        ArrPtr = _Other.ArrPtr;
    }
#else
    // 깊은 복사 (Deep Copy)
    // 1. 참조의 내부에 존재하는 값을 복사하는 복사
    // 2. 내부에 있는 값을 메모리를 동일하게 할당해 복사하는 복사
    void operator= (const IntArray& _Other)
    {
        Copy(_Other);
    }
#endif


    int& operator[](int _Count)
    {
        return ArrPtr[_Count];
    }

    void ReSize(int _Size)
    {
        if (_Size <= 0)
        {
            MsgBoxAssert("Array Range Error!");
        }

        if (ArrPtr != nullptr)
        {
            Release();
        }

        ArrPtr = new int[_Size];
        NumValue = _Size;
    }

    void Copy(const IntArray& _Other)
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
    int* ArrPtr = nullptr;

};

// 전역 사용
// 절차 지향

// 클래스와 객체 
// 객체 지향

// 템플릿을 사용하는 패러다임을 
// 템플릿 메타 프로그래밍, 제네릭 프로그래밍 이라고 한다.

int main()
{
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

    {
        // 기본문법으로써의 배열의 불편한점
        // 1. 대입이 안된다.
        // 2. 크기를 동적으로 바꿀 수 없다.
        // 3. 그 크기를 알수도 없다. (알수는 있는데 불편하다.)

        // 정적 바인딩
        // 100개에서 바뀔수 없다.
        int ArrValue0[100];
        int ArrValue1[100];

        // 대입이 안된다.
        //ArrValue0 = ArrValue1;
    }

    // 객체지향에서 내가 만든 객체로 표현하지 못할건 없다.
    // 나의 배열을 만들어서 기본 배열의 불편한점을 해결하고 편리하게 사용할 수 있다.
    // (사실 이미 그런것들을 제공하고 있다.)
    // 
    // 자료구조? -> 메모리적으로 어떻게 배치할 것인가?
    // 1. 그 메모리적 구조에서 어떻게 새로운 자료를 추가할 것인가?
    // 2. 어느 부분을 어떻게 삭제할 것인가?
    // 
    // 3. 거기서 내가 원하는 자료를 어떻게 찾을것인가? (옵션)
    // 
    {
        IntArray NewArray = IntArray(5);
        NewArray[0] = 20;

        for (int i = 0; i < NewArray.Num(); i++)
        {
            NewArray[i] = i;
        }

        for (int i = 0; i < NewArray.Num(); i++)
        {
            std::cout << NewArray[i] << " ";
        }
    }

    // 과제
    {
        std::cout << std::endl;
        IntArray NewArray0 = IntArray(5);
        // NewArray0 [0] [1] [2] [3] [4]
        for (int i = 0; i < NewArray0.Num(); i++)
        {
            NewArray0[i] = i;
        }

        for (int i = 0; i < NewArray0.Num(); i++)
        {
            std::cout << NewArray0[i] << " ";
        }

        IntArray NewArray1 = IntArray(10);
        // NewArray1 [?] [?] [?] [?] [?]

        NewArray1 = NewArray0;

        std::cout << std::endl;
        for (int i = 0; i < NewArray1.Num(); i++)
        {
            std::cout << NewArray1[i] << " ";
        }

        int a = 0;
    }
    //NewArray0.~IntArray();
    //NewArray1.~IntArray();

    {
        IntArray NewArray0 = IntArray(5);
        for (int i = 0; i < NewArray0.Num(); i++)
        {
            NewArray0[i] = i;
        }

        IntArray NewArray1 = IntArray(NewArray0);

        std::cout << std::endl;
        for (int i = 0; i < NewArray0.Num(); i++)
        {
            std::cout << NewArray0[i] << " ";
        }

        std::cout << std::endl;
        for (int i = 0; i < NewArray1.Num(); i++)
        {
            std::cout << NewArray1[i] << " ";
        }

        int a = 0;
    }
    //NewArray0.~IntArray();
    //NewArray1.~IntArray();
}