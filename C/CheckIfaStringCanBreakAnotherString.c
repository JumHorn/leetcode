#include <stdbool.h>

bool fullSmall(int *v1, int *v2, int size)
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < size; ++i)
	{
		sum1 += v1[i];
		sum2 += v2[i];
		if (sum1 > sum2)
			return false;
	}
	return true;
}

bool checkIfCanBreak(char *s1, char *s2)
{
	int hash1[26] = {0}, hash2[26] = {0};
	for (int i = 0; s1[i]; ++i)
	{
		++hash1[s1[i] - 'a'];
		++hash2[s2[i] - 'a'];
	}
	return fullSmall(hash1, hash2, 26) || fullSmall(hash2, hash1, 26);
}
