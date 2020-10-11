#include <stdbool.h>

bool checkStretchy(char* s, char* word)
{
	int j = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (word[j] && s[i] == word[j])
			++j;
		else if ((i <= 1 || s[i] != s[i - 2] || s[i] != s[i - 1]) && (i <= 0 || !s[i + 1] || s[i] != s[i + 1] || s[i] != s[i - 1]))
			return false;
	}
	return !word[j];
}

int expressiveWords(char* S, char** words, int wordsSize)
{
	int res = 0;
	for (int i = 0; i < wordsSize; ++i)
	{
		if (checkStretchy(S, words[i]))
			++res;
	}
	return res;
}
