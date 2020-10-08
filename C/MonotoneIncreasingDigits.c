#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int monotoneIncreasingDigits(int N)
{
	char digits[10];
	sprintf(digits, "%d", N);
	int i = 1;
	while (digits[i] && digits[i] >= digits[i - 1])
		++i;
	if (!digits[i])
		return N;
	int j = i - 2;
	while (j >= 0 && digits[j] == digits[i - 1])
		--j;
	++j;
	digits[j] -= 1;
	while (digits[++j])
		digits[j] = '9';
	return atoi(digits);
}
