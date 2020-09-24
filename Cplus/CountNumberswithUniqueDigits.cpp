#include <cmath>
using namespace std;

class Solution
{
public:
	int countNumbersWithUniqueDigits(int n)
	{
		if (n <= 1)
			return pow(10, n);
		int res = 10, base = 9;
		for (int i = 1; i < n; ++i)
		{
			base *= 10 - i;
			res += base;
		}
		return res;
	}
};