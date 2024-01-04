// 072_DanglingPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
public:
	int Hp;

	void MoveMsg()
	{
		// 내부에서 this 포인터를 사용하지 않으면 
		// nullptr 이여도 작동된다.
		printf_s("MoveMsg\n");
	}
};

// 허상 포인터 (Dangling Pointer)
// 컴퓨터 프로그래밍에서 적절한 타입의 유효한 객체를 
// 가리키고 있지 않는 포인터

int main()
{
	{
		// 첫 번째 금기 - 동적할당 한 곳에 또 하지 마라
	
		// 500번지     500번지
		int* Ptr = new int();
		
		// 600번지  600번지
			 Ptr = new int();

		// 600번지를 지워라 (500번지는...?)
		delete Ptr;
	}

	{
		// 방어코드를 쳐라
		// nullptr은 사용할 수 없다.
		int* Ptr = nullptr;

		// 0번지에 200을 넣어라 (운영체제에서 막음)
		//	*Ptr = 200; // null 레퍼런스 익셉션

		// 방어 코드 (nullptr 체크)
		if (Ptr != nullptr)
		{
			*Ptr = 10;
		}

		Player* NewPlayer = nullptr;

		if (NewPlayer == nullptr)
		{
			//return 1;
		}

		// 실행되네..?
		NewPlayer->MoveMsg(/*&NewPlayer => this*/);
	}

	{
		int* Ptr = new int();

		delete Ptr; // delete는 nullptr로 바꿔주진 않는다.
		Ptr = nullptr; // 따라서 delete 해줬으면 nullptr을 넣어주자.
	}

	{
		// nullptr은 지우는 것도 안된다.
		int* Ptr = nullptr;

		// delete Ptr;
		// safe_delete 형식
		if (Ptr != nullptr)
		{
			delete Ptr;
			Ptr = nullptr;
		}
	}
}