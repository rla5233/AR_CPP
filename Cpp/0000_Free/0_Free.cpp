#include <iostream>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i = ~0;
    cout << i << endl;

    // int 최대값
    int n = i ^ (1 << 31);
    cout << n << endl;

    n = i & 0b01111111111111111111111111111111;
    cout << n << endl;

    // int 최소값
    //n = i ^ (0b01111111111111111111111111111111);
    //cout << n << endl;

    return 0;
}