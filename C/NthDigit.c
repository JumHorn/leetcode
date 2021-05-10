#include <stdio.h>

int findNthDigit(int n)
{
	long digitsCount = 9, base = 1, digit = 1;
	while (n > digit * digitsCount)
	{
		n -= digit * digitsCount;
		++digit;
		digitsCount *= 10;
		base *= 10;
	}

	base += (n - 1) / digit;
	char number[15];
	sprintf(number, "%ld", base);
	return number[(n - 1) % digit] - '0';
}