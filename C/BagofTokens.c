#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int bagOfTokensScore(int *tokens, int tokensSize, int P)
{
	int res = 0, i = 0, j = tokensSize - 1, score = 0;
	qsort(tokens, tokensSize, sizeof(int), cmp);
	while (i <= j)
	{
		if (P - tokens[i] >= 0)
		{
			P -= tokens[i++];
			++score;
			res = max(res, score);
		}
		else
		{
			if (score <= 0)
				break;
			--score;
			P += tokens[j--];
		}
	}
	return res;
}