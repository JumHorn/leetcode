#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* lhs, char* rhs)
{
	char tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

void reverse(char* s, int first, int last)
{
	while (first < last)
	{
		swap(&s[first], &s[last]);
		++first;
		--last;
	}
}

int nextGreaterElement(int n)
{
	char s[15];
	sprintf(s, "%d", n);
	int N = strlen(s);
	int i = N;
	while (--i > 0)
	{
		if (s[i] > s[i - 1])
		{
			int j = N - 1;
			while (s[j] <= s[i - 1])
				--j;
			swap(&s[i - 1], &s[j]);
			reverse(s, i, N - 1);
			long res = atol(s);
			return res < INT_MAX ? res : -1;
		}
	}
	return -1;
}
