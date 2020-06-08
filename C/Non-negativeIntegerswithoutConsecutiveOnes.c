
int dfs(int n, int num)
{
	if (n > num)
		return 0;
	int res = 1;
	if ((n & 1) == 0)
		res += dfs(n << 1 | 1, num);
	if (n != 0)
		res += dfs(n << 1, num);
	return res;
}

int findIntegers(int num)
{
	return dfs(0, num);
}
