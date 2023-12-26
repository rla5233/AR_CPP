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
		
		for (int i = 2; i * i < m_PrimeVec.size(); i++)
		{
			if (m_PrimeVec[i] == true)
			{
				for (int j = i * i; j < m_PrimeVec.size(); j += i)
				{
					m_PrimeVec[j] = false;
				}
			}
		}
	}

	void CheckConjecture(int _Number)
	{
		int Left = 3, Right = _Number - 3;

		while (Left <= Right)
		{
			if (m_PrimeVec[Left] && m_PrimeVec[Right])
			{
				printf("%d = %d + %d\n", _Number, Left, Right);
				return;
			}

			Left += 2;
			Right -= 2;
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