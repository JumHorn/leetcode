#include <stdbool.h>
#include <string.h>

/*
strictly O(N) solution
Algorithm:
two pointers
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestSubstringWithUniqueChars(char *s, int unique, int k)
{
	int hash[26] = {0}, noLessThanK = 0, res = 0, differentChar = 0;
	for (int i = 0, j = 0; s[j];) //range[i,j] with unique no less than k
	{
		if (differentChar <= unique)
		{
			int index = s[j++] - 'a';
			if (hash[index] == 0)
				++differentChar;
			if (++hash[index] == k)
				++noLessThanK;
		}
		else
		{
			int index = s[i++] - 'a';
			if (hash[index] == k)
				--noLessThanK;
			if (--hash[index] == 0)
				--differentChar;
		}

		if (differentChar == unique && noLessThanK == unique)
			res = max(res, j - i);
	}
	return res;
}

int longestSubstring(char *s, int k)
{
	int res = 0;
	for (int unique = 1; unique <= 26; ++unique)
	{
		int n = longestSubstringWithUniqueChars(s, unique, k);
		res = max(res, n);
	}
	return res;
}