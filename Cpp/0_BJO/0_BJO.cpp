#include <iostream>
#include <cmath>
using namespace std;

class Problem
{
public:
	void Problem_11312(class Equilateral& _RecA, class Equilateral& _RecB);

private:

};

class Equilateral
{
private:
	int m_Side = 0;

public:
	inline void SetSide() { cin >> m_Side; }
	inline int GetSide() { return m_Side; }

};


int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Problem NewProblem = Problem();
	Equilateral NewEquilateral1 = Equilateral();
	Equilateral NewEquilateral2 = Equilateral();

	NewProblem.Problem_11312(NewEquilateral1, NewEquilateral2);

	return 0;
}

void Problem::Problem_11312(Equilateral& _RecA, Equilateral& _RecB)
{
	int TestCase = 0;
	cin >> TestCase;

	for (int i = 0; i < TestCase; i++)
	{
		_RecA.SetSide();
		_RecB.SetSide();

		cout << static_cast<long long>(pow(_RecA.GetSide() / _RecB.GetSide(), 2)) << "\n";
	}
}