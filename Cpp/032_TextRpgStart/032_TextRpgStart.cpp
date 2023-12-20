// 032_TextRpgStart.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// 보여주기만 하는 함수, 수정할 생각이 없는 함수 -> const
void StatusRender(const char* _Name, int _Hp, int _Att)
{
	// 콘솔창은 특수문자를 통해서 특수한 출력기호를 사용할 수 있는데,
	// 전부다 \ 역슬레시를 사용해서 표현한다.
	// \n -> 콘솔창이 한글자로 본다. (줄바꿈 코드)
	//

	// 1.
	// int count = static_cast<int>(strlen(_Name));

	// 2.
	//int count = 0;
	//while (_Name[count])
	//{
	//	count++;
	//}

	// 3.
	int count = printf_s("%s ", _Name);
	for (int i = 0; i < 50 - count; i++)
	{
		printf_s("-");
	}

	printf_s("\n공격력 %d", _Att);
	printf_s("\n체력 %d\n", _Hp);

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}

// 공격의 행동을 화면에 렌더링 하는 함수
void DamageRender(const char* _Name, const int& _Att)
{
	printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", _Name, _Att);
}

// 실제 데미지를 데이터적으로 주는 함수
void DamageLogic(const int& _Att, int& _DefHp)
{
	_DefHp -= _Att;
}

void Damage(const char* _Name, const int& _Att, int& _DefHp)
{
	DamageRender(_Name, _Att);
	DamageLogic(_Att, _DefHp);
}

int main()
{ 
	// 먼저 존재하게 하기 위해서
	// 상태를 만들었다.
	char PlayerName[100] = "Fighter";
	int PlayerHp = 100; 
	int PlayerAtt = 10;

	char MonsterName[100] = "Orc";
	int MonsterHp = 50;
	int MonsterAtt = 5;


	// 메인 루프
	while (true)
	{
		// 눈에보이게 만든다.
		StatusRender(PlayerName, PlayerHp, PlayerAtt);
		StatusRender(MonsterName, MonsterHp, MonsterAtt);

		{
			int Input = _getch();
			system("cls");

			DamageLogic(PlayerAtt, MonsterHp);
			StatusRender(PlayerName, PlayerHp, PlayerAtt);
			StatusRender(MonsterName, MonsterHp, MonsterAtt);
			DamageRender(PlayerName, PlayerAtt);
		}

		//DamageRender(PlayerName, PlayerAtt);
		//DamageLogic(PlayerAtt, MonsterHp);
		//Damage(PlayerName, PlayerAtt, MonsterHp);
		

		{
			int Input = _getch();

			DamageLogic(MonsterAtt, PlayerHp);
			system("cls");

			StatusRender(PlayerName, PlayerHp, PlayerAtt);
			StatusRender(MonsterName, MonsterHp, MonsterAtt);

			DamageRender(PlayerName, PlayerAtt);
			DamageRender(MonsterName, MonsterAtt);
		}

		//DamageRender(MonsterName, MonsterAtt);
		//DamageLogic(MonsterAtt, PlayerHp);
		//Damage(MonsterName, MonsterAtt, PlayerHp);

		{
			int Input = _getch();
			system("cls");
		}

		// 아무키나 눌릴때까지 기다려 줍니다.
		//int Input = _getch();

		// 콘솔창에 명령을 요청한다.
		//system("cls");
	}
}