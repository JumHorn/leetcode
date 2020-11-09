#include <stdbool.h>

int gcd(int x, int y)
{
	return x == 0 ? y : gcd(y % x, x);
}

bool hasGroupsSizeX(int *deck, int deckSize)
{
	int hash[10000] = {0}, count = 0;
	for (int i = 0; i < deckSize; ++i)
	{
		if (count < ++hash[deck[i]])
			count = hash[deck[i]];
	}
	for (int i = 0; i < 10000; ++i)
	{
		if (hash[i] == 0)
			continue;
		count = gcd(count, hash[i]);
		if (count < 2)
			return false;
	}
	return true;
}
