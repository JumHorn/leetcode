#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
So we need a data structure to store the indexes of picked numbers,
to support fast calculation of the new index of each remaining number.
BIT, Segment Tree and Balanced Binary Search Tree can do this.
we can make use of sortedcontainers
*/

/*
BIT

original string: "1 2 4 0 5 6 7", original k = 3;
use/not state:    1 1 1 0 1 1 1 (1: not been used, 0: used);
prefix sum:       1 2 3 3 4 5 6 real index = prefixsum + used

original string: "1 4 2 5 6 7", k = 2;
use/not state:    0 1 0 1 1 1 (1: not been used, 0: used);
prefix sum:       0 1 1 2 3 4
*/

//Fenwick tree(BIT)
int sum(int *tree, int size, int index)
{
	int res = 0;
	for (; index > 0; index -= index & -index)
		res += tree[index];
	return res;
}

void update(int *tree, int size, int index, int delta)
{
	for (; index < size; index += index & -index)
		tree[index] += delta;
}

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(char *)lhs - *(char *)rhs;
}

char *minInteger(char *num, int k)
{
	int N = strlen(num);
	if (k >= N * (N - 1) / 2)
	{
		qsort(num, N, sizeof(char), cmp);
		return num;
	}
	int N = N + 1, tree[N];
	memset(tree, 0, sizeof(tree));
	for (int i = 0; i < N; ++i)
		update(tree, N, i + 1, 1);
	int count[10][N], countColSize[10] = {0};
	for (int i = N - 1; i >= 0; --i)
	{
		int index = num[i] - '0';
		count[index][countColSize[index]++] = i;
	}
	char *res = (char *)malloc(sizeof(char) * (N + 1));
	res[N] = '\0';
	int seen[N], resSize = 0;
	memset(seen, 0, sizeof(seen));
	bool flag = true;
	for (int c = k; c > 0 && flag;)
	{
		flag = false;
		for (int i = 0; i < 10; ++i)
		{
			if (countColSize[i] != 0)
			{
				flag = true;
				int index = count[i][countColSize[i] - 1];
				int move = sum(tree, N, index + 1) - 1;
				if (c < move)
					continue;
				seen[index] = 1;
				res[resSize++] = i + '0';
				c -= move;
				update(tree, N, index + 1, -1);
				--countColSize[i];
				break;
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (seen[i] == 0)
			res[resSize++] = num[i];
	}
	return res;
}