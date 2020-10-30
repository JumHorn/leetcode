#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPrimer(int N)
{
	if (N == 1)
		return false;
	for (int i = 2; i * i <= N; ++i)
	{
		if (N % i == 0)
			return false;
	}
	return true;
}

void reverse(char *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

int primePalindrome(int N)
{
	char s[10];
	sprintf(s, "%d", N);
	int len = strlen(s);
	char half[10];
	strncpy(half, s, (len + 1) / 2);
	half[(len + 1) / 2] = '\0';
	int odd = len % 2, num = atoi(half);
	len = strlen(half);
	while (true)
	{
		sprintf(half, "%d", num);
		int halfsize = strlen(half);
		if (len != halfsize)
		{
			halfsize = len = halfsize - odd;
			half[halfsize] = '\0';
			odd = 1 - odd;
		}
		char last[10];
		strncpy(last, half, halfsize - odd);
		last[halfsize - odd] = '\0';
		reverse(last, 0, halfsize - odd - 1);
		sprintf(s, "%s%s", half, last);
		int res = atoi(s);
		if (res >= N && isPrimer(res))
			return res;
		++num;
	}
	return 0;
}