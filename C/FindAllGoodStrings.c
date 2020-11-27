#include <string.h>

int memdp(char *s1, char *s2, char *evil, int n, int k, int i, int j, int up, int low, int *kmp, int (*dp)[51][2][2])
{
	static const int MOD = 1e9 + 7;
	if (dp[i][j][up][low] != -1)
		return dp[i][j][up][low];
	if (j >= k)
		return 0;
	if (i >= n)
		return 1;
	char from = low ? s1[i] : 'a';
	char to = up ? s2[i] : 'z';
	int res = 0;
	for (char c = from; c <= to; ++c)
	{
		int jump = j;
		while (jump > 0 && evil[jump] != c)
			jump = kmp[jump - 1];
		if (evil[jump] == c)
			++jump;
		res = (res + memdp(s1, s2, evil, n, k, i + 1, jump, up && (c == to), low && (c == from), kmp, dp)) % MOD;
	}
	return dp[i][j][up][low] = res;
}

int findGoodStrings(int n, char *s1, char *s2, char *evil)
{
	int k = strlen(evil);
	int kmp[k];
	kmp[0] = 0;
	for (int i = 1, j = 0; i < k; ++i)
	{
		while (j > 0 && evil[i] != evil[j])
			j = kmp[j - 1];
		if (evil[i] == evil[j])
			++j;
		kmp[i] = j;
	}
	int dp[501][51][2][2];
	memset(dp, -1, sizeof(dp));
	return memdp(s1, s2, evil, n, k, 0, 0, 1, 1, kmp, dp);
}