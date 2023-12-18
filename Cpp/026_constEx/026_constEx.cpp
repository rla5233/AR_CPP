// 026_constEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	{
		// 이건 const int
		const int CValue = 0;
		int NValue = CValue;
	}

	{	
		// 이건 불가능
		const int Value = 2;
		const int* CValue = &Value;
		//int* NValue = CValue;
		//*CValue = 1000;
		//int* NValue = CValue;
		//*NValue = 30;
	}

	{
		const int Value = 2;
		// Value
		// 위치 : 100번지
		// 크기 : 4
		// 형태 : const int
		// 값   : 2
		
		const int* CValue = &Value;
		// CValue
		// 위치 : 600번지
		// 크기 : 8
		// 형태 : const int*
		// 값   : 100번지
		
		// *CValue = 20; // 불가능!
		// 100번지에 있는 2라는 값을 20으로 수정해라

		CValue = nullptr;
		// 600번지에 있는 100번지라는 값을 0번지로 수정해라 // 이건된다.

		const int* const CCValue = &Value;
		//CCValue = nullptr; // 둘다 수정 불가능!
	}

}