#include <iostream>
#include <vector>
using namespace std;

class Problem
{
private:

public:
	void Problem_1145(class Number& _Number) const;

};

class Number
{
private:
	vector<int> m_NumVec = vector<int>();
	int m_LeastMultipleNum = -1;

public:
	void SetNumVec();
	void FindLeastMultipleNum();

	int GCD(int _Num1, int _Num2);
	int LCM(int _Num1, int _Num2);
	
	inline void SetLeastMultipleNum(int _Num) {	m_LeastMultipleNum = _Num; }
	inline int GetLeastMultipleNum() const { return m_LeastMultipleNum; }
};

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Problem NewProblem = Problem();
	Number NewNumber = Number();
	NewProblem.Problem_1145(NewNumber);

	return 0;
}

void Problem::Problem_1145(Number& _Number) const  
{
	for (int i = 0; i < 5; i++)
	{
		_Number.SetNumVec();
	}

	_Number.FindLeastMultipleNum();
	cout << _Number.GetLeastMultipleNum();
}

void Number::SetNumVec()
{
	int Num = 0;
	cin >> Num;
	m_NumVec.push_back(Num);
}

void Number::FindLeastMultipleNum()
{
	int temp1 = 0, temp2 = 0;;
	for (int i = 0; i < m_NumVec.size() - 2; i++)
	{
		for (int j = i + 1; j < m_NumVec.size()-1; j++)
		{
			for (int k = j + 1; k < m_NumVec.size(); k++)
			{
				temp1 = LCM(m_NumVec[i], m_NumVec[j]);
				temp2 = LCM(m_NumVec[k], temp1);
				
				if (temp2 < m_LeastMultipleNum || m_LeastMultipleNum == -1)
				{
					SetLeastMultipleNum(temp2);
				}				
			}
		}
	}
}

int Number::GCD(int _Num1, int _Num2)
{
	while (_Num2 != 0)
	{
		int r = _Num1 % _Num2;
		_Num1 = _Num2;
		_Num2 = r;
	}

	return _Num1;
}

int Number::LCM(int _Num1, int _Num2)
{
	return (_Num1 * _Num2) / GCD(_Num1, _Num2);
}