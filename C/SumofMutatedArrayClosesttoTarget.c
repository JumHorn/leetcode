#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int findBestValue(int *arr, int arrSize, int target)
{
	qsort(arr, arrSize, sizeof(int), cmp);
	int sum[arrSize + 1];  //if current value choosed as best ,then calculate sum
	sum[0] = 0;
	for (int i = 0; i < arrSize; ++i)
		sum[i + 1] = sum[i] + arr[i];
	for (int i = arrSize - 1; i >= 0; --i)
		sum[i + 1] = arr[i] * (arrSize - i) + sum[i];
	if (sum[arrSize] <= target)
		return arr[arrSize - 1];
	int lo = 0, hi = arrSize + 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (sum[mi] < target)
			lo = mi + 1;
		else
			hi = mi;
	}
	target -= sum[--lo];
	//slightly increase the last value with int(target * 1.0 / (N - lo) + 0.4)
	return (int)(target * 1.0 / (arrSize - lo) + 0.4) + (lo >= 1 ? arr[lo - 1] : 0);
}
