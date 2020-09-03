#include <stdlib.h>
#include <string.h>

void reverse(char *str)
{
	int i = 0, j = strlen(str) - 1;
	while (i < j)
	{
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		++i;
		--j;
	}
}

char *largestNumber(int *cost, int costSize, int target)
{
	static char dp[5001][5001];
	char *arr[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
	for (int i = 0; i <= target; ++i)
		dp[i][0] = '\0';
	//char** dp = (char**)malloc(sizeof(int*) * (target + 1));
	// for (int i = 0; i <= target; ++i)
	// {
	// 	dp[i] = (char*)malloc(sizeof(int) * (target + 1));
	// 	memset(dp[i], 0, sizeof(int) * (target + 1));
	// }
	for (int i = 1; i <= target; ++i)
	{
		for (int j = 8; j >= 0; --j)
		{
			if (i - cost[j] < 0 || strcmp(dp[i - cost[j]], "0") == 0)
				continue;
			if (dp[i][0] == '\0' || strlen(dp[i - cost[j]]) >= strlen(dp[i]))
			{
				strcpy(dp[i], dp[i - cost[j]]);
				strcat(dp[i], arr[j]);
			}
		}
		if (dp[i][0] == '\0')
			strcpy(dp[i], "0");
	}
	reverse(dp[target]);
	return dp[target];
}