#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

char *largestNumber(int *cost, int costSize, int target)
{
	static char dp[5001][5001];
	char *arr[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
	for (int i = 0; i <= target; ++i)
		dp[i][0] = '\0';
	for (int i = 1; i <= target; ++i)
	{
		for (int j = 8; j >= 0; --j)
		{
			if (i - cost[j] < 0 || strcmp(dp[i - cost[j]], "0") == 0)
				continue;
			if (dp[i][0] == '\0' || strlen(dp[i - cost[j]]) >= strlen(dp[i]))
			{
				int size = sprintf(dp[i], "%s", dp[i - cost[j]]);
				strcpy(&dp[i][size], arr[j]);
			}
		}
		if (dp[i][0] == '\0')
			strcpy(dp[i], "0");
	}
	reverse(dp[target], 0, strlen(dp[target]) - 1);
	return dp[target];
}