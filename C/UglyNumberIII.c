
#define min(a, b) (((a) < (b)) ? (a) : (b))

int nthUglyNumber(int n, int a, int b, int c)
{
	long i = 1, j = 1, k = 1, res, la = a, lb = b, lc = c;
	while (--n >= 0)
	{
		res = min(la * i, min(lb * j, lc * k));
		if (res == la * i)
			i++;
		if (res == lb * j)
			j++;
		if (res == lc * k)
			k++;
	}
	return res;
}

