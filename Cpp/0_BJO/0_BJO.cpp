#include <iostream>
using namespace std;

void Eureka();
bool isEureka(int _Num);

// 6588
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Eureka();

    return 0;
}

void Eureka()
{
    int T = 0;
    cin >> T;

    int number = 0;
    while (T--)
    {
        cin >> number;
        if (isEureka(number))
        {

        }
    }
}

bool isEureka(int _Num)
{
    return false;
}
