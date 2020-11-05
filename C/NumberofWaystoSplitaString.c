
int numWays(char* s)
{
	static const int MOD = 1e9 + 7;
	int ones = 0, N = 0;
	for (; s[N]; ++N)
		ones += s[N] - '0';
	if (ones % 3 != 0)
		return 0;
	if (ones == 0)
		return (long)(N - 1) * (N - 2) / 2 % MOD;
	int m = ones / 3, a, b, i = 0;
	for (; i < N && m > 0; ++i)
		m -= s[i] - '0';
	int j = i;
	while (s[j] == '0')
		++j;
	a = j - i;
	m = ones / 3;
	for (i = j; i < N && m > 0; ++i)
		m -= s[i] - '0';
	j = i;
	while (s[j] == '0')
		++j;
	b = j - i;
	return (long)(a + 1) * (b + 1) % MOD;
}
