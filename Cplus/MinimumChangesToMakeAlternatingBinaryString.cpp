#include <string>
using namespace std;

class Solution
{
public:
	int minOperations(string s)
	{
		int res1 = 0, res2 = 0;
		char start = '1';
		for (auto c : s)
		{
			if (c != start)
				++res1;
			start = 1 - (start - '0') + '0';
		}
		start = '0';
		for (auto c : s)
		{
			if (c != start)
				++res2;
			start = 1 - (start - '0') + '0';
		}
		return min(res1, res2);
	}
};