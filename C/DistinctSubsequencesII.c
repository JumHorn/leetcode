#include <string.h>

int distinctSubseqII(char *S)
{
	static const int MOD = 1e9 + 7;
	int dp = 1, last[26];
	memset(last, -1, sizeof(last));
	for (int i = 0; S[i]; ++i)
	{
		int pre_dp = dp;
		dp = (dp * 2) % MOD;
		int index = S[i] - 'a';
		if (last[index] != -1)
			dp = (dp - last[index] + MOD) % MOD;
		last[index] = pre_dp;
	}
	return (dp - 1 + MOD) % MOD;
}