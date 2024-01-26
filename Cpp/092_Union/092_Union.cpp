// 092_Union.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>

// 구조체의 크기는 바이트패딩 규칙에 따라 결정된다.
struct MyStruct
{
    int A;
    int B;
};
// [][][][] [][][][]
// A        B

// 공용체의 크기는 내부의 자료형중 
// 무조건 가장 큰 자료형으로 자신의 크기를 잡는다.
union MyUnion
{
    int A;
    int B;
    __int64 Value;
};
// [][][][][][][][]
// Value
// A
// B

// class struct union 은 따로 이름을 안붙일수가 있다.
// 
//struct -> 내부에 존재하는 변수의 메모리를 struct형으로 구성해줘
//{
//    int X;
//    int Y;
//};


// 타일맵에서 key 값으로 이용할 수 있다.
struct TileMapKey
{
    union
    {
        struct
        {
            int X;
            int Y;
        };
        __int64 Key;
    };
};

struct Tile
{
    int SpriteIndex = 0;
};

int main()
{
    int sizeS = sizeof(MyStruct);
    int sizeU = sizeof(MyUnion);

    int a = 0;

    TileMapKey NewKey = { 5, 5 };
    std::map<__int64, Tile> NewTileMap;
    NewTileMap[NewKey.Key] = Tile();

    int b = 0;
}