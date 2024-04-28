class Solution
{
public:
	long long minEnd(int n, int x)
	{
		--n;
		unsigned long long res = x;
		for (int i = 0, j = 0; i < 30; ++i)
		{
			while ((res >> j) & 1)
				++j;
			if ((n >> i) & 1)
				res ^= (1ull << j);
			++j;
		}
		return res;
	}
};