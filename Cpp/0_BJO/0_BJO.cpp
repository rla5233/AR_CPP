#include <iostream>
#include <vector>

using namespace std;

void ColorPaper();
void SetPaper(vector<vector<int>>& _Board, int _Number);

// 10163
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ColorPaper();

	return 0;
}

void ColorPaper()
{
	int N = 0;
	cin >> N;

	vector<vector<int>> Board(1001, vector<int>(1001));
	for (int i = 1; i <= N; ++i)
	{
		SetPaper(Board, i);
	}
}

void SetPaper(vector<vector<int>>& _Board, int _Number)
{
	int x = 0, y = 0, width = 0, height = 0;
	cin >> x >> y >> width >> height;
	
	for (int i = y; i < y + height; ++i)
	{
		for (int j = x; j < x + width; ++j)
		{
			_Board[i][j] = _Number;
		}
	}
}
