#include <stdbool.h>
#include <string.h>

bool wordBreak(char *s, char **wordDict, int wordDictSize)
{
	if (wordDictSize == 0)
		return false;
	int N = strlen(s);
	bool dp[N + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	int wordDictColSize[wordDictSize];
	for (int i = 0; i < wordDictSize; ++i)
		wordDictColSize[i] = strlen(wordDict[i]);
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j >= 0 && !dp[i + 1]; --j)
		{
			for (int k = 0; k < wordDictSize; ++k)
			{
				if (wordDictColSize[k] == i - j + 1 && strncmp(wordDict[k], s + j, i - j + 1) == 0)
					dp[i + 1] = dp[j];
			}
		}
	}
	return dp[N];
}