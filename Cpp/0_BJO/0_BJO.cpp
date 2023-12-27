#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class MyString
{
public:
	MyString() {}

	void SetWord() { cin >> m_OriginalWord; }
	void DivideWord(int _First, int _Second)
	{
		int b = 0;

		m_Word1 = m_OriginalWord.substr(0, _First);
		m_Word2 = m_OriginalWord.substr(_First, _Second - _First);
		m_Word3 = m_OriginalWord.substr(_Second);

		int a = 0;
	}

	void ReverseWord()
	{
		reverse(m_Word1.begin(), m_Word1.end());
		reverse(m_Word2.begin(), m_Word2.end());
		reverse(m_Word3.begin(), m_Word3.end());
	}

	void MergeWord()
	{
		m_AfterWord = m_Word1 + m_Word2 + m_Word3;
	}

	void AddWordVec()
	{
		m_WordVec.push_back(m_AfterWord);
	}

	void SortWordVec()
	{
		sort(m_WordVec.begin(), m_WordVec.end());
	}

	string GetFirstWord()
	{
		return m_WordVec[0];
	}
	
	int GetWordLength()	{ return m_OriginalWord.length(); }

protected:

private:
	string m_OriginalWord = "";
	string m_AfterWord = "";
	string m_Word1 = "";
	string m_Word2 = "";
	string m_Word3 = "";
	vector<string> m_WordVec = vector<string>();

};

void Problem_1251();

// 1251
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Problem_1251();

	return 0;
}

void Problem_1251()
{
	MyString NewMyString = MyString();
	NewMyString.SetWord();

	for (int i = 1; i <= NewMyString.GetWordLength() - 2; i++)
	{
		for (int j = i + 1; j <= NewMyString.GetWordLength() - 1; j++)
		{
			NewMyString.DivideWord(i, j);
			NewMyString.ReverseWord();
			NewMyString.MergeWord();
			NewMyString.AddWordVec();
		}
	}

	NewMyString.SortWordVec();
	cout << NewMyString.GetFirstWord();
}