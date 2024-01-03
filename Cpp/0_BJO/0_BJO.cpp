#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Problem
{
private:

public:
	void Problem_2204(class Word& _Word);

};

class Word
{
public:

private:
	vector<string> m_StringVec = vector<string>();

public:
	void InputStringVec();
	void SortVec();
	void ClearVec();
	string GetVecFirstWord();

	bool compare(string _str1, string _str2);
};

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Problem NewProblem = Problem();
	Word NewWord = Word();

	NewProblem.Problem_2204(NewWord);

	return 0;
}

void Problem::Problem_2204(Word& _Word)
{
	int TestCase = 0;
	
	while (true)
	{
		cin >> TestCase;
		if (TestCase == 0)
		{
			return;
		}

		for (int i = 0; i < TestCase; i++)
		{
			_Word.InputStringVec();
		}

		_Word.SortVec();
		cout << _Word.GetVecFirstWord() << "\n";
		_Word.ClearVec();
	}
}

void Word::InputStringVec()
{
	string str = "";
	cin >> str;
	m_StringVec.push_back(str);
}

void Word::SortVec()
{
	sort(m_StringVec.begin(), m_StringVec.end(), compare);
}

void Word::ClearVec()
{
	m_StringVec.clear();
}

string Word::GetVecFirstWord()
{
	return *(m_StringVec.begin());
}

bool Word::compare(string _str1, string _str2)
{
	return _str1 < _str2;
}
