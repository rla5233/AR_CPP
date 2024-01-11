#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Problem
{
public:
	void Problem_1120(class String& _Str) const;

private:

};

class String
{
public:
	inline void SetStringA(string _Str)
	{
		m_StringA = _Str;
	};

	inline void SetStringB(string _Str)
	{
		m_StringB = _Str;
	};

	inline int GetDiff()
	{
		return m_Diff;
	}

	void SetMinDiff();

private:
	string m_StringA = "";
	string m_StringB = "";
	int m_Diff = -1;
};

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Problem NewProblem = Problem();
	String NewString = String();

	NewProblem.Problem_1120(NewString);

	return 0;
}


void Problem::Problem_1120(String& _Str) const
{
	string Input = "";

	cin >> Input;
	_Str.SetStringA(Input);

	cin >> Input;
	_Str.SetStringB(Input);

	_Str.SetMinDiff();
	cout << _Str.GetDiff(); 

}

void String::SetMinDiff()
{
	m_Diff = -1;
	int Len_Diff = m_StringB.length() - m_StringA.length();
	for (int j = 0; j <= Len_Diff; j++)
	{
		int Diff = 0;
		for (int i = 0; i < m_StringA.length(); i++)
		{
			if (m_StringA[i] != m_StringB[i + j])
			{
				++Diff;
			}
		}

		if (Diff < m_Diff || m_Diff == -1)
		{
			m_Diff = Diff;
		}
	}
}