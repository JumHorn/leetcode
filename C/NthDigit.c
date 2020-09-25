#include <stdio.h>

int findNthDigit(int n)
{
	long digitsCount = 9, base = 1, bit = 1;
	while (n > bit * digitsCount)
	{
		n -= bit * digitsCount;
		bit += 1;
		digitsCount *= 10;
		base *= 10;
	}

	base += (n - 1) / bit;
	char number[15];
	sprintf(number, "%ld", base);
	return number[(n - 1) % bit] - '0';
}