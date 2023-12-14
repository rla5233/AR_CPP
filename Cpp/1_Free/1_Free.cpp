#include <iostream>
using namespace std;

int main()
{
    // 그러나 포인터와 배열은 동일하지않다!
    int MonsterHps[5] = { 11, 22, 33, 44 ,55 };
    int* Ptr = MonsterHps;

    // 둘의 크기는 다르다.
    int ArrSize = sizeof(MonsterHps);
    int PtrSize = sizeof(Ptr);

    return 0;
}
