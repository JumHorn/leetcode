#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long makePalindrome(long half, int even)
{
	long left = half, right = 0;
	if (even != 0)
		half /= 10;
	for (; half > 0; half /= 10)
	{
		left *= 10;
		right = right * 10 + half % 10;
	}
	return left + right;
}

char *nearestPalindromic(char *n)
{
	long num = atoll(n);
	int N = strlen(n);
	n[N / 2 + N % 2] = '\0';
	long half = atoll(n);
	long res0 = makePalindrome(half, N % 2);
	long abs0 = abs(num - res0);
	if (abs0 == 0)
		abs0 = LONG_MAX;

	long res1;
	if (half != pow(10, N / 2 + N % 2) - 1)
		res1 = makePalindrome(half + 1, N % 2);
	else
		res1 = pow(10, N) + 1;
	long abs1 = abs(num - res1);

	long res2;
	if (half != pow(10, N / 2 + N % 2 - 1))
		res2 = makePalindrome(half - 1, N % 2);
	else
		res2 = pow(10, N - 1) - 1;
	long abs2 = abs(num - res2);

	char *res = (char *)malloc(sizeof(char) * 20);
	if (abs2 <= abs0 && abs2 <= abs1)
		sprintf(res, "%ld", res2);
	else if (abs0 <= abs1 && abs0 < abs2)
		sprintf(res, "%ld", res0);
	else
		sprintf(res, "%ld", res1);
	return res;
}