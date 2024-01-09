#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Problem
{
public:
	void Problem_10610(class NumberString& _NumString) const;

private:

};

class NumberString
{
public:
	void SetNumString(string _String);
	void SortNumString();
	bool IsCanDivide();
	inline string GetNumString() { return m_NumString; }


private:
	string m_NumString = "";
};

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Problem NewProblem = Problem();
	NumberString NewNumString = NumberString();

	NewProblem.Problem_10610(NewNumString);

	return 0;
}

void Problem::Problem_10610(NumberString& _NumString) const
{
	string Input = "";
	cin >> Input;

	_NumString.SetNumString(Input);

	int a = 0;

	_NumString.SortNumString();

	if (_NumString.IsCanDivide())
	{
		cout << _NumString.GetNumString();
	}
	else
	{
		cout << -1;
	}
}

void NumberString::SetNumString(string _String)
{
	m_NumString = _String;
}

void NumberString::SortNumString()
{
	sort(m_NumString.rbegin(), m_NumString.rend());
}

bool NumberString::IsCanDivide()
{
	int temp = 0;
	if (m_NumString[m_NumString.length() - 1] != '0')
	{
		return false;
	}
	else
	{
		for (int i = m_NumString.length() - 1; i >= 0; i--)
		{
			temp += m_NumString[i] - '0';
		}

		if (temp % 3 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
