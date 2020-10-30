
int binaryGap(int n)
{
	int res = 0;
	for (int i = 0, j = 32; i < 31; ++i)
	{
		if (n & (1 << i))
		{
			if (i - j > res)
				res = i - j;
			j = i;
		}
	}
	return res;
}