#include <stdbool.h>

bool canConstruct(char *ransomNote, char *magazine)
{
	int count[26] = {0};
	for (int i = 0; magazine[i]; ++i)
		++count[magazine[i] - 'a'];
	for (int i = 0; ransomNote[i]; ++i)
	{
		if (--count[ransomNote[i] - 'a'] < 0)
			return false;
	}
	return true;
}