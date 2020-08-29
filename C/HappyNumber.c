#include <stdbool.h>

int next(int n)
{
	int res = 0;
	while (n != 0)
	{
		res += (n % 10) * (n % 10);
		n /= 10;
	}
	return res;
}

bool isHappy(int n)
{
	if (n == 1)
		return true;
	int p = n, q = next(n);
	while (p != q)
	{
		if (q == 1)
			return true;
		p = next(p);
		q = next(next(q));
	}
	return false;
}