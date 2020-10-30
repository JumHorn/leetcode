#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return strcmp((char *)lhs, (char *)rhs);
}

void normaliseWord(char *word, char *encode)  //encode the odd/even indexed element
{
	for (int i = 0; word[i]; ++i)
		++encode[word[i] - 'a' + 26 * (i & 1)];
}

int numSpecialEquivGroups(char **A, int ASize)
{
	char arr[ASize][53];
	memset(arr, 'a', sizeof(arr));
	for (int i = 0; i < ASize; ++i)
	{
		normaliseWord(A[i], arr[i]);
		arr[i][52] = '\0';
	}
	qsort(arr, ASize, sizeof(arr[0]), cmp);
	int res = 0;
	for (int i = 1, j = 0; i <= ASize; ++i)
	{
		if (i == ASize || strcmp(arr[i], arr[j]) != 0)
		{
			++res;
			j = i;
		}
	}
	return res;
}
