#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int *l = (int *)lhs, *r = (int *)rhs;
	if (l[0] != r[0])
		return l[0] - r[0];
	return l[1] - r[1];
}

int power(int x)
{
	int res = 1;
	while (x != 1)
	{
		if (x % 2 == 0)
			x /= 2;
		else
			x = 3 * x + 1;
		++res;
	}
	return res;
}

int getKth(int lo, int hi, int k)
{
	int arr[1000][2];  //{power,value}
	for (int i = lo; i <= hi; ++i)
	{
		arr[i - lo][0] = power(i);
		arr[i - lo][1] = i;
	}
	qsort(arr, hi - lo + 1, sizeof(arr[0]), cmp);
	return arr[k - 1][1];
}
