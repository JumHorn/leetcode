#include <stdbool.h>

/*
pow(3,19) == 1162261467
pow(3,19) < INT_MAX
*/

bool isPowerOfThree(int n)
{
	return n > 0 && 1162261467 % n == 0;
}