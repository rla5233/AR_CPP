// 015_Arrary.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // 몬스터가 100마리어야 한다.
    // 퀘스트가 100개어야 한다.

    // int MonsterHp0;
    // int MonsterHp1;
    // int MonsterHp2;
    // ...
    // int MonsterHp99;

    // 위처럼 만들필요 없다.

    // int[] -> int 배열형이라고 한다.
    {
        int MonsterHp[100];
    }

    {
        // 첫번째
        // [][][][] [][][][] [][][][] [][][][] [][][][]
        // 모든 변수는 붙어있게 된다. (선형구조)
        int MonsterHps[5] = { 11, 22, 33, 44 ,55 };

        // 제로베이스라고 하고 (0부터 접근)
        int MonsterHp1 = MonsterHps[0];
        int MonsterHp2 = MonsterHps[1];
        int MonsterHp3 = MonsterHps[2];
        int MonsterHp4 = MonsterHps[3];
        int MonsterHp5 = MonsterHps[4];

        __int64 Address0 = reinterpret_cast<__int64>(&MonsterHps[0]);
        __int64 Address1 = reinterpret_cast<__int64>(&MonsterHps[1]);
        __int64 Address2 = reinterpret_cast<__int64>(&MonsterHps[2]);
        __int64 Address3 = reinterpret_cast<__int64>(&MonsterHps[3]);
        __int64 Address4 = reinterpret_cast<__int64>(&MonsterHps[4]);
    }

    {
        int MonsterHps[5] = { 11, 22, 33, 44 ,55 };

        // int*    int[]
        int* Ptr = MonsterHps;

        // 배열이 사용할 수 있는 문법은 포인터도 사용할 수 있다.
        // ex) 포인터의 핵심연산중 하나인 주소이동

        // Ptr == 100 번지
        // Ptr + 1 == 100 번지 + (sizeof(int) * 1) 번지
        // Ptr + 2 == 100 번지 + (sizeof(int) * 2) 번지
        // Ptr + 3 == 100 번지 + (sizeof(int) * 3) 번지
        // Ptr + 4 == 100 번지 + (sizeof(int) * 4) 번지

        __int64 Address0 = reinterpret_cast<__int64>(Ptr + 0);
        __int64 Address1 = reinterpret_cast<__int64>(Ptr + 1);
        __int64 Address2 = reinterpret_cast<__int64>(Ptr + 2);
        __int64 Address3 = reinterpret_cast<__int64>(Ptr + 3);
        __int64 Address4 = reinterpret_cast<__int64>(Ptr + 4);

        
    }

    {
        // 그러나 포인터와 배열은 동일하지않다!
        int MonsterHps[5] = { 11, 22, 33, 44 ,55 };
        int* Ptr = MonsterHps;

        // 둘의 크기는 다르다.
        int ArrSize = sizeof(MonsterHps);
        int PtrSize = sizeof(Ptr);
    }
}