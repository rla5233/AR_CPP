#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Problem
{
private:

public:
	void Problem_6603(class Lotto& _Lotto) const;

};

class Lotto
{
public:
	Lotto() {}
	~Lotto() {}

	void AddNum_S(int _Num);
	void Clear();
	void PrintAllCase();

private:
	const int m_Count = 6;
	vector<int> m_SVec = vector<int>();
};

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Problem NewProblem = Problem();
	Lotto NewLotto = Lotto();

	NewProblem.Problem_6603(NewLotto);

	return 0;
}

void Problem::Problem_6603(Lotto& _Lotto) const
{
	while (true)
	{
		int K = 0;
		cin >> K;
		if (K == 0)
		{
			break;
		}

		for (int i = 0; i < K; i++)
		{
			int num = 0;
			cin >> num;
			_Lotto.AddNum_S(num);
		}

		_Lotto.PrintAllCase();
		_Lotto.Clear();
	}
}

void Lotto::AddNum_S(int _Num)
{
	m_SVec.push_back(_Num);
}


void Lotto::Clear()
{
	m_SVec.clear();
}

void Lotto::PrintAllCase()
{
	for (int a = 0; a < (m_SVec.size() - m_Count) + 1; a++)
	{
		for (int b = a + 1; b < (m_SVec.size() - m_Count) + 2; b++)
		{
			for (int c = b + 1; c < (m_SVec.size() - m_Count) + 3; c++)
			{
				for (int d = c + 1; d < (m_SVec.size() - m_Count) + 4; d++)
				{
					for (int e = d + 1; e < (m_SVec.size() - m_Count) + 5; e++)
					{
						for (int f = e + 1; f < (m_SVec.size() - m_Count) + 6; f++)
						{
							cout << m_SVec[a] << " ";
							cout << m_SVec[b] << " ";
							cout << m_SVec[c] << " ";
							cout << m_SVec[d] << " ";
							cout << m_SVec[e] << " ";
							cout << m_SVec[f] << "\n";
						}
					}
				}
			}
		}
	}

	cout << "\n";
}
