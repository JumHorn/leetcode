#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maximumSum(int *arr, int arrSize)
{
	int res = arr[0];
	int max1 = arr[0]; //one deletion
	int max0 = arr[0]; //no deletion
	for (int i = 1; i < arrSize; i++)
	{
		max1 = max(max0, max(max1 + arr[i], arr[i]));
		max0 = max(max0 + arr[i], arr[i]);
		res = max(res, max1);
	}
	return res;
}