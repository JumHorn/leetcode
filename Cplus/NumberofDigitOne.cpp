#include <string>
#include <cmath>
using namespace std;

/*
统计每一位上为1时，有多少种可能性
计算百位上1的可能性
24071 highN=24 lowN=71 factor=100
digit == 0, count = highN * factor.
digit == 1, count = highN * factor + lowN + 1.
digit > 1, count = (highN + 1) * factor.
*/

class Solution
{
public:
	int countDigitOne(int n)
	{
		int res = 0;
		for (long long m = 1; m <= n; m *= 10)
		{
			int a = n / m, b = n % m;
			if (a % 10 == 1)
				res += a / 10 * m + b + 1;
			else if (a % 10 == 0)
				res += a / 10 * m;
			else
				res += (a / 10 + 1) * m;
		}
		return res;
	}
};