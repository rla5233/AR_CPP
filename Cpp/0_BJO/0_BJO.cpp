#include <iostream>
#include <vector>

// 11441
int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int N = 0;
	std::cin >> N;

	int num = 0;
	std::vector<int> PSum(N + 1, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> num;
		PSum[i + 1] = PSum[i] + num;
	}

	int M = 0;
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		int begin = 0, end = 0;
		std::cin >> begin >> end;
		std::cout << PSum[end] - PSum[begin - 1] << "\n";
	}

	return 0;
}