#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int smallestFrequency(char *str)
{
	int freq = 0;
	char smallest = 'z';
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] < smallest)
		{
			smallest = str[i];
			freq = 1;
		}
		else if (str[i] == smallest)
			++freq;
	}
	return freq;
}

int upper_bound(int *freq, int freqSize, int val)
{
	int lo = 0, hi = freqSize;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (freq[mi] <= val)
			lo = mi + 1;
		else
			hi = mi;
	}
	return freqSize - lo;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *numSmallerByFrequency(char **queries, int queriesSize, char **words, int wordsSize, int *returnSize)
{
	*returnSize = queriesSize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int freq[wordsSize];
	for (int i = 0; i < wordsSize; ++i)
		freq[i] = smallestFrequency(words[i]);
	qsort(freq, wordsSize, sizeof(int), cmp);
	for (int i = 0; i < queriesSize; ++i)
		res[i] = upper_bound(freq, wordsSize, smallestFrequency(queries[i]));
	return res;
}