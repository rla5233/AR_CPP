#include <iostream>
#include <vector>
using namespace std;

void Scanner();
void MakeNewspaper(vector<string>& _Newspaper, int _R);
void ShowNewspaper(const vector<string> _Newspaper);
void RBigger(vector<string>& _Newspaper, int _ZR);
void CBigger(vector<string>& _Newspaper, int _ZC);

// 3035
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Scanner();

    return 0;
}

void Scanner()
{
    int R = 0, C = 0;
    cin >> R >> C;

    vector<string> Newspaper;
    int ZR = 0, ZC = 0;
    cin >> ZR >> ZC;

    MakeNewspaper(Newspaper, R);
    RBigger(Newspaper, ZR);
    CBigger(Newspaper, ZC);
    ShowNewspaper(Newspaper);
}

void MakeNewspaper(vector<string>& _Newspaper, int _R)
{
    string str = "";
    for (int i = 0; i < _R; i++)
    {
        cin >> str;
        _Newspaper.push_back(str);
    }

}

void ShowNewspaper(const vector<string> _Newspaper)
{
    for (int i = 0; i < _Newspaper.size(); i++)
        cout << _Newspaper[i] << "\n";
}

void RBigger(vector<string>& _Newspaper, int _ZR)
{
    vector<string> temp;
    for (int i = 0; i < _Newspaper.size(); i++)
        for (int j = 0; j < _ZR; j++)
        {
            temp.push_back(_Newspaper[i]);
        }

    swap(_Newspaper, temp);
}

void CBigger(vector<string>& _Newspaper, int _ZC)
{
    vector<string> temp;
    string str = "";
    for (int i = 0; i < _Newspaper.size(); i++)
    {
        str = "";
        for (int j = 0; j < _Newspaper[i].length(); j++)
        {
            for (int k = 0; k < _ZC; k++)
                str += _Newspaper[i][j];
        }

        temp.push_back(str);
    }

    swap(_Newspaper, temp);
}