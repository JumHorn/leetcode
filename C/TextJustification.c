#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize)
{
	char **res = (char **)malloc(sizeof(char *) * 100);
	*returnSize = 0;
	char row[maxWidth + 1];
	row[maxWidth] = '\0';
	int N = wordsSize, rowSize = 0;
	int wordsColSize[N];
	for (int i = 0; i < N; ++i)
		wordsColSize[i] = strlen(words[i]);
	for (int i = 0, k, l; i < N; i += k)
	{
		for (rowSize = k = l = 0; i + k < N && l + wordsColSize[i + k] <= maxWidth - k; ++k)
			l += wordsColSize[i + k];
		rowSize += sprintf(&row[rowSize], "%s", words[i]);
		for (int j = 0; j < k - 1; ++j)
		{
			if (i + k >= N) //last row
				row[rowSize++] = ' ';
			else
			{
				memset(&row[rowSize], ' ', sizeof(char) * (maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)));
				rowSize += (maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1));
			}
			rowSize += sprintf(&row[rowSize], "%s", words[i + j + 1]);
		}
		memset(&row[rowSize], ' ', sizeof(char) * (maxWidth - rowSize));
		res[(*returnSize)++] = strdup(row);
	}
	return res;
}