// 021_OperatorEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Plus(int _Left, int _Right)
{
    return _Left + _Right;
}

void PlusSub(int& _Left, int _Right)
{
    _Left = _Left + _Right;
}

// 전위 증가 연산자
int PPFirst(int& _Value)
{
    _Value = _Value + 1;
    return _Value;
}

// 후위 증가 연산자
int PPBack(int& _Value)
{
    int ret = _Value;
    _Value = _Value + 1;
    return ret;
}

int main()
{
    // 아래 둘은 같은 결과
    {
        int Result = Plus(10, 10);  
    }

    {
        int Result = 10 + 10;
    }

    {
        int Value = 0;
        // 너무나도 많이 사용하는 꼴이고
        // 코드가 간결해지기 때문에 등장했다.
        Value += 10; 
        Value = Value + 10;
        PlusSub(Value, 10);
    }

    {
        int Value = 0;
        // 너무나도 많이 사용하는 꼴이고
        // 코드가 간결해지기 때문에 등장했다.
        ++Value;
        Value++;
        
        int Result = PPFirst(Value);
        Result = PPBack(Value);
    }

}