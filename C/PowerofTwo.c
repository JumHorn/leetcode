#include <stdbool.h>

bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
	int res = 0;
	while (n != 0)
	{
		++res;
		n &= n - 1;
	}
	return res == 1;
}