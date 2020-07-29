#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(char *)lhs - *(char *)rhs;
}

bool cmpstr(char *S, int size, int start0, int start1)
{
	for (int i = 0; i < size; ++i)
	{
		if (S[(start1 + i) % size] != S[(start0 + i) % size])
			return S[(start1 + i) % size] < S[(start0 + i) % size];
	}
	return false;
}

char *orderlyQueue(char *S, int K)
{
	int N = strlen(S);
	if (K > 1)
	{
		qsort(S, N, sizeof(char), cmp);
		return S;
	}
	int res = 0;
	for (int i = 1; i < N; ++i)
	{
		if (cmpstr(S, N, res, i))
			res = i;
	}
	char dup[N];
	memcpy(dup, &S[res], (N - res) * sizeof(char));
	memcpy(&dup[N - res], S, res * sizeof(char));
	memcpy(S, dup, N * sizeof(char));
	return S;
}