#include <iostream>
using namespace std;

#define WIDTH 3
#define HEIGHT 3

const char BACKGROUND = '*';

void Problem_12759();

class Pos
{
public:
	int X = 0;
	int Y = 0;
};

class TicTacToe
{
public:
	TicTacToe() {}
	TicTacToe(char _BackGround)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			for (int x = 0; x < WIDTH; x++)
			{
				m_board[y][x] = _BackGround;
			}
		}
	}

	void Drawing(const Pos& _Pos, int _Char)
	{
		Drawing(_Pos.Y, _Pos.X, _Char);
	}

	inline void Drawing(int _Y, int _X, int _Char)
	{
		m_board[_Y - 1][_X - 1] = _Char;
	}

	void Check()
	{
		string check = "";

		// 가로 체크
		for (int y = 0; y < HEIGHT; y++)
		{
			check = "";
			for (int x = 0; x < WIDTH; x++)
			{
				check += m_board[y][x];
			}

			WinnerCheck(check);
			if (m_isfinish)
			{
				return;
			}
		}

		// 세로 체크
		for (int x = 0; x < WIDTH; x++)
		{
			check = "";
			for (int y = 0; y < HEIGHT; y++)
			{
				check += m_board[y][x];
			}

			WinnerCheck(check);
			if (m_isfinish)
			{
				return;
			}
		}

		// 대각선 체크
		check = "";
		for (int i = 0; i < WIDTH; i++)
		{
			check += m_board[i][i];
		}

		WinnerCheck(check);
		if (m_isfinish)
		{
			return;
		}

		check = "";
		for (int i = 0; i < WIDTH; i++)
		{
			check += m_board[i][WIDTH - i - 1];
		}

		WinnerCheck(check);
		if (m_isfinish)
		{
			return;
		}

		// 무승부 체크
		bool IsDraw = true;
		for (int y = 0; y < HEIGHT; y++)
		{
			for (int x = 0; x < WIDTH; x++)
			{
				if (m_board[y][x] == BACKGROUND)
				{
					IsDraw = false;
				}
			}
		}

		if (IsDraw)
		{
			m_winner = 0;
			m_isfinish = true;
		}
	}
	
	void WinnerCheck(string _Draw)
	{

		int a = 0;

		if (_Draw == "111")
		{
			m_winner = 1; 
			m_isfinish = true;
		}
		else if (_Draw == "222")
		{
			m_winner = 2;
			m_isfinish = true;
		}
	}

	inline bool GetIsFinish() { return m_isfinish; }
	inline int GetWinner() { return m_winner; }

protected:

private:
	char m_board[3][4] = { 0, };
	int m_winner = 0;
	bool m_isfinish = false;
};

class Player
{
public:
	Player() {}
	Player(int _Number) : m_Number(_Number) {}
	
	void SetPosInput()
	{
		int x = 0, y = 0;
		cin >> y >> x;
		SetPos(y, x);
	}

	void SetPos(const Pos& _Pos)
	{
		SetPos(_Pos.Y, _Pos.X);
	}

	void SetPos(int _PosY, int _PosX) 
	{ 
		m_Pos.X = _PosX; 
		m_Pos.Y = _PosY;
	}

	inline int GetNumber() { return m_Number; }
	inline Pos GetPos() { return m_Pos; }


protected:

private:
	Pos m_Pos = { 0 ,0 };
	int m_Number = 0;
};

// 12759
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Problem_12759();

	return 0;
}

void Problem_12759()
{
	int P1_Number = 0;
	cin >> P1_Number;

	TicTacToe Game = TicTacToe(BACKGROUND);
	Player P1 = Player(P1_Number);
	Player P2 = Player(P1_Number == 1 ? 2 : 1);

	while (1)
	{
		P1.SetPosInput();
		Game.Drawing(P1.GetPos(), P1.GetNumber() + '0');
		Game.Check();
		if (Game.GetIsFinish())
		{
			cout << Game.GetWinner();
			break;
		}

		P2.SetPosInput();
		Game.Drawing(P2.GetPos(), P2.GetNumber() + '0');
		Game.Check();
		if (Game.GetIsFinish())
		{
			cout << Game.GetWinner();
			break;
		}
	}
}