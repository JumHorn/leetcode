#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int maxProfitAssignment(int *difficulty, int difficultySize, int *profit, int profitSize, int *worker, int workerSize)
{
	qsort(worker, workerSize, sizeof(int), cmp);
	//sort by difficulty
	int job[profitSize][2];
	for (int i = 0; i < difficultySize; ++i)
	{
		job[i][0] = difficulty[i];
		job[i][1] = profit[i];
	}
	qsort(job, profitSize, sizeof(job[0]), cmp);

	int res = 0, d = 0, p = 0;
	for (int i = 0; i < workerSize; ++i)
	{
		while (d < difficultySize && worker[i] >= job[d][0])
		{
			p = max(p, job[d][1]);
			++d;
		}
		res += p;
	}
	return res;
}