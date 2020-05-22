
int dfs(int n, int *k, long val)
{
	if (val > n)
		return -1;
	if (*k == 1)
		return val;
	--*k;
	for (int i = 0; i < 10; i++)
	{
		int res = dfs(n, k, val * 10 + i);
		if (res == -1)
			break;
		if (res > 0)
			return res;
	}
	return 0;
}

int findKthNumber(int n, int k)
{
	for (int i = 1; i < 10; i++)
	{
		int res = dfs(n, &k, i);
		if (res > 0)
			return res;
	}
	return -1;
}