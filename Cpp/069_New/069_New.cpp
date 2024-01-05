// 069_New.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// Zone 안에는 몬스터가 있어야한다.
class Monster
{

};

class Zone
{
    // 이러면 몬스터 크기가 고정된다...
    Monster Arr[10];

};

// 메모리를 사용하는것을 메모리를 바인딩한다고 한다.
// 1. 정적 바인딩 (정적 할당)
// 2. 동적 바인딩 (동적 할당)

// 지금까지 해온 메모리 바인딩을 정적 바인딩이라고 한다.
// 내가 원하는 만큼만 -> 불가능
// 고정 메모리의 크기를 실행 중간에 유동적으로 처리할 수 가 없다.
// ex) 내 주변에 보이는 부분만 처리할 수 없다.
// -> 스택(지역변수)영역, 데이터 영역(전역변수), 코드 영역(상수)에 바인딩 된다.

int main()
{
    {
        // 이건.... 게임시작하자마자 모든 맵을 로딩시킨 것이다.
        Zone Arr[100];

        // new 연산자를 붙이면 Zone을 하나 생성하겠다.
        Zone* CurZone = new Zone();

        // 동적 할당은 사용이 끝나면 꼭 없에주어야 한다.
        delete CurZone;
    }

    // 동적 바인딩 (동적 할당)
    // 동적 할당은 힙영역을 사용한다.
    //
    // 동적 할당의 필요성
    // 1. 어떤 메모리를 원할때 원하는 만큼 생성할 수 있다.
    // 2. 동적할당을 통해 소유의 개념을 표현할 수 있다.
    //
    // 동적 바인딩이 정적 바인딩 보다 좋은거라고 생각하면 안된다.
    // 그냥 각자를 각자로 받아 들여야 한다.

    {
        Zone* CurZone = nullptr;

        if (true/*플레이어가 들어왔다면*/)
        {
            CurZone = new Zone();

            // ... 

            delete CurZone;
        }
    }

    {
        // 배열로 할당하는 방법 (중요)
        Monster* NewMonster1 = new Monster[10];

        int MonsterCount = 20;
        Monster* NewMonster2 = new Monster[MonsterCount];

        delete[] NewMonster1;
        delete[] NewMonster2;
    }
}