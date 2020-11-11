#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int largestValsFromLabels(int *values, int valuesSize, int *labels, int labelsSize, int num_wanted, int use_limit)
{
	int arr[labelsSize][2]; //{value,label}
	for (int i = 0; i < valuesSize; ++i)
	{
		arr[i][0] = values[i];
		arr[i][1] = labels[i];
	}
	qsort(arr, labelsSize, sizeof(arr[0]), cmp);
	int res = 0, hash[20001] = {0};
	for (int i = valuesSize - 1; i >= 0 && num_wanted > 0; --i)
	{
		if (++hash[arr[i][1]] <= use_limit)
		{
			res += arr[i][0];
			--num_wanted;
		}
	}
	return res;
}