#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int toInt(char *S, int start, int end)
{
	int val = 0, index = end;
	while (index >= start)
	{
		val |= ((S[index] - '0') << (end - index));
		--index;
	}
	return val;
}

bool queryString(char *S, int N)
{
	int len = strlen(S);
	if (N > 2 * len)
		return false;
	char *hash = (char *)malloc(N * sizeof(char));
	memset(hash, 0, N * sizeof(char));
	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < len && j - i <= 31; ++j)
		{
			int val = toInt(S, i, j);
			if (val > N)
				break;
			if (val > 0)
				hash[val - 1] = 1;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (hash[i] == 0)
			return false;
	}
	return true;
}