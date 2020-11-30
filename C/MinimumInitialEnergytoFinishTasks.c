#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	int *l = *(int **)lhs, *r = *(int **)rhs;
	return (l[0] + r[1]) - (l[1] + r[0]);
}

int minimumEffort(int **tasks, int tasksSize, int *tasksColSize)
{
	int N = tasksSize;
	qsort(tasks, N, sizeof(int *), cmp);
	int res = 0, cur = 0;
	for (int i = 0; i < N; ++i)
	{
		if (cur < tasks[i][1])
		{
			res += tasks[i][1] - cur;
			cur += tasks[i][1] - cur;
		}
		cur -= tasks[i][0];
	}
	return res;
}