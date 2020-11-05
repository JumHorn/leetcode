#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		if (s[first] != s[last])
			return false;
	}
	return true;
}

bool check(char *a, char *b)
{
	int i = 0, j = strlen(a) - 1;
	for (; i < j; ++i, --j)
	{
		if (a[i] != b[j])
			break;
	}
	return isPalindrome(b, i, j) || isPalindrome(a, i, j);
}

bool checkPalindromeFormation(char *a, char *b)
{
	return check(a, b) || check(b, a);
}
