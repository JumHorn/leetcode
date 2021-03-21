class Solution
{
public:
	int maxValue(int n, int index, int maxSum)
	{
		int lo = 2, hi = 1e9 + 1;
		while (lo < hi)
		{
			long mi = (hi - lo) / 2 + lo;
			long sum = mi;
			if (mi > index)
				sum += (mi - 1 + mi - index) * index / 2;
			else
			{
				sum += (mi - 1 + 1) * (mi - 1) / 2;
				sum += (index - mi + 1);
			}

			int count = n - index - 1;
			if (mi > count)
				sum += (mi - 1 + mi - count) * count / 2;
			else
			{
				sum += (mi - 1 + 1) * (mi - 1) / 2;
				sum += (count - mi + 1);
			}

			if (sum <= maxSum)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}
};