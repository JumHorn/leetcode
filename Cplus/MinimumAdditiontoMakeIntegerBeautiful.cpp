class Solution
{
public:
	long long makeIntegerBeautiful(long long n, int target)
	{
		for (long long m = n; m > 0; m /= 10)
			target -= m % 10;
		if (target >= 0)
			return 0;
		target = -target;
		long long base = 1, res = 0, carry = 0;
		for (long long m = n; m > 0 && target + carry > 0; m /= 10)
		{
			carry += m % 10;
			target -= m % 10;
			if (carry % 10 != 0)
			{
				res = base * (10 - carry % 10) + res;
				carry = carry / 10 + 1;
			}
			else
				carry /= 10;
			base *= 10;
		}
		return res;
	}
};