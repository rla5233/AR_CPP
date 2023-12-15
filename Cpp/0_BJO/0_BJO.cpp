#include <iostream>
#include <vector>
using namespace std;

void Bingo();
void MakeBingo(vector<vector<int>> & _Bingo);
void CallBingo(vector<vector<int>> & _Bingo);
void DeleteCall(vector<vector<int>>& _Bingo, int _Call);
int FindBingoCount(vector<vector<int>>& _Bingo);
int CheckRow(vector<vector<int>>& _Bingo);

// 2578
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Bingo();

    return 0;
}

void Bingo()
{
    vector<vector<int>> bingo;
    MakeBingo(bingo);
    CallBingo(bingo);
}

void MakeBingo(vector<vector<int>>& _Bingo)
{
    vector<int> v(5);
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> v[j];
        }

        _Bingo.push_back(v);
    }
}

void CallBingo(vector<vector<int>>& _Bingo)
{
    vector<int> Call(25);
    for (int i = 0; i < 25; ++i)
    {
        cin >> Call[i];
    }

    int count = 0;
    for (int i = 0; i < Call.size(); ++i)
    {
        DeleteCall(_Bingo, Call[i]);
        count = FindBingoCount(_Bingo);
        if (count >= 3)
        {
            cout << i + 1;
            return;
        }
    }
}

void DeleteCall(vector<vector<int>>& _Bingo, int _Call)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (_Bingo[i][j] == _Call)
            {
                _Bingo[i][j] = 0;
                return;
            }
        }
    }
}

int FindBingoCount(vector<vector<int>>& _Bingo)
{
    int count = 0;
    count += CheckRow(_Bingo);
    //CheckCol();
    //CheckDia();

    return count;
}

int CheckRow(vector<vector<int>>& _Bingo)
{


    return 0;
}
