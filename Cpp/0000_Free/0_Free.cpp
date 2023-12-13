#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Hotel();
void CountRoom(int n, int m);
bool CheckRoom(int n);

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Hotel();

    return 0;
}

void Hotel()
{
    int N, M;
    while (1)
    {
        cin >> N >> M;
        if (cin.eof())
            break;

        CountRoom(N, M);
    }
}

void CountRoom(int n, int m)
{
    int count = 0;
    for (int i = n; i <= m; i++)
    {
        if (CheckRoom(i))
            count++;
    }

    cout << count << "\n";
}

    // int 최소값
    //n = i ^ (0b01111111111111111111111111111111);
    //cout << n << endl;

    return true;
}