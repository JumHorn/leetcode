#include <limits.h>
#include <stdlib.h>
#include <string.h>

/*
dp[i][j]表示，将数组arr1的前i个元素通过j次替换后变为严格递增序列时，序列中最后一个元素的最小值,即第i个元素的最小值
1. 当arr1[i+1] > dp[i][j] 时，即前i个元素已经严格递增，这时arr1[i+1]大于严格递增序列的最大值时，
	arr1[i+1]直接加在序列末尾，即这时的序列应该严格递增，且此时的序列进行替换的次数仍然为i次。
2. 选择将arr2进行元素替换，此时，我们应当在数组arr2中找到第一个比dp[i][j-1]大的数，dp[i][j-1]即前i个元素进行j-1替换后的序列的最大值，
	我们使用二分查找即可在O(lgn)时间复杂度内找到该值,此时我们仍然保证前i+1个元素进行了j次替换。
*/

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int binarySearch(int *arr, int lo, int hi, int val)
{
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] <= val)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}

int makeArrayIncreasing(int *arr1, int arr1Size, int *arr2, int arr2Size)
{
	//INF == 1077952576
	const int BASE = 1u << 6, INF = (BASE | (BASE << 8) | (BASE << 16) | (BASE << 24));
	int dp[arr1Size + 1][arr1Size + 1];
	memset(dp, BASE, sizeof(dp));
	dp[0][0] = -1;
	qsort(arr2, arr2Size, sizeof(int), cmp);

	for (int i = 0; i < arr1Size; ++i)
	{
		for (int j = 0; j <= i + 1; ++j)
		{
			if (arr1[i] > dp[i][j])
				dp[i + 1][j] = arr1[i];

			if (j > 0)
			{
				int index = binarySearch(arr2, 0, arr2Size, dp[i][j - 1]);
				if (index != arr2Size && dp[i + 1][j] > arr2[index])
					dp[i + 1][j] = arr2[index];
			}
			if (i == arr1Size - 1 && dp[i + 1][j] < INF)
				return j;
		}
	}
	return -1;
}