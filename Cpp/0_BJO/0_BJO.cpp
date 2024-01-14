#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Problem
{
public:
	void Problem_12788(class IUPC& _IUPC) const;

private:

};

class IUPC
{
public:
	void SortCTPPen();
	void BorrowPen();
	
	void SetCTPPen();
	void SetCTP(int _Num);
	void SetParticipent(int _Num);

	inline bool CanBorrow() const { return m_CanBorrow; }
	inline int GetBorrowCTP() const { return m_BorrowCTP; }

private:
	int m_CTP = 0;
	int m_Participent = 0;
	int m_BorrowCTP = 0;
	bool m_CanBorrow = false;
	vector<int> m_CTPPen = vector<int>();
};


int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Problem NewProblem = Problem();
	IUPC NewIUPC = IUPC();
	NewProblem.Problem_12788(NewIUPC);

	return 0;
}

void Problem::Problem_12788(IUPC& _IUPC) const
{
	int N = 0;
	cin >> N;
	_IUPC.SetCTP(N);

	int M = 0, K = 0;
	cin >> M >> K;
	_IUPC.SetParticipent(M * K);

	_IUPC.SetCTPPen();
	_IUPC.SortCTPPen();

	_IUPC.BorrowPen();

	if (_IUPC.CanBorrow())
	{
		cout << _IUPC.GetBorrowCTP();
	}
	else
	{
		cout << "STRESS";
	}
}

void IUPC::SetCTP(int _Num)
{
	m_CTP = _Num;
}

void IUPC::SetParticipent(int _Num)
{
	m_Participent = _Num;
}

void IUPC::SetCTPPen()
{
	m_CTPPen.assign(m_CTP, 0);
	for (int i = 0; i < m_CTP; i++)
	{
		cin >> m_CTPPen[i];
	}
}

void IUPC::SortCTPPen()
{
	sort(m_CTPPen.rbegin(), m_CTPPen.rend());
}

void IUPC::BorrowPen()
{
	int count = 0;
	m_CanBorrow = false;
	for (int i = 0; i < m_CTPPen.size(); i++)
	{
		count += m_CTPPen[i];
		if (count >= m_Participent)
		{
			m_BorrowCTP = i + 1;
			m_CanBorrow = true;
			return;
		}
	}
}