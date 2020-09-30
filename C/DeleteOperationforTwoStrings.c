#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minDistance(char* word1, char* word2)
{
	int N1 = strlen(word1), N2 = strlen(word2);
	int dp[N2 + 1];
	for (int j = 0; j <= N2; ++j)
		dp[j] = j;
	for (int i = 0; i < N1; ++i)
	{
		int pre = dp[0], next;
		dp[0] = i + 1;
		for (int j = 0; j < N2; ++j)
		{
			next = dp[j + 1];
			if (word1[i] == word2[j])
				dp[j + 1] = pre;
			else
				dp[j + 1] = min(dp[j + 1], dp[j]) + 1;
			pre = next;
		}
	}
	return dp[N2];
}
