#include <iostream>
#include <algorithm>
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
	void SortName();
	void SetPalindrome();

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
	_Name.SortName();
	_Name.SetPalindrome();


}

void Name::SetName(string _Name)
{
	m_Name = _Name;
}

void Name::SortName()
{
	sort(m_Name.begin(), m_Name.end());
}

void Name::SetPalindrome()
{
	string name = m_Name;
	do
	{
		string temp = name;
		reverse(name.begin(), name.end());

		if (temp == name)
		{
			m_Palindrome = name;
			m_IsPalindrome = true;
		}

	} while (next_permutation(name.begin(), name.end()));

	m_IsPalindrome = false;
}
