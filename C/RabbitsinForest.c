#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int numRabbits(int *answers, int answersSize)
{
	qsort(answers, answersSize, sizeof(int), cmp);
	int res = 0, colorcount = 0;
	for (int i = 0; i < answersSize;)
	{
		colorcount = answers[i] + 1;
		int j = i + 1;
		while (j < answersSize && j - i < colorcount && answers[i] == answers[j])
			++j;
		i = j;
		res += colorcount;
	}
	return res;
}