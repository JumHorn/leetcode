#include <stdbool.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool arrLessThan(int *arr1, int *arr2, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr1[i] > arr2[i])
			return false;
	}
	return true;
}

int maxScoreWords(char **words, int wordsSize, char *letters, int lettersSize, int *score, int scoreSize)
{
	int N = wordsSize;
	int dp[1 << N][27]; //this mask [0,26] is alpha count [27,27] is score
	memset(dp, 0, sizeof(dp));
	int letterCount[26] = {0};
	for (int i = 0; i < lettersSize; ++i)
		++letterCount[letters[i] - 'a'];

	int res = 0;
	for (int mask = 0; mask < 1 << N; ++mask)
	{
		for (int i = 0; i < N; ++i)
		{
			if ((mask >> i) & 1)
			{
				for (int j = 0; words[i][j]; ++j)
				{
					++dp[mask][words[i][j] - 'a'];
					dp[mask][26] += score[words[i][j] - 'a'];
				}
			}
		}
		if (arrLessThan(dp[mask], letterCount, 26))
			res = max(res, dp[mask][26]);
	}
	return res;
}