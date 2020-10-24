#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return strcmp(*(char **)lhs, *(char **)rhs);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***suggestedProducts(char **products, int productsSize, char *searchWord, int *returnSize, int **returnColumnSizes)
{
	int N = strlen(searchWord);
	qsort(products, productsSize, sizeof(char *), cmp);

	*returnSize = N;
	char ***res = (char ***)malloc(sizeof(char **) * (*returnSize));
	memset(res, 0, sizeof(char **) * (*returnSize));
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memset(*returnColumnSizes, 0, sizeof(int) * (*returnSize));

	int lo = 0, hi = productsSize;
	for (int i = 0; i < N; ++i)
	{
		hi = productsSize;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (strncmp(products[mi], searchWord, i + 1) < 0)
				lo = mi + 1;
			else
				hi = mi;
		}
		for (hi = lo; hi - lo < 3 && hi < productsSize; ++hi)
		{
			if (strncmp(products[hi], searchWord, i + 1) != 0)
				break;
		}
		(*returnColumnSizes)[i] = hi - lo;
		res[i] = (char **)malloc(sizeof(char *) * (*returnColumnSizes)[i]);
		for (int j = 0; j < hi - lo; ++j)
		{
			int len = strlen(products[j + lo]);
			res[i][j] = (char *)malloc(sizeof(char) * (len + 1));
			strcpy(res[i][j], products[j + lo]);
		}
	}
	return res;
}