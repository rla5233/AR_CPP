// 045_TextRpgClassVer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// ----------------------------------------
class Player
{
public:
	Player()
	{
	}

	void StatusRender()
	{
		// 메모리에 관련된 명확한 설명은 안한 상태지만
		// 자신의 멤버함수에서 자신의 멤버변수는 자유롭게 사용가능하다.
		int count = printf_s("%s ", Name);
		for (int i = 0; i < 50 - count; i++)
		{
			printf_s("-");
		}

		printf_s("\n공격력 %d", Att);
		printf_s("\n체력 %d\n", Hp);

		for (int i = 0; i < 50; i++)
		{
			printf_s("-");
		}

		printf_s("\n");
	}

	void DamageLogic(int _Att)
	{
		Hp -= _Att;
	}

	void DamageRender()
	{
		printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", Name, Att);
	}

	bool IsDeath() { return Hp <= 0; }

	int GetHp() { return Hp; }
	int GetAtt() { return Att; }

protected:

private:
	char Name[100] = "Fighter";
	int Hp = 100;
	int Att = 10;
};

class Monster
{
public:
	Monster()
	{
	}

	void StatusRender()
	{
		// 메모리에 관련된 명확한 설명은 안한 상태지만
		// 자신의 멤버함수에서 자신의 멤버변수는 자유롭게 사용가능하다.
		int count = printf_s("%s ", Name);
		for (int i = 0; i < 50 - count; i++)
		{
			printf_s("-");
		}

		printf_s("\n공격력 %d", Att);
		printf_s("\n체력 %d\n", Hp);

		for (int i = 0; i < 50; i++)
		{
			printf_s("-");
		}

		printf_s("\n");
	}

	void DamageLogic(int _Att)
	{
		Hp -= _Att;
	}

	void DamageRender()
	{
		printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", Name, Att);
	}

	bool IsDeath() { return Hp <= 0; }

	int GetHp() { return Hp; }
	int GetAtt() { return Att; }

protected:

private:
	char Name[100] = "Orc";
	int Hp = 50;
	int Att = 5;
};


int main()
{
	Player NewPlayer = Player();
	Monster NewMonster = Monster();

	// 메인 루프
	while (true)
	{
		NewPlayer.StatusRender();
		NewMonster.StatusRender();

		{
			int Input = _getch();
			system("cls");

			NewMonster.DamageLogic(NewPlayer.GetAtt());
			NewPlayer.StatusRender();
			NewMonster.StatusRender();
			NewPlayer.DamageRender();
		}

		if (NewPlayer.IsDeath() || NewMonster.IsDeath())
		{
			printf_s("게임종료\n");
			break;
		}

		{
			int Input = _getch();

			NewPlayer.DamageLogic(NewMonster.GetAtt());
			system("cls");
			NewPlayer.StatusRender();
			NewMonster.StatusRender();
			NewPlayer.DamageRender();
			NewMonster.DamageRender();
		}

		{
			int Input = _getch();
			system("cls");
		}

		// 누군가 죽었다면 게임종료
		// Player와 몬스터에 bool을 리턴하는 IsDeath() 이용
		if (NewPlayer.IsDeath() || NewMonster.IsDeath())
		{
			printf_s("게임종료\n");
			break;
		}

		// 아무키나 눌릴때까지 기다려 줍니다.
		//int Input = _getch();

		// 콘솔창에 명령을 요청한다.
		//system("cls");
	}
}