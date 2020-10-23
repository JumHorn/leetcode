#include <stdbool.h>

bool isIsomorphic(char* s, char* t)
{
	int hash[128] = {0}, seen[128] = {0};  //already matched
	for (int i = 0; s[i]; ++i)
	{
		if (hash[s[i]] == 0 && seen[t[i]] == 0)
		{
			hash[s[i]] = t[i];
			seen[t[i]] = 1;
		}
		if (hash[s[i]] != t[i])
			return false;
	}
	return true;
}
