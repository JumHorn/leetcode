#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

void normaliseWord(char *word, char *encode) //encode the odd/even indexed element
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