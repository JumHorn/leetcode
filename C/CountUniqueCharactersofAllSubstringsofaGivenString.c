#include <string.h>

int uniqueLetterString(char *s)
{
	static const int MOD = 1e9 + 7;
	if (!*s)
		return 0;
	int N = strlen(s);
	int left[N], right[N];
	int map[26] = {0};
	for (int i = 0; i < N; ++i)
	{
		left[i] = i - map[s[i] - 'A'] + 1;
		map[s[i] - 'A'] = i + 1;
	}
	for (int i = 0; i < 26; ++i)
		map[i] = N - 1;
	for (int i = N - 1; i >= 0; --i)
	{
		right[i] = map[s[i] - 'A'] - i + 1;
		map[s[i] - 'A'] = i - 1;
	}
	int res = 0;
	for (int i = 0; i < N; ++i)
		res = (res + left[i] * right[i]) % MOD;
	return res;
}
