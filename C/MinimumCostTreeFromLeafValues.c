#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int mctFromLeafValues(int *arr, int arrSize)
{
	int res = 0, top = -1;
	for (int i = 0; i < arrSize; ++i)
	{
		while (top != -1 && arr[top] <= arr[i])
		{
			int mid = arr[top--];
			res += mid * (top == -1 ? arr[i] : min(arr[top], arr[i]));
		}
		arr[++top] = arr[i];
	}
	for (int i = 1; i <= top; ++i)
		res += arr[i] * arr[i - 1];
	return res;
}