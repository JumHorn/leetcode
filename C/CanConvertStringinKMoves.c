#include <stdbool.h>
#include <string.h>

bool canConvertString(char* s, char* t, int k)
{
	if (strlen(s) != strlen(t))
		return false;
	int base = k / 26, r = k % 26;
	int moves[26];
	for (int i = 0; i < 26; ++i)
		moves[i] = base;
	for (int i = 0; i < r; ++i)
		++moves[i];
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] != t[i])
		{
			int steps = (t[i] - s[i] + 26) % 26 - 1;
			if (--moves[steps] < 0)
				return false;
		}
	}
	return true;
}
