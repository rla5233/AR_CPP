#include <iostream>
using namespace std;

class Problem
{
private:

public:
	void Problem_2721(class TriNum& _TriNum);

};

class TriNum
{
private:
	int m_Tn = 0;
	int m_Wn = 0;

public:
	void SetTn(int _N);
	void SetWn(int _N);

	inline int GetWn() const { return m_Wn; }
};

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Problem NewProblem = Problem();
	TriNum NewTriNum = TriNum();
	NewProblem.Problem_2721(NewTriNum);

	return 0;
}

void Problem::Problem_2721(TriNum& _TriNum)
{
	int TestCase = 0;
	cin >> TestCase;

	int N = 0;
	for (int i = 0; i < TestCase; i++)
	{
		cin >> N;
		_TriNum.SetWn(N);
		cout << _TriNum.GetWn() << "\n";
	}
}

void TriNum::SetTn(int _N)
{
	m_Tn = _N * (_N + 1) / 2;
}

void TriNum::SetWn(int _N)
{
	int Result = 0;
	for (int i = 1; i <= _N; i++)
	{
		SetTn(i + 1);
		Result += i * m_Tn;
	}

	m_Wn = Result;
}