class Solution
{
public:
	int rotatedDigits(int N)
	{
		int res = 0;
		for (int i = 2; i <= N; ++i)
			res += canBeRotated(i);
		return res;
	}

	int canBeRotated(int N)
	{
		int hash[] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
		int n = N, base = 1, rotate = 0;
		while (n != 0)
		{
			if (hash[n % 10] == -1)
				return 0;
			rotate += hash[n % 10] * base;
			n /= 10;
			base *= 10;
		}
		return N == rotate ? 0 : 1;
	}
};