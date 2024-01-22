// 089_trycatch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// throw : catch 문으로 던져버린다.
void Function2() throw(int, bool, const char*) // 생략 가능
{
	int* Ptr = nullptr;
	
	if (nullptr != Ptr)
	{
		throw 10;
	}

	if (nullptr != Ptr)
	{
		throw true;
	}

	if (nullptr == Ptr)
	{
		// 바깥쪽에서 받아주지 않으면 아래의 코드가 실행된다.
		throw "nullptr";
	}

	*Ptr = 100;

	throw true;
}

void Function1() throw(int, bool) // noexcept // 예외를 바깥으로 넘기지 않는다.
{
	Function2();
}

void Function() 
{
	// 최신 문법
	
	// trycatch
	// 심각한 오류가 나도 일단 넘겨라.
	// 예외처리할 구문을 받아 줘야한다.
	// 수업에선 잘 사용하지 않을것이나
	// 실무에선 사용할 수 있다.
	try
	{
		// 예외처리할 코드를 넣는다.
		Function1();
	}
	catch (int Exp)
	{
		std::cout << "int 예외" << std::endl;
	}
	catch (bool Exp)
	{
		std::cout << "bool 예외" << std::endl;
	}
	//catch (const char* Exp)
	//{
	//    std::cout << Exp << std::endl;
	//}
}


int main()
{
	Function();
}