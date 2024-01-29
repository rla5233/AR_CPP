// 093_LocalStatic.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{

};

void Test()
{
	// 이 함수에서만 사용할 수 있으면서, 메모리는 전역적으로 유지되는 변수
	// 필요한 메모리를 공개하고 싶은 곳에만 공개 함으로써
	// 건강한 객체간의 관계를 만드는것이 목적이다.

	// 빌드되면 데이터영역으로 옮겨 버린다.
	static int A = 0;
	std::cout << ++A << std::endl;
}

int main()
{
	while (true)
	{
		Test();
	}
}