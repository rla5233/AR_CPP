// 025_const.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 참조형 (포인터나 레퍼런스)을 인자로 받는 함수가
// 참조형에 const를 안걸어놨다면
// 무조건 값이 수정되어서 나올수 있다는 의미로 받아들인다.
// 
// cosnt를 붙임으로써 사용자가 넣어준 값이 바뀌지 않을것이라는 것을
// 명시해 준것이다.
int StringCount(const char* _Ptr)
{
    int Count = 0;

    while (_Ptr[Count])
    {
        ++Count;
    }

    return Count;
}

// Damage 함수니 체력이 줄겠지?
// 함수의 내용은 내부로 가기전까지 알 수 는 없다.
void Damage(int& _Hp, int _Att)
{
    //_Hp += _Att;
}

int main()
{
    // const
    // 내용은 어렵지 않다
    // 그래도 매우매우매우 중요하다

    // 이 메모리 영역은 비트적 상수성을 지키겠다.

    // 컴파일러의 옵션에 따라
    // 아예 상수로 대체될수도 있다.

    // 사용하는 프로그래머들 끼리는 굉장히 중요한 의미가 된다.
    // const == 특정 메모리영역의 값을 변경할 수 없다.
    //       == 함수를 만들 때 프로그래머들끼리의 무언의 의미 교환
    //       == "const가 안붙은 참조형(포인터/레퍼런스)은 무조건 함수안에서 바뀔 것이다."
    //          라는 암묵적인 의미를 내포하고 있는것이다.
    //          함수의 이름만 보고는 정확한 동작을 알 수 없다.
    //          따라서 값이 수정되어서 나오는 것이 아니라면 cosnt를 꼭 붙여야 한다.
    
    {
        const int Value = 0;
        //Value = 20; // 고칠 수 없다!
    }

    {
        const int Value = 0;
        bool Arr[4];
        // 둘은 4바이트 덩어리일 뿐이다.
        // 얼마든지 형변환 할수 있다.

        // 따라서 메모리영역이 크기만 중요할 뿐이다.
    }

    {
        char Arr[10] = "aaaaa";
        int Count = StringCount(Arr);
        std::cout << Count << std::endl;
    }

    {
        // "AAAAA" : 코드 영역에 있기 때문에 const (수정불가)
        int Count = StringCount("AAAAA");

        // 지역 변수 중에 const가 안붙은 것은 스택 영역에 생김
        // 지연 변수 중에 const가 붙은 녀석은 컴파일러에 따라
        // 상수가 될수도 있고 스택에 만들어 질수도 있다.

        char Arr[10] = "aaaaa";
        const char* CPtr = Arr;
        char* NPtr = Arr;
        //char* NPtr2 = CPtr;
        // const가 붙어있지 않은 참조형 자료형에
        // const를 붙일수는 있다.
        // const가 붙어있는 참조형 자료형에
        // const를 뗄수는 없다.
        // (사실 const_cast를 이용해 뗄 수 있지만 그딴거 왜씀?)
    }
}