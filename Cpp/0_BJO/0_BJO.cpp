#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Problem
{
public:
	void Problem_11008(class Typing& _Typing) const;

private:

};

class Typing
{
public:
	void FindMinTime();

	inline void SetCopy(string _Copy)
	{
		m_Copy = _Copy;
	}
	inline void SetGoal(string _Goal)
	{
		m_Goal = _Goal;
	}
	inline int GetTime() const 
	{
		return m_Time;
	};

private:
	string m_Copy = "";
	string m_Goal = "";
	int m_Time = 0;
};

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Problem NewProblem = Problem();
	Typing NewCopy = Typing();

	NewProblem.Problem_11008(NewCopy);

	return 0;
}

void Problem::Problem_11008(Typing& _Typing) const
{
	int TestCase = 0;
	cin >> TestCase;

	string str = "";
	for (int i = 0; i < TestCase; i++)
	{
		cin >> str;
		_Typing.SetGoal(str);

		cin >> str;
		_Typing.SetCopy(str);

		_Typing.FindMinTime();
		cout << _Typing.GetTime() << "\n";
	}
}

void Typing::FindMinTime()
{
	m_Time = 0;
	int i = 0;
	while(i < m_Goal.length())
	{
		if (m_Goal[i] == m_Copy[0])
		{
			if (m_Goal.substr(i, m_Copy.length()) == m_Copy)
			{
				++m_Time;
				i += m_Copy.length();
				continue;
			}
		}		
		
		++m_Time;
		++i;		
	}
}