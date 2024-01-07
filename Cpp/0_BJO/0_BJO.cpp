#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Problem
{
private:

public:
	void Problem_3568(class iSharp& _iSharp) const;

};

class iSharp
{
private:
	string m_iSharpType = "";
	string m_BaseType = "";
	string m_VarName = "";
	string m_ExtraType = "";
	vector<string> m_OrgTypeVec = vector<string>();


public:
	void ConvertOrgType();
	void FindBaseType();
	void FindVarName(int& _Index);
	void FindExtraType(int& _Index);
	void PrintOrgTypeVec();

	inline void SetiSharpType(string _String) { m_iSharpType = _String; }

};


int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Problem NewProblem = Problem();
	iSharp NewiSharp = iSharp();

	NewProblem.Problem_3568(NewiSharp);

	return 0;
}

void Problem::Problem_3568(iSharp& _iSharp) const
{
	string Input = "";
	getline(cin, Input);

	_iSharp.SetiSharpType(Input);
	_iSharp.ConvertOrgType();
	_iSharp.PrintOrgTypeVec();
}

void iSharp::ConvertOrgType()
{
	FindBaseType();

	int idx = static_cast<int>(m_BaseType.length());
	while (m_iSharpType[idx] != ';')
	{
		FindVarName(idx);
		FindExtraType(idx);
		m_OrgTypeVec.push_back(m_BaseType + m_ExtraType + " " + m_VarName + ";");
	}


}

void iSharp::FindBaseType()
{
	for (int i = 0; i < m_iSharpType.length(); i++)
	{
		if (m_iSharpType[i] == ' ')
		{
			return;
		}

		m_BaseType += m_iSharpType[i];
	}
}

void iSharp::FindVarName(int& _Index)
{
	m_VarName = "";
	++_Index;
	for (_Index; _Index < m_iSharpType.length(); _Index++)
	{
		switch (m_iSharpType[_Index])
		{
			case '*':	case '[':	case '&':
			case ',':	case ';':
			{
				return;
			}
			default:
			{
				if (m_iSharpType[_Index] != ' ')
				{
					m_VarName += m_iSharpType[_Index];
				}
				break;
			}
		}
	}
}

void iSharp::FindExtraType(int& _Index)
{
	m_ExtraType = "";
	for (_Index; _Index < m_iSharpType.length(); _Index++)
	{
		if (m_iSharpType[_Index] == ',' || m_iSharpType[_Index] == ';')
		{
			reverse(m_ExtraType.begin(), m_ExtraType.end());
			return;
		}
		else
		{
			if (m_iSharpType[_Index] == '[')
			{
				m_ExtraType += "]";
			}
			else if (m_iSharpType[_Index] == ']')
			{
				m_ExtraType += "[";
			}
			else
			{
				m_ExtraType += m_iSharpType[_Index];
			}
		}
	}
}

void iSharp::PrintOrgTypeVec()
{
	for (int i = 0; i < m_OrgTypeVec.size(); i++)
	{
		cout << m_OrgTypeVec[i] << "\n";
	}
}