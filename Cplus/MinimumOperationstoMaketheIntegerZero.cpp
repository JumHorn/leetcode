#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int makeTheIntegerZero(int num1, int num2)
	{
		long long val = num2;
		for (int i = 1; i <= num1 - val; ++i, val += num2)
		{
			if (i >= bitCount(num1 - val))
				return i;
		}
		return -1;
	}

	int bitCount(unsigned long long n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};