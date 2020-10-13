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

void reverse(char *s, int size)
{
	int i = 0, j = size - 1;
	while (i < j)
	{
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		++i;
		--j;
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
		reverse(last, halfsize - odd);
		sprintf(s, "%s%s", half, last);
		int res = atoi(s);
		if (res >= N && isPrimer(res))
			return res;
		++num;
	}
	return 0;
}