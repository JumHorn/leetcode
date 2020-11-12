#include <string.h>

int getMaxRepetitions(char *s1, int n1, char *s2, int n2)
{
	int N1 = strlen(s1), N2 = strlen(s2), res = 0, index = 0;
	int count[N2 + 1], seen[N2];
	memset(count, 0, sizeof(count));
	memset(seen, -1, sizeof(seen));
	for (int i = 0; i < n1; ++i)
	{
		for (int j = 0; j < N1; ++j)
		{
			if (s1[j] == s2[index])
				++index;
			if (index == N2)
			{
				index = 0;
				++res;
			}
		}
		count[i] = res;
		int k = seen[index];
		if (k != -1)
		{
			int pre = count[k];
			int pattern = (count[i] - count[k]) * ((n1 - k - 1) / (i - k));
			int remain = count[k + (n1 - k - 1) % (i - k)] - count[k];
			return (pre + pattern + remain) / n2;
		}
		seen[index] = i;
	}
	return res / n2;
}