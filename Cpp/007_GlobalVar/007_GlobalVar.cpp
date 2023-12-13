// 007_GlobalVar.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 전역 변수
int MonsterSpeed = 10;

void MonsterMove()
{
	// 지역 변수
	int MonsterSpeed = 5;
}

int main()
{
	MonsterMove();
}
