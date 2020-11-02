#include <stdlib.h>

/*
       start ---------- n
1 --------------------- n
1 --------------------- n
1 --------------- end

            start ----- n
1 --------------------- n
1 --------------------- n
1 ----- end

we only care about start end
1. start < end return [start,end]
2. start > end return [1,end] and  [start,n]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* mostVisited(int n, int* rounds, int roundsSize, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * n);
	*returnSize = 0;
	for (int i = rounds[0]; i <= rounds[roundsSize - 1]; ++i)
		res[(*returnSize)++] = i;
	if (*returnSize != 0)
		return res;
	for (int i = 1; i <= rounds[roundsSize - 1]; ++i)
		res[(*returnSize)++] = i;
	for (int i = rounds[0]; i <= n; ++i)
		res[(*returnSize)++] = i;
	return res;
}
