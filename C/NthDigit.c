#include <stdio.h>

int findNthDigit(int n)
{
	long base = 1, digit = 1;
	for (int digitsCount = 9; n > digit * digitsCount; digitsCount *= 10)
	{
		n -= digit * digitsCount;
		++digit;
		base *= 10;
	}

	base += (n - 1) / digit;
	char number[15];
	sprintf(number, "%ld", base);
	return number[(n - 1) % digit] - '0';
}