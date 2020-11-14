
#define min(a, b) (((a) < (b)) ? (a) : (b))

int count(int m, int n, int x)
{
	int res = 0;
	for (int i = 1; i <= m; ++i)
		res += min(x / i, n);
	return res;
}

int findKthNumber(int m, int n, int k)
{
	int lo = 1, hi = m * n;
	while (lo < hi)
	{
		int mid = (hi - lo) / 2 + lo;
		if (count(m, n, mid) < k)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}