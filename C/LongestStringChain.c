#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

bool checkValid(char *lhs, char *rhs)  //lhs is subsequence of rhs or not
{
	while (*lhs && *rhs)
	{
		if (*lhs == *rhs)
			++lhs;
		++rhs;
	}
	return !*lhs;
}

int longestStrChain(char **words, int wordsSize)
{
	int arr[wordsSize][2];  //{word length,index}
	for (int i = 0; i < wordsSize; ++i)
	{
		arr[i][0] = strlen(words[i]);
		arr[i][1] = i;
	}
	qsort(arr, wordsSize, sizeof(arr[0]), cmp);
	int dp[wordsSize];
	int res = 1;
	for (int i = 0; i < wordsSize; ++i)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[i][0] - arr[j][0] > 1)
				break;
			if (arr[i][0] == arr[j][0])
				continue;
			if (checkValid(words[arr[j][1]], words[arr[i][1]]))
			{
				dp[i] = max(dp[i], dp[j] + 1);
				res = max(res, dp[i]);
			}
		}
	}
	return res;
}
