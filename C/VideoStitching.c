#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int *l = *(int **)lhs, *r = *(int **)rhs;
	if (l[0] != r[0])
		return l[0] - r[0];
	return r[1] - l[1];
}

int videoStitching(int **clips, int clipsSize, int *clipsColSize, int T)
{
	qsort(clips, clipsSize, sizeof(int *), cmp);
	if (clips[0][0] > 0)
		return -1;
	int maxend = clips[0][1], end = maxend, res = 1;
	for (int i = 1; i < clipsSize && end < T; ++i)
	{
		if (clips[i][0] > end)
		{
			if (clips[i][0] > maxend)
				return -1;
			end = maxend;
			++res;
		}
		maxend = max(maxend, clips[i][1]);
	}
	if (end >= T)
		return res;
	return maxend >= T ? res + 1 : -1;
}