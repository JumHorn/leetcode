class Solution
{
public:
	int countEven(int num)
	{
		int res = 0;
		for (int i = 1; i <= num; ++i)
		{
			if (digitSum(i) % 2 == 0)
				++res;
		}
		return res;
	}

	int digitSum(int n)
	{
		int res = 0;
		for (; n > 0; n /= 10)
			res += n % 10;
		return res;
	}
};