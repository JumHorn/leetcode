#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// next permutation

#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

void reverse(char *arr, int first, int last)
{
	for (; first < last; ++first, --last)
		swap(arr[first], arr[last]);
}

int nextGreaterElement(int n)
{
	char s[15];
	sprintf(s, "%d", n);
	int N = strlen(s);
	for (int i = N - 1; i > 0; --i)
	{
		if (s[i] > s[i - 1])
		{
			int j = N - 1;
			while (s[j] <= s[i - 1])
				--j;
			swap(s[i - 1], s[j]);
			reverse(s, i, N - 1);
			long res = atol(s);
			return res < INT_MAX ? res : -1;
		}
	}
	return -1;
}