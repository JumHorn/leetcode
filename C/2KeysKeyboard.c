/*
f means factor
n=f1*f2*f3***
the minstep is sum of all factor
*/

int minSteps(int n)
{
	int res = 0;
	for (int factor = 2; n > 1; ++factor)
	{
		for (; n % factor == 0; n /= factor)
			res += factor;
	}
	return res;
}