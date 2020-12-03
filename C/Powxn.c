
double recursive(double x, long n)
{
	if (n == 0)
		return 1;
	double res = recursive(x, n / 2);
	res *= (n % 2 == 0) ? res : x * res;
	return res;
}

double myPow(double x, int n)
{
	if (x == 0 || x == 1 || n == 0)
		return 1;
	long m = n;
	double res = recursive(x > 0 ? x : -x, m > 0 ? m : -m);
	if (n < 0)
		res = 1 / res;
	return x < 0 && n % 2 == 1 ? -res : res;
}