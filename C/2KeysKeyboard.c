

int minSteps(int n)
{
	int res = 0, factor = 1;
	while (n > 1)
	{
		++factor;
		while (n % factor == 0)
		{
			res += factor;
			n /= factor;
		}
	}
	return res;
}
