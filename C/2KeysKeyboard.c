/*
f means factor
n=f1*f2*f3***
the minstep is sum of all factor
*/
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