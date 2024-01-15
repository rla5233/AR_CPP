#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 1543
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string doc = "", find = "";
	getline(cin, doc);
	getline(cin, find);

	int count = 0, idx = 0;
	while (true)
	{
		if (doc.find(find, idx) != string::npos)
		{
			idx = static_cast<int>(doc.find(find, idx) + find.length());
			++count;
		}
		else
		{
			cout << count;
			break;
		}
	}

	return 0;
}