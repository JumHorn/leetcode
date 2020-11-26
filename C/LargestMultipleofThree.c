#include <stdbool.h>
#include <stdlib.h>

static int sum, size, count[10];

bool f(int index)
{
	if (count[index] > 0)
	{
		--count[index];
		--size;
		sum -= index;
	}
	return sum % 3 == 0;
}

char *largestMultipleOfThree(int *digits, int digitsSize)
{
	memset(count, 0, sizeof(count));
	sum = 0;
	size = digitsSize;
	for (int i = 0; i < digitsSize; ++i)
	{
		++count[digits[i]];
		sum += digits[i];
	}

	if (sum % 3 == 1)
	{
		if (!(f(1) || f(4) || f(7)))
			f(2) || f(2) || f(5) || f(5) || f(8) || f(8);
	}
	else if (sum % 3 == 2)
	{
		if (!(f(2) || f(5) || f(8)))
			f(1) || f(1) || f(4) || f(4) || f(7) || f(7);
	}
	if (size == 0)
		return "";
	char *res = (char *)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	for (int i = 9, j = 0; i >= 0; --i)
	{
		while (--count[i] >= 0)
			res[j++] = i + '0';
	}
	if (res[0] == '0')
		res[1] = '\0';
	return res;
}