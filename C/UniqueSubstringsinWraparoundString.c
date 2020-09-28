#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int findSubstringInWraproundString(char *p)
{
	if (!*p)
		return 0;
	int dp[26] = {0};
	int count, next = -1, size = strlen(p);
	for (int i = size - 1; i >= 0; --i)
	{
		if ((p[i] - 'a' + 1) % 26 == next)
			++count;
		else
			count = 1;
		dp[p[i] - 'a'] = max(dp[p[i] - 'a'], count);
		next = p[i] - 'a';
	}
	int res = 0;
	for (int i = 0; i < 26; ++i)
		res += dp[i];
	return res;
}