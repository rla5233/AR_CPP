#include <iostream>
#include <vector>
using namespace std;

class Goldbach
{
public:
	Goldbach() {}
	
	void SetPrimeVec()
	{
		m_PrimeVec.assign(1000001, true);
		
		for (int i = 2; i < m_PrimeVec.size(); i++)
		{
			if (m_PrimeVec[i] == true)
			{
				for (int j = i * 2; j < m_PrimeVec.size(); j += i)
				{
					m_PrimeVec[j] = false;
				}

				if (i % 2 == 0)
				{
					m_PrimeVec[i] = false;
				}
			}
		}
	}

	void CheckConjecture(int _Number)
	{
		int Left = 0, Right = _Number;

		Left = 3;
		while (!m_PrimeVec[Right])
		{
			--Right;
		}

		while (Left < Right)
		{
			if (Left + Right == _Number)
			{
				printf("%d = %d + %d\n", _Number, Left, Right);
				return;
			}

		}

		cout << "Goldbach's conjecture is wrong.\n";
	}

	

protected:

private:
	vector<bool> m_PrimeVec;

};


void Problem_6588();

// 6588
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Problem_6588();

	return 0;
}

void Problem_6588()
{
	int N = 0;

	Goldbach NewGoldbach = Goldbach();
	NewGoldbach.SetPrimeVec();

	while (1)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}

		NewGoldbach.CheckConjecture(N);
	}
}