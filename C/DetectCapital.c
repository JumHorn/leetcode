#include <ctype.h>
#include <stdbool.h>

bool all_of(char* word, int (*predicate)(int))
{
	while (*word)
	{
		if (!predicate(*word))
			return false;
		++word;
	}
	return true;
}

bool detectCapitalUse(char* word)
{
	return all_of(word, isupper) || all_of(word, islower) || (isupper(*word) && all_of(word + 1, islower));
}
