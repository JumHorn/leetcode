class Solution
{
public:
	int minimumNumbers(int num, int k)
	{
		if (num == 0)
			return 0;
		if (k == 0)
		{
			if (num % 10 == 0)
				return 1;
			return -1;
		}
		if (num % 10 == k % 10)
			return 1;
		for (int i = 1; i <= 10 && i * k <= num; ++i)
		{
			int val = i * k;
			if (val % 10 == num % 10)
				return i;
		}
		return -1;
	}
};