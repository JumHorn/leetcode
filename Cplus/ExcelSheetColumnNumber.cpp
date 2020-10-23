#include <string>
using namespace std;

class Solution
{
public:
	int titleToNumber(string s)
	{
		int N = s.length(), pow = 26, res = 0;
		long base = 1;
		for (int i = N - 1; i >= 0; --i)
		{
			res += (s[i] - 'A' + 1) * base;
			base *= pow;
		}
		return res;
	}
};