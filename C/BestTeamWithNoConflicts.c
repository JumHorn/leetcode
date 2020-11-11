#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	int *l = (int *)lhs, *r = (int *)rhs;
	if (l[0] != r[0])
		return r[0] < l[0] ? -1 : 1;
	return r[1] - l[1];
}

int bestTeamScore(int *scores, int scoresSize, int *ages, int agesSize)
{
	int arr[scoresSize][2], arrSize = scoresSize; //{age,score}
	for (int i = 0; i < scoresSize; ++i)
	{
		arr[i][0] = ages[i];
		arr[i][1] = scores[i];
	}
	qsort(arr, arrSize, sizeof(arr[0]), cmp); // decreasing
	int dp[scoresSize], res = 0;
	for (int i = 0; i < scoresSize; ++i)
	{
		dp[i] = arr[i][1];
		for (int j = 0; j < i; ++j)
		{
			if (arr[i][1] <= arr[j][1])
				dp[i] = max(dp[i], dp[j] + arr[i][1]);
		}
		res = max(res, dp[i]);
	}
	return res;
}