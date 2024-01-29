// 094_NewEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>

class Renderer
{
public:
    bool IsDeath = true;
    int Value = 0;

public:
    void Render()
    {
        ++Value;
    }
};

int main()
{
    // 다음과 같은 릴리즈는 문제가 있다.
    Renderer* NewRenderer = new Renderer();

    std::list<Renderer*> ActorList;
    ActorList.push_back(NewRenderer);

    std::list<Renderer*> LevelList;
    LevelList.push_back(NewRenderer);


    while (true)
    {
        for (Renderer* Render : LevelList)
        {
            Render->Render();
        }

        for (Renderer* Render : ActorList)
        {
            delete Render;
        }
        ActorList.clear();

    }
}