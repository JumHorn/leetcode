#include <stdlib.h>
#include <string.h>

/*
sa[i] the ith rank's index
rank[i] the ith index's rank

1. sa[rank[i]]=i
2 .rank[sa[i]]=i

3. lcp[i] >= lcp[i-1]-1 need to prove
*/

typedef struct
{
	int index;
	int currank;
	int nextrank;
} SuffixArray;

int cmp(const void *lhs, const void *rhs)
{
	SuffixArray *l = (SuffixArray *)lhs;
	SuffixArray *r = (SuffixArray *)rhs;
	if (l->currank != r->currank)
		return l->currank - r->currank;
	return l->nextrank - r->nextrank;
}

char *lastSubstring(char *s)
{
	int N = strlen(s);
	SuffixArray sa[N];
	//init
	for (int i = 0; i < N - 1; ++i)
	{
		sa[i].index = i;
		sa[i].currank = s[i] - 'a';
		sa[i].nextrank = s[i + 1] - 'a';
	}
	sa[N - 1].index = N - 1;
	sa[N - 1].currank = s[N - 1] - 'a';
	sa[N - 1].nextrank = -1;
	qsort(sa, N, sizeof(SuffixArray), cmp);

	int rank[N];
	for (int k = 4; k < 2 * N; k *= 2)
	{
		int rank_count = 0;
		int pre_rank = sa[0].currank;
		sa[0].currank = rank_count;
		rank[sa[0].index] = 0;
		//update rank
		for (int i = 1; i < N; ++i)
		{
			if (sa[i].currank == pre_rank && sa[i].nextrank == sa[i - 1].nextrank)
				sa[i].currank = rank_count;
			else
			{
				pre_rank = sa[i].currank;
				sa[i].currank = ++rank_count;
			}
			rank[sa[i].index] = i;
		}
		for (int i = 0; i < N; ++i)
		{
			int nextindex = sa[i].index + k / 2;
			sa[i].nextrank = (nextindex < N) ? sa[rank[nextindex]].currank : -1;
		}
		qsort(sa, N, sizeof(SuffixArray), cmp);
	}
	return &s[sa[N - 1].index];
}