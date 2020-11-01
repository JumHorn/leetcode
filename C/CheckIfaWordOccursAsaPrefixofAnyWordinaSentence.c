#include <string.h>

int isPrefixOfWord(char *sentence, char *searchWord)
{
	int res = 1, N = strlen(searchWord);
	for (char *token = strtok(sentence, " "); token; token = strtok(NULL, " "))
	{
		if (strncmp(token, searchWord, N) == 0)
			return res;
		++res;
	}
	return -1;
}