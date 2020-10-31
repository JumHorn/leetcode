
int tribonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	int f1 = 0, f2 = 1, f3 = 1;
	for (int i = 3; i <= n; ++i)
	{
		int f4 = f1 + f2 + f3;
		f1 = f2;
		f2 = f3;
		f3 = f4;
	}
	return f3;
}