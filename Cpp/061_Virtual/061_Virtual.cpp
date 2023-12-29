// 061_Virtual.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit
{
public:
	// virtual 문법
	// 자식이 만약 나와 완전히 동일한 함수를 구현한다면
	// 자식의 함수를 우선적으로 실행한다.
	virtual int GetAtt() { return Att; }

private:
	int Att = 10;

};

class Monster : public FightUnit
{

};

class Player : public FightUnit
{
protected:
	// override를 붙여서 부모에게서 물려받아 
	// 재구현한 함수라는 것을 명시해준다. (안붙여도 동작하지만)
	int GetAtt() override
	{
		return FightUnit::GetAtt() + WAtt;
	}
	
private:
	int WAtt = 5;
};

void Fight(FightUnit* _Left, FightUnit* _Right)
{
	// 겉으로 보기에는 FightUnit 이지만
	// 동작할때는 플레이어나 몬스터처럼 동작하는것
	// 그래서 다형성이라고 한다. 
	int a = _Left->GetAtt();
	int b = _Right->GetAtt();

	int c = 0;
}

int main()
{
	// 가장 말단 형태로는 거의 사용하지 않는다.
	Player NewPlayer;
	Monster NewMonster;

	Fight(&NewPlayer, &NewMonster);


	return 0;
}