#include <string.h>

char* breakPalindrome(char* palindrome)
{
	int N = strlen(palindrome);
	for (int i = 0; i < N / 2; ++i)
	{
		if (palindrome[i] != 'a')
		{
			palindrome[i] = 'a';
			return palindrome;
		}
	}
	palindrome[N - 1] = 'b';
	return N < 2 ? "" : palindrome;
}
