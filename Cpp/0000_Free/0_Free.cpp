#include <iostream>
#include <string>
using namespace std;

int GM_MaxNumber(int _N);

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    cout << GM_MaxNumber(N);

    return 0;
}

int GM_MaxNumber(int _N)
{
    string s;
    for (int i = _N; i >= 4; i--)
    {
        s = to_string(i);

    }

    return 0;
}
