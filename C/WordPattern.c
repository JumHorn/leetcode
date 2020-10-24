#include <stdbool.h>
#include <string.h>

bool wordPattern(char* pattern, char* s)
{
	char *hash[26] = {0}, *token;
	for (token = strtok(s, " "); token && *pattern; token = strtok(NULL, " "))
	{
		if (hash[*pattern - 'a'] == NULL)
		{
			for (int i = 0; i < 26; ++i)  //check this token not mapped
			{
				if (hash[i] != NULL && strcmp(hash[i], token) == 0)
					return false;
			}
			hash[*pattern - 'a'] = token;
		}
		else
		{
			if (strcmp(hash[*pattern - 'a'], token) != 0)
				return false;
		}
		++pattern;
	}
	return !*pattern && token == NULL;
}
