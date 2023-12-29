#include <iostream>
#include <vector>
using namespace std;

class Problem
{
public:
	void JBoxProblem();

private:
};

class JBox
{
public:
	void SetBoxVec();
	void PrintJBox();

	inline void SetSize() { cin >> m_Size; }

private:
	int m_Size = 0;
	vector<string> m_BoxVec = vector<string> ();
};


// 12790
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Problem NewProblem = Problem();
	NewProblem.JBoxProblem();
	

	return 0;
}

void Problem::JBoxProblem()
{
	int TestCase = 0;
	cin >> TestCase;

	JBox NewJBox = JBox();

	for (int i = 0; i < TestCase; i++)
	{
		NewJBox.SetSize();
		NewJBox.SetBoxVec();
		NewJBox.PrintJBox();
	}
}

void JBox::SetBoxVec()
{
	m_BoxVec.clear();

	string temp = "";

	for (int i = 0; i < m_Size; i++)
	{
		for (int j = 0; j < m_Size; j++)
		{
			if (i == 0 || i == m_Size - 1 ||
				j == 0 || j == m_Size - 1)
			{
				temp += '#';
			}
			else
			{
				temp += 'J';
			}

		}

		m_BoxVec.push_back(temp);
		temp = "";
	}
}

void JBox::PrintJBox()
{
	for (int i = 0; i < m_BoxVec.size(); i++)
	{
		cout << m_BoxVec[i] << "\n";
	}

	cout << "\n";
}