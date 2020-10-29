#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return strcmp(*(char **)lhs, *(char **)rhs);
}

bool existInBanned(char **banned, int bannedSize, char *val)
{
	if (bannedSize == 0)
		return false;
	int lo = 0, hi = bannedSize - 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (strcmp(banned[mi], val) < 0)
			lo = mi + 1;
		else
			hi = mi;
	}
	return strcmp(banned[lo], val) == 0;
}

char *mostCommonWord(char *paragraph, char **banned, int bannedSize)
{
	qsort(banned, bannedSize, sizeof(char *), cmp);
	for (int i = 0; paragraph[i]; ++i) //make punctuation to ' '
	{
		if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
			paragraph[i] = paragraph[i] - 'A' + 'a';
		if (paragraph[i] < 'a' || paragraph[i] > 'z')
			paragraph[i] = ' ';
	}
	char *arr[1000], *res = NULL;
	int arrSize = 0, freq = 0;
	for (char *token = strtok(paragraph, " "); token; token = strtok(NULL, " "))
		arr[arrSize++] = token;
	qsort(arr, arrSize, sizeof(char *), cmp);
	for (int i = 1, j = 0; i <= arrSize; ++i)
	{
		if (i == arrSize || strcmp(arr[i], arr[j]) != 0)
		{
			if (i - j > freq && !existInBanned(banned, bannedSize, arr[j]))
			{
				freq = i - j;
				res = arr[j];
			}
			j = i;
		}
	}
	return res;
}