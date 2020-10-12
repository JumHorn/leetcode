#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

void swap(int *lhs, int *rhs)
{
	int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

int maxProfitAssignment(int *difficulty, int difficultySize, int *profit, int profitSize, int *worker, int workerSize)
{
	qsort(worker, workerSize, sizeof(int), cmp);
	//sort by difficulty
	for (int i = 0; i < difficultySize; ++i)
	{
		for (int j = difficultySize - 1; j > i; --j)
		{
			if (difficulty[j - 1] > difficulty[j])
			{
				swap(&difficulty[j - 1], &difficulty[j]);
				swap(&profit[j - 1], &profit[j]);
			}
		}
	}

	int res = 0, d = 0, p = 0;
	for (int i = 0; i < workerSize; ++i)
	{
		while (d < difficultySize && worker[i] >= difficulty[d])
		{
			p = max(p, profit[d]);
			++d;
		}
		res += p;
	}
	return res;
}
