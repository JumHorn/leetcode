#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//malloc result
char **mallocRes(char (*data)[20], int dataSize, int *returnSize)
{
	*returnSize = dataSize;
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		int n = strlen(data[i]);
		res[i] = (char *)malloc(sizeof(char) * (n + 1));
		strcpy(res[i], data[i]);
	}
	return res;
}

void dfs(char *S, int SSize, int first, int last, int count, char (*staticRes)[20], int *size)
{
	if (first >= last)
		return;
	if (S[first] != '0' || last - first == 1) //decimal
	{
		char a[15];
		snprintf(a, last - first + 1, "%s", &S[first]); //at most i-first chars with null
		if (count == 0)
		{
			sprintf(staticRes[*size], "(%s", a);
			dfs(S, SSize, last, SSize, count + 1, staticRes, size);
		}
		else
		{
			strcpy(staticRes[*size + 1], staticRes[*size]);
			int len = strlen(staticRes[*size]);
			sprintf(&staticRes[*size][len], ", %s)", a);
			++*size;
		}
	}
	for (int i = first + 1; i < last; ++i) //point
	{
		if (S[first] == '0' && i - first >= 2) //zero prefix
			break;
		if (S[last - 1] != '0')
		{
			char a[15], b[15];
			snprintf(a, i - first + 1, "%s", &S[first]); //at most i-first chars with null
			snprintf(b, last - i + 1, "%s", &S[i]);
			if (count == 0)
			{
				sprintf(staticRes[*size], "(%s.%s", a, b);
				dfs(S, SSize, last, SSize, count + 1, staticRes, size);
			}
			else
			{
				strcpy(staticRes[*size + 1], staticRes[*size]);
				int len = strlen(staticRes[*size]);
				sprintf(&staticRes[*size][len], ", %s.%s)", a, b);
				++*size;
			}
		}
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **ambiguousCoordinates(char *S, int *returnSize)
{
	static char staticRes[5000][20];
	*returnSize = 0;
	int size = strlen(S);
	for (int i = 0; i < size; ++i)
		dfs(&S[1], size - 2, 0, i + 1, 0, staticRes, returnSize);
	return mallocRes(staticRes, *returnSize, returnSize);
}