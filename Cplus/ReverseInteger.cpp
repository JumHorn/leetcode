#include <climits>

class Solution
{
public:
	int reverse(int x)
	{
		if (x == INT_MIN) //overflow
			return 0;
		return x >= 0 ? reversePositive(x) : -reversePositive(-x);
	}

	int reversePositive(int x)
	{
		int res = 0;
		while (x != 0)
		{
			if (res > INT_MAX / 10)
				return 0;
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};