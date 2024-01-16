#include <iostream>
#include <algorithm>
#include <string>

// 5988
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N = 0;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::string Num = "";
		std::cin >> Num;

		if ((Num[Num.length() - 1] - '0') % 2 == 0)
		{
			std::cout << "even\n";
		}
		else
		{
			std::cout << "odd\n";
		}
	}

	return 0;
}