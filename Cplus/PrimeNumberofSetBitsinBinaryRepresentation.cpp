class Solution
{
public:
	int countPrimeSetBits(int L, int R)
	{
		int res = 0;
		for (int i = L; i <= R; ++i)
			res += isPrime(bitCount(i));
		return res;
	}

	int bitCount(int N)
	{
		int res = 0;
		while (N != 0)
		{
			++res;
			N &= N - 1;
		}
		return res;
	}

	int isPrime(int N) //only consider prime less than 32
	{
		if (N == 2 || N == 3 || N == 5)
			return 1;
		if (N < 2 || N % 2 == 0 || N % 3 == 0 || N % 5 == 0)
			return 0;
		return 1;
	}
};