
int findMinFibonacciNumbers(int k)
{
	int f1 = 0, f2 = 1;
	while (f2 <= k)
	{
		int f3 = f2 + f1;
		f1 = f2;
		f2 = f3;
	}
	int res = 0;
	while (k > 0)
	{
		if (k >= f2)
		{
			++res;
			k -= f2;
		}
		int f3 = f2 - f1;
		f2 = f1;
		f1 = f3;
	}
	return res;
}
