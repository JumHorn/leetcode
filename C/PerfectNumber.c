#include <stdbool.h>

/*
Euclid-Euler Theorem
*/

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

int pn(int p)
{
	return (1u << (p - 1)) * ((1u << p) - 1);
}

bool checkPerfectNumber(int num)
{
	int primes[] = {2, 3, 5, 7, 13, 17, 19, 31};
	for (int i = 0; i < ARRAY_SIZE(primes); ++i)
	{
		if (pn(primes[i]) == num)
			return true;
	}
	return false;
}