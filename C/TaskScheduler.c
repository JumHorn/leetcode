#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? 1 : -1;
}

int leastInterval(char *tasks, int tasksSize, int n)
{
	int hash[26] = {0};
	for (int i = 0; i < tasksSize; ++i)
		++hash[tasks[i] - 'A'];
	qsort(hash, 26, sizeof(int), cmp); //des
	int maxCount = hash[0], maxSameCount = 1;
	for (int i = 1; i < 26 && hash[i] == hash[0]; ++i)
		++maxSameCount;
	return max(tasksSize, (maxCount - 1) * (n + 1) + maxSameCount);
}