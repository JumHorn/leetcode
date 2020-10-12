#include <stdbool.h>

bool request(int a, int b)
{
	return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
}

int numFriendRequests(int *ages, int agesSize)
{
	int hash[121] = {0};
	for (int i = 0; i < agesSize; ++i)
		++hash[ages[i]];
	int res = 0;
	for (int i = 0; i < 121; ++i)
	{
		if (hash[i] == 0)
			continue;
		for (int j = 0; j < 121; ++j)
		{
			if (request(i, j))
				res += hash[i] * (hash[j] - (i == j ? 1 : 0));
		}
	}
	return res;
}