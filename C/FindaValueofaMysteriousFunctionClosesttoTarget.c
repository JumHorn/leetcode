#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int closestToTarget(int *arr, int arrSize, int target)
{
	int res = abs(arr[0] - target);
	int valid[20]; //at most 20 values in result set
	int validSize = 1;
	valid[0] = arr[0];
	for (int i = 0; i < arrSize; ++i)
	{
		int next_valid[20];
		int size = 1;
		next_valid[0] = arr[i];
		res = min(res, fabs(arr[i] - target));
		for (int j = 0; j < validSize; j++)
		{
			next_valid[size++] = valid[j] & arr[i];
			res = min(res, fabs((valid[j] & arr[i]) - target));
		}
		int unique = 0;
		for (int j = 1; j < size; ++j) //decreasing array unique
		{
			if (next_valid[unique] != next_valid[j])
				next_valid[++unique] = next_valid[j];
		}
		validSize = unique + 1;
		memcpy(valid, next_valid, sizeof(valid));
	}
	return res;
}