#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)rhs - *(int *)lhs;
}

int leastInterval(char *tasks, int tasksSize, int n)
{
	int hash[26] = {0};
	for (int i = 0; i < tasksSize; ++i)
		++hash[tasks[i] - 'A'];
	qsort(hash, 26, sizeof(int), cmp);
	int res = 0, minTask, i;
	while (hash[0] > 0)
	{
		minTask = hash[0];
		for (i = 0; i < min(n + 1, 26) && hash[i] > 0; ++i)
			minTask = min(minTask, hash[i]);
		if (i < 26 && hash[i] != 0)
			minTask = minTask - hash[i] + 1;
		for (i = 0; i < min(n + 1, 26) && hash[i] > 0; ++i)
			hash[i] -= minTask;
		res += (n + 1) * minTask;
		qsort(hash, 26, sizeof(int), cmp);
	}
	res -= n + 1 - i;
	return res;
}
