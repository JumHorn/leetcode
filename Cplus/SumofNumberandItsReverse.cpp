class Solution
{
public:
	bool sumOfNumberAndReverse(int num)
	{
		for (int i = 0; i <= num; ++i)
		{
			if (i == reverse(num - i))
				return true;
		}
		return false;
	}

	int reverse(int n)
	{
		int res = 0;
		for (; n > 0; n /= 10)
			res = res * 10 + n % 10;
		return res;
	}
};