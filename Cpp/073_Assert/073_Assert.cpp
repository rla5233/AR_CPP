// 073_Assert.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h> // 윈도우 헤더 -> 플랫폼 헤더
#include <assert.h>

int main()
{
	// 프로그램을 파괴할 수 있는 함수를 말한다.
	// 일부러 심각한 익셉션을 일으켜 절대 벌어지면
	// 안되는 사용법이 사용됐다는것을 알려 주는 것
	//

	// 지금은 사용법만 배움
	MessageBoxA(nullptr, "에러발생", "치명적 에러", MB_OK);
	assert(false);

}