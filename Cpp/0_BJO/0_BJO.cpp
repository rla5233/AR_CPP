#include <iostream>
#include <string>
using namespace std;

class Problem
{
private:

public:
	void Problem_1769(class NumString& _NumString);

};

class NumString
{
private:
	string m_Num = "";
	int m_ChangeCount = 0;

public:
	void ChangeNum();
	bool CheckNum_3M();

	inline void ChangeCountUP() { ++m_ChangeCount; }
	inline void SetNum(string _Num) { m_Num = _Num; }
	inline int GetChangeCount() const { return m_ChangeCount; }
	inline int GetNumStringLen() const { return static_cast<int>(m_Num.length()); }
};


int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Problem NewProblem = Problem();
	NumString NewNumString = NumString();
	NewProblem.Problem_1769(NewNumString);

	return 0;
}

void Problem::Problem_1769(NumString& _NumString)
{
	string num = "";
	cin >> num;

	_NumString.SetNum(num);

	while (_NumString.GetNumStringLen() > 1)
	{
		_NumString.ChangeNum();
	}

	cout << _NumString.GetChangeCount() << "\n";
	if (_NumString.CheckNum_3M())
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}

void NumString::ChangeNum()
{
	int num = 0;
	for (int i = 0; i < m_Num.length(); i++)
	{
		num += m_Num[i] - '0';
	}

	int a = 0;

	ChangeCountUP();
	SetNum(to_string(num));
}

bool NumString::CheckNum_3M()
{
	int num = stoi(m_Num);
	if (num % 3 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}