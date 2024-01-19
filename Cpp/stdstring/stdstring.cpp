// stdstring.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

class MyString
{
public:
    int Size = 0;
    char* Arr = nullptr;

    void operator=(const MyString& _Other)
    {
        // 얕은 복사
        Arr = _Other.Arr;
    }

    MyString(const MyString& _Other)
    {
        Arr = _Other.Arr;
        Size = _Other.Size;
        Arr = new char[Size] { 0, };
        for (size_t i = 0; i < Size; i++)
        {
            Arr[i] = _Other.Arr[i];
        }


    }

    MyString(const char* _Ptr)
    {
        Size = strlen(_Ptr) + 1;

        Arr = new char[Size] { 0, };
        for (size_t i = 0; i < Size; i++)
        {
            Arr[i] = _Ptr[i];
        }
    }

    ~MyString()
    {
        if (nullptr != Arr)
        {
            delete Arr;
            Arr = nullptr;
        }
    }
};

void TestMyFunction(const MyString& Text)
{

}

void TestFunction(std::string Text)
{

}

int main()
{
	// 일종의 vector라고 생각하면 편하다.
    // std::vector<char>
	std::string str0 = "가";
	std::string str1 = "나";

	std::string result = str0 + str1;
	std::cout << result << std::endl;

	std::wstring wstr0 = L"가"; // 와이드 바이트 인코딩 (와이드 바이트는 2바이트)
	std::wstring wstr1 = L"나"; // 와이드 바이트 인코딩
	std::wstring wresult = wstr0 + wstr1;
	std::cout << result << std::endl;
}