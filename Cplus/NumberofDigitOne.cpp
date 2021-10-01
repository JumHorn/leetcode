#include <cmath>
#include <string>
using namespace std;

/*
统计每一位上为1时，有多少种可能性
计算百位上1的可能性
24071 highN=24 lowN=71 factor=100
digit == 0, count = highN * factor.
digit == 1, count = highN * factor + lowN + 1.
digit > 1, count = highN * factor + factor.
*/

class Solution
{
public:
	int countDigitOne(int n)
	{
		int res = 0;
		for (long long factor = 1; factor <= n; factor *= 10)
		{
			int a = n / factor, b = n % factor;
			res += a / 10 * factor;
			if (a % 10 == 1)
				res += b + 1;
			else if (a % 10 > 1)
				res += factor;
		}
		return res;
	}
};