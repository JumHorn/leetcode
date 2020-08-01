#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(long long x)
{
	char str[20] = {0};
	sprintf(str, "%lld", x);
	int i = 0, j = strlen(str) - 1;
	while (i < j)
	{
		if (str[i++] != str[j--])
			return false;
	}
	return true;
}

void reverse(char *str, char *out, int size)
{
	for (int i = 0, j = size - 1; i <= j; ++i, --j)
	{
		out[i] = str[j];
		out[j] = str[i];
	}
}

int superpalindromesInRange(char *L, char *R)
{
	long long l = atoll(L), r = atoll(R);
	int res = 0, magic = 1e5;

	for (long long i = 1; i < magic; i++)
	{
		char str[40] = {0}, reverse_str[20] = {0};
		sprintf(str, "%lld", i);
		reverse(str, reverse_str, strlen(str));
		strcat(str, reverse_str);
		long long val = atoll(str);
		val *= val;
		if (val > r)
			break;
		if (val >= l && isPalindrome(val))
			++res;
	}
	for (long long i = 1; i < magic; i++)
	{
		char str[40] = {0}, reverse_str[20] = {0};
		sprintf(str, "%lld", i);
		reverse(str, reverse_str, strlen(str) - 1);
		strcat(str, reverse_str);
		long long val = atoll(str);
		val *= val;
		if (val > r)
			break;
		if (val >= l && isPalindrome(val))
			++res;
	}
	return res;
}