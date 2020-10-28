#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s, int first, int last, int d)
{
	while (first < last && s[first] == s[last])
	{
		++first;
		--last;
	}
	return first >= last ||
		   (d == 1 && isPalindrome(s, first + 1, last, 0)) ||
		   (d == 1 && isPalindrome(s, first, last - 1, 0));
}

bool validPalindrome(char* s)
{
	return isPalindrome(s, 0, strlen(s) - 1, 1);
}
