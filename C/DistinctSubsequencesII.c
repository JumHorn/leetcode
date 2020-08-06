#include <string.h>

int distinctSubseqII(char* S)
{
	static const int MOD = 1e9 + 7;
	int dp = 1, last[26];
	memset(last, -1, sizeof(last));
	for (char* p = S; *p; ++p)
	{
		int old_dp = dp;
		dp = (dp * 2) % MOD;
		int index = *p - 'a';
		if (last[index] != -1)
			dp = (dp - last[index] + MOD) % MOD;
		last[index] = old_dp;
	}
	return dp - 1;
}
