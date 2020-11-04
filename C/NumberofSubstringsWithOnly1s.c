
int numSub(char* s)
{
	static const int MOD = 1e9 + 7;
	long res = 0, count = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '0')
			count = 0;
		else
			++count;
		res = (res + count) % MOD;
	}
	return res;
}
