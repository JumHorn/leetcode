#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * *********************************************************************
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int guess(Master *, char *word);
 */

typedef struct Master Master;

int guess(Master *, char *word);

void swap(char **lhs, char **rhs)
{
	char *tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

int strdiff(char *lhs, char *rhs)
{
	int res = 0;
	for (int i = 0; lhs[i]; ++i)
	{
		if (lhs[i] == rhs[i])
			++res;
	}
	return res;
}

void findSecretWord(char **wordlist, int wordlistSize, Master *master)
{
	srand(time(NULL));
	char *possible[wordlistSize];
	for (int i = 0; i < wordlistSize; ++i)
		possible[i] = wordlist[i];
	int diff = guess(master, *possible), N = strlen(*possible);
	for (; diff < N; diff = guess(master, *possible))
	{
		char guessed[10];
		strcpy(guessed, *possible);
		int size = 0;
		for (int i = 1; i < wordlistSize; ++i)
		{
			if (strdiff(guessed, possible[i]) == diff)
				possible[size++] = possible[i];
		}
		wordlistSize = size;
		int index = rand() % size;
		swap(&possible[0], &possible[index]); //random guess
	}
}