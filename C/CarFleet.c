#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int carFleet(int target, int *position, int positionSize, int *speed, int speedSize)
{
	int N = positionSize;
	if (N == 0)
		return 0;
	int arr[N][2];
	for (int i = 0; i < N; ++i)
	{
		arr[i][0] = position[i];
		arr[i][1] = speed[i];
	}
	qsort(arr, N, sizeof(arr[0]), cmp);
	double time[N];
	for (int i = 0; i < N; ++i)
		time[i] = (target - arr[i][0]) * 1.0 / arr[i][1];
	int res = 0;
	for (int i = N - 1, j; i >= 0; i = j)
	{
		++res;
		j = i - 1;
		while (j >= 0 && time[i] >= time[j])
			--j;
	}
	return res;
}
