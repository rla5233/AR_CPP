// 091_RangedFor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <map>

int main()
{
    {
        std::list<int> NewList;

        // 너무 길다.
        std::list<int>::iterator StartIter = NewList.begin();
        std::list<int>::iterator EndIter = NewList.end();

        for (; StartIter != EndIter; ++StartIter)
        {

        }
    }


    {
        std::list<int> NewList;
        for (size_t i = 0; i < NewList.size(); i++)
        {

        }
        
        // Rangedfor
        for (int i : NewList)
        {

        }

        // 주의!
        // Rangedfor 문 사용시 값을 변경하는 것은 문제가 되지 않으나
        // 메모리의 구조가 변경하는것은 문제가 된다!

        for (int& i : NewList)
        {

        }
    }

}