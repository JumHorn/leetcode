#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
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