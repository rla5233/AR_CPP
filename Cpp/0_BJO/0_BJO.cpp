#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Problem
{
public:
	void Problem_1213(class Name& _Name) const;

private:

};

class Name
{
public:
	void SetName(string _Name);
	void SetPalindrome();

	inline string GetPalindrome() { return m_Palindrome; }
	inline bool IsPalindrome() { return m_IsPalindrome; }

private:
	string m_Name = "";
	string m_Palindrome = "";
	vector<int> m_Alpha = vector<int>(26, 0);

	bool m_IsPalindrome = false;
};

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Problem NewProblem = Problem();
	Name NewName = Name();

	NewProblem.Problem_1213(NewName);

	return 0;
}

void Problem::Problem_1213(class Name& _Name) const
{
	string Input = "";
	cin >> Input;

	_Name.SetName(Input);
	_Name.SetPalindrome();

	if (_Name.IsPalindrome())
	{
		cout << _Name.GetPalindrome();
	}
	else
	{
		cout << "I'm Sorry Hansoo";
	}
}

void Name::SetName(string _Name)
{
	m_Name = _Name;
}

void Name::SetPalindrome()
{
	int odd_Count = 0;
	
	for (int i = 0; i < m_Name.length(); i++)
	{
		++m_Alpha[m_Name[i] - 'A'];
	}

	for (int i = 0; i < m_Alpha.size(); i++)
	{
		if (m_Alpha[i] % 2 != 0)
		{
			++odd_Count;
		}
	}

	if (odd_Count > 1)
	{
		m_IsPalindrome = false;
	}
	else
	{
		m_IsPalindrome = true;

		string temp1 = "";
		string temp2 = "";
		char odd = ' ';
		for (int i = 0; i < m_Alpha.size(); i++)
		{
			while (m_Alpha[i] > 0)
			{
				if (m_Alpha[i] % 2 == 0)
				{
					temp1 += 'A' + i;
					temp2 += 'A' + i;
					m_Alpha[i] -= 2;
				}
				else
				{
					odd = 'A' + i;
					if (m_Alpha[i] != 1)
					{
						temp1 += 'A' + i;
						temp2 += 'A' + i;
						m_Alpha[i] -= 2;
					}
					else
					{
						--m_Alpha[i];
					}
				}
			}
		}

		if (odd != ' ')
		{
			temp1 += odd;
		}

		reverse(temp2.begin(), temp2.end());
		m_Palindrome = temp1 + temp2;
	}
}