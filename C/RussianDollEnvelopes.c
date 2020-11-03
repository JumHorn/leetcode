#include <stdlib.h>

//cmp function
int cmp(const void *lhs, const void *rhs)
{
	if ((*(int **)lhs)[0] != (*(int **)rhs)[0])
		return (*(int **)lhs)[0] - (*(int **)rhs)[0];
	return (*(int **)rhs)[1] - (*(int **)lhs)[1];
}

int maxEnvelopes(int **envelopes, int envelopesSize, int *envelopesColSize)
{
	qsort(envelopes, envelopesSize, sizeof(int *), cmp);
	int size = 0;
	for (int i = 0; i < envelopesSize; ++i)
	{
		int lo = 0, hi = size;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (envelopes[mi][1] < envelopes[i][1])
				lo = mi + 1;
			else
				hi = mi;
		}
		envelopes[lo][1] = envelopes[i][1];
		if (lo == size)
			++size;
	}
	return size;
}
