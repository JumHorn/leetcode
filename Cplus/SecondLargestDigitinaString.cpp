#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int secondHighest(string s)
	{
		vector<int> count(10);
		for (auto c : s)
		{
			if (c >= '0' && c <= '9')
				++count[c - '0'];
		}
		int n = 2;
		for (int i = 9; i >= 0; --i)
		{
			if (count[i] > 0)
				--n;
			if (n <= 0)
				return i;
		}
		return -1;
	}
};