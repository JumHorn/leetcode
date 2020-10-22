#include <limits.h>
#include <stdbool.h>

int reversePositive(int x)
{
	int res = 0;
	while (x != 0)
	{
		if (res > INT_MAX / 10)
			return 0;
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

bool isPalindrome(int x)
{
	if (x < 0)
		return false;
	if (x == 0)
		return true;
	return x == reversePositive(x);
}
