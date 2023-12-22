// 046_2DArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	// 2차원 배열
	char Arr[3][4] =
	{
		{'0', '1', '2'},
		"345",
		{'6', '7', '8'}
	};

	//  [][][][]
	//  [][][][]
	//  [][][][]

	// 사실 메모리 구조는 1차원 선형구조이지만
	// 인간이 이해하기 편하게 하기위해 만든 문법

	__int64 Address0 = reinterpret_cast<__int64>(&Arr[0][0]);
	__int64 Address1 = reinterpret_cast<__int64>(&Arr[0][1]);
	__int64 Address2 = reinterpret_cast<__int64>(&Arr[0][2]);
	__int64 Address3 = reinterpret_cast<__int64>(&Arr[0][3]);
	__int64 Address4 = reinterpret_cast<__int64>(&Arr[1][0]);
	__int64 Address5 = reinterpret_cast<__int64>(&Arr[1][1]);
	__int64 Address6 = reinterpret_cast<__int64>(&Arr[1][2]);
	__int64 Address7 = reinterpret_cast<__int64>(&Arr[1][3]);
	__int64 Address8 = reinterpret_cast<__int64>(&Arr[2][0]);
	__int64 Address9 = reinterpret_cast<__int64>(&Arr[2][1]);
	__int64 Address10 = reinterpret_cast<__int64>(&Arr[2][2]);
	__int64 Address11 = reinterpret_cast<__int64>(&Arr[2][3]);

	// char Arr[9]; = char [9]

	// char [4]형이 [3]개 모여있는 배열.
	// Arr			char [3][4]

	// Arr[0]		Arr[1]			Arr[2]
	// char[4]		char[4]			char[4]
	// [][][][]		[][][][]		[][][][]
	//



	int IntArr[10];
	int* Ptr = IntArr;

	char* Ptr0 = Arr[0];
	char* Ptr1 = Arr[1];
	char* Ptr2 = Arr[2];


	printf_s(Ptr0);
	printf_s(Ptr1);
	printf_s(Ptr2);

}