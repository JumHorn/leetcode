

int consecutiveNumbersSum(int N)
{
	int res = 0, m = 1, mk = N;
	while (mk > 0)
	{
		if (mk % m == 0)
			++res;
		++m;
		mk = N - m * (m - 1) / 2;
	}
	return res;
}
