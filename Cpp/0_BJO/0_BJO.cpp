#include <iostream>
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

	inline void SetK(int _K) { m_K = _K; }
	void SetS_ByInput();

private:
	int m_K = 0;
	string m_S = "";
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
		_Lotto.SetK(K);

	}
}

void Lotto::SetS_ByInput()
{}
