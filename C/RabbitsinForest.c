#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
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
