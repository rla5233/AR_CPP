#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void FinalWinner();
void CardInput(vector<vector<int>>& _Card, int _N, int _M);
void FindWinner(vector<int>& _Score);

// 12756
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	FinalWinner();

	return 0;
}

void FinalWinner()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<vector<int>> Card;
	CardInput(Card, N, M);

	vector<int> Score(N);
	for (int i = 0; i < M; ++i)
	{
		int max = 0;
		for (int j = 0; j < Card.size(); j++)
		{
			if (max < Card[j][i])
			{
				max = Card[j][i];
			}
		}
	

		for (int j = 0; j < Card.size(); j++)
		{
			if (max == Card[j][i])
			{
				++Score[j];
			}
		}

	}

	FindWinner(Score);
}

void CardInput(vector<vector<int>>& _Card, int _N, int _M)
{
	while (_N--)
	{
		vector<int> card(_M);
		for (int i = 0; i < _M; ++i)
		{
			cin >> card[i];
		}
		
		sort(card.rbegin(), card.rend());
		_Card.push_back(card);
	}
}

void FindWinner(vector<int>& _Score)
{
	int max = 0;
	for (int i = 0; i < _Score.size(); ++i)
	{
		if (max < _Score[i])
		{
			max = _Score[i];
		}
	}

	for (int i = 0; i < _Score.size(); ++i)
	{
		if (max == _Score[i])
		{
			cout << i + 1 << " ";
		}
	}
}